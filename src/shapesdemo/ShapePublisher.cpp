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
 * @file ShapePublisher.cpp
 */

#include "eprosimashapesdemo/shapesdemo/ShapePublisher.h"

#include <eprosimashapesdemo/qt/mainwindow.h>
#include <thread>

ShapePublisher::ShapePublisher(
        MainWindow* win,
        ShapesDemo* sd,
        Topic* topic)
    : mp_sd(sd)
    , mp_datawriter(nullptr)
    , mp_publisher(nullptr)
    , mp_topic(topic)
    , listener_(this)
    , m_mutex(QMutex::Recursive)
    , isInitialized(false)
    , hasWritten(false)
    , m_mainWindow(win)
{
    // TODO Auto-generated constructor stub
}

ShapePublisher::~ShapePublisher()
{
    // TODO Auto-generated destructor stub
    if (isInitialized)
    {
        if (mp_sd->getParticipant() && mp_publisher && mp_datawriter)
        {
            Duration_t wait_time(1, 0);
            rtps::InstanceHandle_t handle;
            if (mp_datawriter->get_type()->m_isGetKeyDefined)
            {
                mp_datawriter->dispose((void*)&this->m_shape.m_shape, handle);
            }
            mp_datawriter->wait_for_acknowledgments(wait_time);

            if (RETCODE_OK != mp_publisher->delete_datawriter(mp_datawriter))
            {
                std::cerr << "Error deleting datawriter: " << mp_datawriter->guid() << std::endl;
                return;
            }
        }

        if (mp_sd->getParticipant() && mp_publisher)
        {
            if (RETCODE_OK != mp_sd->getParticipant()->delete_publisher(mp_publisher))
            {
                std::cerr << "Error deleting publisher: " << std::endl;
                return;
            }
        }
    }
}

bool ShapePublisher::initPublisher()
{
    mp_publisher = mp_sd->getParticipant()->create_publisher(m_pub_qos);

    m_dw_qos.reliable_writer_qos().times.heartbeat_period.seconds = 0;
    m_dw_qos.reliable_writer_qos().times.heartbeat_period.nanosec = 500 * 1000 * 1000;

    mp_datawriter = mp_publisher->create_datawriter(mp_topic, m_dw_qos, &listener_);

    isInitialized = true;

    return nullptr != mp_datawriter;
}

void ShapePublisher::write()
{
    if (mp_datawriter != nullptr)
    {
        mp_datawriter->write(&m_shape.m_shape);
        m_mutex.lock();
        hasWritten = true;
        m_mutex.unlock();
    }
}

void ShapePublisher::PubListener::on_publication_matched(
        DataWriter* writer,
        const PublicationMatchedStatus& info)
{
    if (info.current_count_change >= 1)
    {
        std::cout << "Publisher in topic " << writer->get_topic()->get_name() << " MATCHES Sub: "
                  << info.last_subscription_handle << std::endl;
    }
    else
    {
        std::cout << "Publisher in topic " <<  writer->get_topic()->get_name() << " REMOVES Sub: "
                  << info.last_subscription_handle << std::endl;
    }
}

void ShapePublisher::PubListener::on_offered_deadline_missed(
        DataWriter* writer,
        const OfferedDeadlineMissedStatus& status)
{
    if (0 < status.total_count_change)
    {
        std::stringstream str;
        str << "DataWriter " << writer->guid() << " detects deadline missed";
        parent_->m_mainWindow->addMessageToOutput(QString(str.str().c_str()));
    }
}

void ShapePublisher::PubListener::on_liveliness_lost(
        DataWriter* writer,
        const LivelinessLostStatus& status)
{
    if (0 < status.total_count_change)
    {
        std::stringstream str;
        str << "DataWriter " << writer->guid() << " detects liveliness lost";
        parent_->m_mainWindow->addMessageToOutput(QString(str.str().c_str()));
    }
}

void ShapePublisher::PubListener::on_offered_incompatible_qos(
        DataWriter* writer,
        const OfferedIncompatibleQosStatus& status)
{
    if (0 < status.total_count_change)
    {
        std::stringstream str;
        str << "DataWriter " << writer->guid() << " detects incompatible QoS " << qos_policy_id_to_string(
            status.last_policy_id);
        parent_->m_mainWindow->addMessageToOutput(QString(str.str().c_str()));
    }
}
