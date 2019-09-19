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
        Participant* par)
    : mp_pub(nullptr)
    , mp_participant(par)
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
        mp_pub->dispose_and_unregister((void*)&this->m_shape.m_shape);
        Domain::removePublisher(mp_pub);
    }
}

bool ShapePublisher::initPublisher()
{
    m_attributes.times.heartbeatPeriod.seconds = 0;
    m_attributes.times.heartbeatPeriod.nanosec = 500000000;

    mp_pub = Domain::createPublisher(mp_participant,m_attributes,(PublisherListener*)this);
    if (mp_pub !=nullptr)
    {
         isInitialized = true;
         return true;
    }
    return false;
}

void ShapePublisher::write()
{
    if (mp_pub !=nullptr)
    {
        mp_pub->write((void*)&this->m_shape.m_shape);
        m_mutex.lock();
        hasWritten = true;
        m_mutex.unlock();
    }
}

void ShapePublisher::onPublicationMatched(
        Publisher* /*pub*/,
        rtps::MatchingInfo& info)
{
    if (info.status == rtps::MATCHED_MATCHING)
    {
        std::cout << "Publisher in topic " << m_attributes.topic.getTopicName() << " MATCHES Sub: " << info.remoteEndpointGuid << std::endl;
    }
    else if (info.status == rtps::REMOVED_MATCHING)
    {
        std::cout << "Publisher in topic " << m_attributes.topic.getTopicName() << " REMOVES Sub: " << info.remoteEndpointGuid << std::endl;
    }
}

void ShapePublisher::on_offered_deadline_missed(
        Publisher*,
        const OfferedDeadlineMissedStatus&)
{
    m_mainWindow->addMessageToOutput(QString("Offered deadline missed"));
}

void ShapePublisher::on_liveliness_lost(
        Publisher*,
        const LivelinessLostStatus&)
{
    m_mainWindow->addMessageToOutput(QString("Publisher lost liveliness"));
}
