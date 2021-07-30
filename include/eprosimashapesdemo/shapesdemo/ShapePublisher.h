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
 * @file ShapePublisher.h
 *
 */

#ifndef SHAPEPUBLISHER_H_
#define SHAPEPUBLISHER_H_

#include <QMutex>

#include "eprosimashapesdemo/shapesdemo/ShapeInfo.h"

#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/qos/DataWriterQos.hpp>
#include <fastdds/dds/topic/Topic.hpp>

class MainWindow;

using namespace eprosima::fastdds::dds;

/**
 * @brief The ShapePublisher class, implements a Publisher to transmit shapes.
 */
class ShapePublisher : public DataWriterListener
{
public:

    ShapePublisher(
            MainWindow* win,
            DomainParticipant* par,
            Topic* topic);

    virtual ~ShapePublisher();

    DataWriterQos m_dw_qos;
    PublisherQos m_pub_qos;
    DomainParticipant* mp_participant;
    DataWriter* mp_datawriter;
    eprosima::fastdds::dds::Publisher* mp_publisher;
    Topic* mp_topic;

    /**
     * @brief Initialize the publisher.
     * @return  True if correct.
     */
    bool initPublisher();

    /**
     * @brief Write the shape.
     */
    void write();

    class PubListener : public eprosima::fastdds::dds::DataWriterListener
    {
    public:

        PubListener(
                ShapePublisher* parent)
            : parent_(parent)
        {
        }

        ~PubListener() override
        {
        }

        /**
         * @brief onPublicationMatched
         * @param info
         */
        void on_publication_matched(
                DataWriter* writer,
                const PublicationMatchedStatus& info) override;

        void on_offered_deadline_missed(
                DataWriter* writer,
                const OfferedDeadlineMissedStatus& status) override;

        void on_liveliness_lost(
                DataWriter* writer,
                const LivelinessLostStatus& status) override;

    private:

        ShapePublisher* parent_;

    }
    listener_;

    std::string getTopicName() const
    {
        return mp_topic->get_name();
    }

    Shape m_shape;
    QMutex m_mutex;
    bool isInitialized;
    bool hasWritten;
    MainWindow* m_mainWindow;
};


#endif /* SHAPEPUBLISHER_H_ */
