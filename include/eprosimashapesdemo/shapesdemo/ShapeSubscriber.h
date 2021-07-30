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
 * @file ShapeSubscriber.h
 *
 */

#ifndef SHAPESUBSCRIBER_H_
#define SHAPESUBSCRIBER_H_

#include <QMutex>

#include "eprosimashapesdemo/shapesdemo/Shape.h"
#include "eprosimashapesdemo/shapesdemo/ShapeHistory.h"
#include "eprosimashapesdemo/shapesdemo/ShapesDemo.h"

#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/topic/Topic.hpp>

using namespace eprosima::fastdds::dds;

class ContentFilterSelector;
class MainWindow;

/**
 * @brief The ShapeSubscriber class, implements a Subscriber to receive shapes.
 */
class ShapeSubscriber
{
public:

    ShapeSubscriber(
            MainWindow* win,
            DomainParticipant* par,
            Topic* topic);

    virtual ~ShapeSubscriber();

    DataReaderQos m_dr_qos;
    SubscriberQos m_sub_qos;
    DomainParticipant* mp_participant;
    DataReader* mp_datareader;
    eprosima::fastdds::dds::Subscriber* mp_subscriber;
    Topic* mp_topic;

    /**
     * @brief Initialize the subscriber
     * @return True if correct.
     */
    bool initSubscriber();

    void adjustContentFilter(
            ShapeFilter& m_filter);

    void assignContentFilterPointer(
            ContentFilterSelector* p)
    {
        mp_contentFilter = p;
    }

    class SubListener : public eprosima::fastdds::dds::DataReaderListener
    {
    public:

        SubListener(
                ShapeSubscriber* parent)
            : parent_(parent)
        {
        }

        ~SubListener() override
        {
        }

        void on_data_available(
                DataReader* reader) override;

        void on_subscription_matched(
                DataReader* reader,
                const eprosima::fastdds::dds::SubscriptionMatchedStatus& info) override;

        void on_requested_deadline_missed(
                DataReader* reader,
                const eprosima::fastrtps::RequestedDeadlineMissedStatus& status) override;

        void on_liveliness_changed(
                DataReader* reader,
                const eprosima::fastrtps::LivelinessChangedStatus& status) override;

    private:

        ShapeSubscriber* parent_;

    }
    listener_;

    std::string getTopicName() const
    {
        return mp_topic->get_name();
    }

    bool hasReceived;
    QMutex m_mutex;
    std::vector<rtps::GUID_t> m_remoteWriters;
    ShapeHistory m_shapeHistory;
    TYPESHAPE m_shapeType;
    ContentFilterSelector* mp_contentFilter;
    MainWindow* m_mainWindow;
};

#endif /* SHAPESUBSCRIBER_H_ */
