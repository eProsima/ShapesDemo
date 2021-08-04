// Copyright 2017 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file ShapeSubscriber.cpp
 *
 */

#include <fastdds/dds/builtin/topic/PublicationBuiltinTopicData.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>
#include <fastdds/rtps/common/InstanceHandle.h>
#include <fastrtps/utils/TimeConversion.h>

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
        if (ReturnCode_t::RETCODE_OK != mp_subscriber->delete_datareader(mp_datareader))
        {
            std::cerr << "Error deleting datareader: " << mp_datareader->guid() << std::endl;
            return;
        }
    }

    if (mp_sd->getParticipant() && mp_subscriber)
    {
        if (ReturnCode_t::RETCODE_OK != mp_sd->getParticipant()->delete_subscriber(mp_subscriber))
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

    mp_datareader = mp_subscriber->create_datareader(mp_topic, m_dr_qos, &listener_);

    return nullptr != mp_datareader;
}

void ShapeSubscriber::SubListener::on_data_available(
        DataReader* reader)
{
    Shape shape;
    shape.m_type = parent_->m_shapeType;
    eprosima::fastdds::dds::SampleInfo info;

    while (reader->take_next_sample(&shape.m_shape, &info) == ReturnCode_t::RETCODE_OK)
    {
        shape.m_time = info.source_timestamp.to_duration_t();
        shape.m_writerGuid = info.sample_identity.writer_guid();

        shape.m_strength = parent_->mp_sd->writer_strength(
            eprosima::fastrtps::rtps::iHandle2GUID(info.publication_handle));

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

void ShapeSubscriber::SubListener::on_subscription_matched(
        DataReader* reader,
        const eprosima::fastdds::dds::SubscriptionMatchedStatus& info)
{
    static_cast<void>(reader);
    if (info.current_count_change > 1)
    {
        bool found = false;
        for (std::vector<rtps::GUID_t>::iterator it = parent_->m_remoteWriters.begin();
                it != parent_->m_remoteWriters.end(); ++it)
        {
            if (*it == iHandle2GUID(info.last_publication_handle))
            {
                found = true;

                // Get ownership (to fake not implemented feature)
                eprosima::fastdds::dds::builtin::PublicationBuiltinTopicData writer_data;

                reader->get_matched_publication_data(
                    writer_data,
                    eprosima::fastrtps::rtps::iHandle2GUID(info.last_publication_handle));

                break;
            }
        }
        if (!found)
        {
            parent_->m_remoteWriters.push_back(iHandle2GUID(info.last_publication_handle));
        }
    }
    else
    {
        parent_->m_mutex.lock();
        parent_->m_shapeHistory.removedOwner(iHandle2GUID(info.last_publication_handle));
        parent_->m_mutex.unlock();
    }
}

void ShapeSubscriber::adjustContentFilter(
        ShapeFilter& filter)
{
    m_mutex.lock();
    m_shapeHistory.adjustContentFilter(filter);
    m_mutex.unlock();
}

void ShapeSubscriber::SubListener::on_requested_deadline_missed(
        DataReader* reader,
        const eprosima::fastrtps::RequestedDeadlineMissedStatus& status)
{
    static_cast<void>(reader);
    static_cast<void>(status);
    parent_->m_mainWindow->addMessageToOutput(QString("Requested deadline missed"));
}

void ShapeSubscriber::SubListener::on_liveliness_changed(
        DataReader* reader,
        const eprosima::fastrtps::LivelinessChangedStatus& status)
{
    static_cast<void>(reader);
    if (status.alive_count_change == 1)
    {
        parent_->m_mainWindow->addMessageToOutput(QString("Liveliness recovered"));
    }
    else if (status.not_alive_count_change == 1)
    {
        parent_->m_mainWindow->addMessageToOutput(QString("Liveliness lost"));
    }
}

//void ShapeSubscriber::removeSamplesFromWriter(GUID_t)
