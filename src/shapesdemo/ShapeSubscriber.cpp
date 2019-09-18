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

#include <eprosimashapesdemo/shapesdemo/ShapeSubscriber.h>
#include <eprosimashapesdemo/qt/ContentFilterSelector.h>
#include <fastrtps/utils/TimeConversion.h>

#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/subscriber/SampleInfo.h>
#include <fastrtps/Domain.h>

#include <eprosimashapesdemo/qt/mainwindow.h>

ShapeSubscriber::ShapeSubscriber(
        MainWindow* win,
        Participant* par)
    : mp_sub(nullptr)
    , mp_participant(par)
    , hasReceived(false)
    , m_mutex(QMutex::Recursive)
    , mp_contentFilter(nullptr)
    , m_mainWindow(win)
{
    // TODO Auto-generated constructor stub

}

ShapeSubscriber::~ShapeSubscriber()
{
    // TODO Auto-generated destructor stub
    Domain::removeSubscriber(mp_sub);
    if (mp_contentFilter!=nullptr)
    {
        delete(mp_contentFilter);
    }
}

bool ShapeSubscriber::initSubscriber()
{
    mp_sub = Domain::createSubscriber(mp_participant,m_attributes,(SubscriberListener*)this);
    if (mp_sub !=nullptr)
    {
        return true;
    }
    return false;
}

void ShapeSubscriber::onNewDataMessage(
        Subscriber* sub)
{
    Shape shape;
    shape.m_type = this->m_shapeType;
    SampleInfo_t info;
    while (sub->takeNextData((void*)&shape.m_shape,&info))
    {
        shape.m_time = info.sourceTimestamp.to_duration_t();
        shape.m_writerGuid = info.sample_identity.writer_guid();
        shape.m_strength = info.ownershipStrength;
        QMutexLocker locck(&this->m_mutex);
        if (info.sampleKind == rtps::ALIVE)
        {
            hasReceived = true;
            m_shapeHistory.addToHistory(shape);
        }
        else
        {
            SD_COLOR color = getColorFromInstanceHandle(info.iHandle);
            if (info.sampleKind == rtps::NOT_ALIVE_DISPOSED)
            {
                m_shapeHistory.dispose(color);
            }
            else
            {
                m_shapeHistory.unregister(color);
            }
        }
    }
}



void ShapeSubscriber::onSubscriptionMatched(
        Subscriber* /*sub*/,
        rtps::MatchingInfo& info)
{
    if (info.status == rtps::MATCHED_MATCHING)
    {
        bool found = false;
        for (std::vector<rtps::GUID_t>::iterator it = m_remoteWriters.begin();
            it!=m_remoteWriters.end();++it)
        {
            if (*it==info.remoteEndpointGuid)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            m_remoteWriters.push_back(info.remoteEndpointGuid);
        }
    }
    else if (info.status == rtps::REMOVED_MATCHING)
    {
        m_mutex.lock();
        m_shapeHistory.removedOwner(info.remoteEndpointGuid);
        m_mutex.unlock();
    }
}

void ShapeSubscriber::adjustContentFilter(
        ShapeFilter &filter)
{
    m_mutex.lock();
    m_shapeHistory.adjustContentFilter(filter);
    m_mutex.unlock();
}

void ShapeSubscriber::on_requested_deadline_missed(
        Subscriber*,
        const RequestedDeadlineMissedStatus&)
{
    m_mainWindow->addMessageToOutput(QString("Requested deadline missed"));
}

void ShapeSubscriber::on_liveliness_changed(
        Subscriber*,
        const LivelinessChangedStatus& status)
{
    if (status.alive_count_change == 1 || status.not_alive_count_change == -1)
    {
        m_mainWindow->addMessageToOutput(QString("Liveliness recovered"));
    }
    else if (status.not_alive_count_change == 1 || status.alive_count_change == -1)
    {
        m_mainWindow->addMessageToOutput(QString("Liveliness lost"));
    }

}

//void ShapeSubscriber::removeSamplesFromWriter(GUID_t)
