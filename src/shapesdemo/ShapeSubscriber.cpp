// Copyright 2021 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// This file is part of eProsima Fast DDS Shapes Demo.
//
// eProsima Fast DDS Shapes Demo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// eProsima Fast DDS Shapes Demo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with eProsima Fast DDS Shapes Demo. If not, see <https://www.gnu.org/licenses/>.

/**
 * @file ShapeSubscriber.cpp
 *
 */

#include <fastdds/dds/builtin/topic/PublicationBuiltinTopicData.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>
#include <fastdds/rtps/common/InstanceHandle.hpp>

#include <eprosimashapesdemo/qt/ContentFilterSelector.h>
#include <eprosimashapesdemo/qt/mainwindow.h>
#include <eprosimashapesdemo/shapesdemo/ShapeSubscriber.h>

ShapeSubscriber::ShapeSubscriber(
        MainWindow* win,
        ShapesDemo* sd,
        Topic* topic)
    : mp_sd(sd)
    , mp_datareader(nullptr)
    , mp_subscriber(nullptr)
    , mp_topic(topic)
    , listener_(this)
    , hasReceived(false)
    , m_mutex(QMutex::Recursive)
    , mp_contentFilter(nullptr)
    , m_mainWindow(win)
{
    // TODO Auto-generated constructor stub
}

ShapeSubscriber::~ShapeSubscriber()
{
    if (mp_sd->getParticipant() && mp_subscriber && mp_datareader)
    {
        if (RETCODE_OK != mp_subscriber->delete_datareader(mp_datareader))
        {
            std::cerr << "Error deleting datareader: " << mp_datareader->guid() << std::endl;
            return;
        }
    }

    if (mp_sd->getParticipant() && mp_filtered_topic)
    {
        if (RETCODE_OK != mp_sd->getParticipant()->delete_contentfilteredtopic(mp_filtered_topic))
        {
            std::cerr << "Error deleting filtered topic" << std::endl;
            // NOTE: don't return since we want to try and remove the subscriber
        }
    }

    if (mp_sd->getParticipant() && mp_subscriber)
    {
        if (RETCODE_OK != mp_sd->getParticipant()->delete_subscriber(mp_subscriber))
        {
            std::cerr << "Error deleting subscriber: " << std::endl;
            return;
        }
    }

    if (mp_contentFilter != nullptr)
    {
        delete(mp_contentFilter);
    }
}

bool ShapeSubscriber::initSubscriber()
{
    mp_subscriber = mp_sd->getParticipant()->create_subscriber(m_sub_qos);

    eprosima::fastdds::dds::TopicDescription* topic = mp_topic;

    if (m_shapeHistory.m_filter.m_useContentFilter)
    {
        static uint64_t filter_index = 0;
        std::vector<std::string> parameters;
        parameters.emplace_back(std::to_string(m_shapeHistory.m_filter.m_minX));
        parameters.emplace_back(std::to_string(m_shapeHistory.m_filter.m_maxX));
        parameters.emplace_back(std::to_string(m_shapeHistory.m_filter.m_minY));
        parameters.emplace_back(std::to_string(m_shapeHistory.m_filter.m_maxY));
        mp_filtered_topic = mp_sd->getParticipant()->create_contentfilteredtopic(
            std::to_string(filter_index++), mp_topic,
            "x > %0 AND x < %1 AND y > %2 AND y < %3", parameters);
        if (nullptr != mp_filtered_topic)
        {
            topic = mp_filtered_topic;
        }
        else
        {
            m_mainWindow->addMessageToOutput(QString(
                        "Error creating content filtered topic. Using application filtering."));
        }
    }

    mp_datareader = mp_subscriber->create_datareader(topic, m_dr_qos, &listener_);

    return nullptr != mp_datareader;
}

void ShapeSubscriber::SubListener::on_data_available(
        DataReader* reader)
{
    Shape shape;
    shape.m_type = parent_->m_shapeType;
    eprosima::fastdds::dds::SampleInfo info;

    while (reader->take_next_sample(&shape.m_shape, &info) == RETCODE_OK)
    {
        shape.m_time = info.source_timestamp.to_duration_t();

        QMutexLocker locck(&parent_->m_mutex);
        if (info.instance_state == ALIVE_INSTANCE_STATE)
        {
            parent_->hasReceived = true;
            parent_->m_shapeHistory.addToHistory(shape);
        }
        else
        {
            SD_COLOR color = getColorFromInstanceHandle(info.instance_handle);
            if (info.instance_state == NOT_ALIVE_DISPOSED_INSTANCE_STATE)
            {
                parent_->m_shapeHistory.dispose(color);
            }
            else
            {
                parent_->m_shapeHistory.unregister(color);
            }
        }
    }
}

void ShapeSubscriber::adjustContentFilter(
        ShapeFilter& filter)
{
    m_mutex.lock();
    m_shapeHistory.adjustContentFilter(filter);
    if (nullptr != mp_filtered_topic)
    {
        std::vector<std::string> parameters;
        parameters.emplace_back(std::to_string(filter.m_minX));
        parameters.emplace_back(std::to_string(filter.m_maxX));
        parameters.emplace_back(std::to_string(filter.m_minY));
        parameters.emplace_back(std::to_string(filter.m_maxY));
        mp_filtered_topic->set_expression_parameters(parameters);
    }
    m_mutex.unlock();
}

void ShapeSubscriber::SubListener::on_requested_deadline_missed(
        DataReader* reader,
        const RequestedDeadlineMissedStatus& status)
{
    if (0 < status.total_count_change)
    {
        std::stringstream str;
        str << "DataReader " << reader->guid() << " detects deadline missed";
        parent_->m_mainWindow->addMessageToOutput(QString(str.str().c_str()));
    }
}

void ShapeSubscriber::SubListener::on_liveliness_changed(
        DataReader* reader,
        const LivelinessChangedStatus& status)
{
    std::stringstream str;
    if (0 < status.alive_count_change)
    {
        str << "DataReader " << reader->guid() << " detects liveliness recovered";
        parent_->m_mainWindow->addMessageToOutput(QString(str.str().c_str()));
    }
    if (0 < status.not_alive_count_change)
    {
        str << "DataReader " << reader->guid() << " detects liveliness lost";
        parent_->m_mainWindow->addMessageToOutput(QString(str.str().c_str()));
    }
}

void ShapeSubscriber::SubListener::on_requested_incompatible_qos(
        DataReader* reader,
        const RequestedIncompatibleQosStatus& status)
{
    if (0 < status.total_count_change)
    {
        std::stringstream str;
        str << "DataReader " << reader->guid() << " detects incompatible QoS " << qos_policy_id_to_string(
            status.last_policy_id);
        parent_->m_mainWindow->addMessageToOutput(QString(str.str().c_str()));
    }
}
