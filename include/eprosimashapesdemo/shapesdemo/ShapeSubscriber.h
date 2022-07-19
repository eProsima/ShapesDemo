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
#include <fastdds/dds/topic/ContentFilteredTopic.hpp>
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
            ShapesDemo* sd,
            Topic* topic);

    virtual ~ShapeSubscriber();

    DataReaderQos m_dr_qos;
    SubscriberQos m_sub_qos;
    ShapesDemo* mp_sd;
    DataReader* mp_datareader;
    eprosima::fastdds::dds::Subscriber* mp_subscriber;
    Topic* mp_topic;
    ContentFilteredTopic* mp_filtered_topic = nullptr;

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
    ShapeHistory m_shapeHistory;
    TYPESHAPE m_shapeType;
    ContentFilterSelector* mp_contentFilter;
    MainWindow* m_mainWindow;
};

#endif /* SHAPESUBSCRIBER_H_ */
