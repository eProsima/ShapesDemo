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
 * @file ShapePublisher.cpp
 */

#include "eprosimashapesdemo/shapesdemo/ShapePublisher.h"
#include "fastrtps/Domain.h"
#include "fastrtps/publisher/Publisher.h"

#include <eprosimashapesdemo/qt/mainwindow.h>
#include <thread>

ShapePublisher::ShapePublisher(
        MainWindow* win,
        DomainParticipant* par,
        Topic* topic)
    : mp_participant(par)
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
        if (mp_participant && mp_publisher && mp_datawriter)
        {
            Duration_t wait_time(1, 0);
            rtps::InstanceHandle_t handle;

            mp_datawriter->dispose((void*)&this->m_shape.m_shape, handle);
            mp_datawriter->wait_for_acknowledgments(wait_time);

            if (ReturnCode_t::RETCODE_OK != mp_publisher->delete_datawriter(mp_datawriter))
            {
                std::cerr << "Error deleting datawriter: " << mp_datawriter->guid() << std::endl;
                return;
            }
        }

        if (mp_participant && mp_publisher)
        {
            if (ReturnCode_t::RETCODE_OK != mp_participant->delete_publisher(mp_publisher))
            {
                std::cerr << "Error deleting publisher: " << std::endl;
                return;
            }
        }
    }
}

bool ShapePublisher::initPublisher()
{
    mp_publisher = mp_participant->create_publisher(m_pub_qos);

    m_dw_qos.reliable_writer_qos().times.heartbeatPeriod.seconds = 0;
    m_dw_qos.reliable_writer_qos().times.heartbeatPeriod.nanosec = 500000000;

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
    static_cast<void>(writer);
    static_cast<void>(status);
    parent_->m_mainWindow->addMessageToOutput(QString("Offered deadline missed"));
}

void ShapePublisher::PubListener::on_liveliness_lost(
        DataWriter* writer,
        const LivelinessLostStatus& status)
{
    static_cast<void>(writer);
    static_cast<void>(status);
    parent_->m_mainWindow->addMessageToOutput(QString("Publisher lost liveliness"));
}
