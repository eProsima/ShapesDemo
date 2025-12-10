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
 * @file ShapePublisher.h
 *
 */

#ifndef SHAPEPUBLISHER_H_
#define SHAPEPUBLISHER_H_

#include <QMutex>

#include "eprosimashapesdemo/shapesdemo/ShapeInfo.h"
#include "eprosimashapesdemo/shapesdemo/ShapesDemo.h"

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
            ShapesDemo* sd,
            Topic* topic);

    virtual ~ShapePublisher();

    DataWriterQos m_dw_qos;
    PublisherQos m_pub_qos;
    ShapesDemo* mp_sd;
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

        void on_offered_incompatible_qos(
                DataWriter* writer,
                const OfferedIncompatibleQosStatus& status) override;

    private:

        ShapePublisher* parent_;

    }
    listener_;

    std::string getTopicName() const
    {
        return mp_topic->get_name();
    }

    Shape m_shape;
    QRecursiveMutex m_mutex;
    bool isInitialized;
    bool hasWritten;
    MainWindow* m_mainWindow;
};


#endif /* SHAPEPUBLISHER_H_ */
