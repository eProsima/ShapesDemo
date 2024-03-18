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
 * @file ShapesDemo.h
 *
 */

#ifndef SHAPESDEMO_H_
#define SHAPESDEMO_H_

#include <map>

#include <QMutex>

#include "eprosimashapesdemo/shapesdemo/ShapePubSubTypes.h"
#include "eprosimashapesdemo/shapesdemo/ShapeDefinitions.h"

#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipantListener.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/topic/TopicDescription.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/rtps/common/Guid.h>
#include <fastdds/rtps/writer/WriterDiscoveryInfo.h>

using namespace eprosima::fastdds::dds;

/**
 * @brief The ShapesDemoOptions class, used to transmit the options between the options menu and the ShapesDemo class.
 */
class ShapesDemoOptions
{
public:

    bool m_udp_transport;
    bool m_tcp_transport;
    bool m_intraprocess_transport;
    bool m_shm_transport;
    bool m_statistics;
    bool m_ros2_topic;
    QString m_tcp_type;
    uint16_t m_listenPort;
    uint16_t m_serverPort;
    std::string m_serverIp;
    uint32_t m_updateIntervalMs;
    uint32_t m_movementSpeed;
    uint32_t m_domainId;
    bool m_auto_fill_type_information;

    ShapesDemoOptions()
    {
        m_udp_transport = true;
        m_tcp_transport = false;
        m_intraprocess_transport = true;
        m_shm_transport = true;
        m_statistics = false;
        m_ros2_topic = false;
        m_listenPort = 5100;
        m_serverPort = 5100;
        m_serverIp = "127.0.0.1";
        m_updateIntervalMs = INITIAL_INTERVAL_MS;
        m_movementSpeed = 7;
        m_domainId = 0;
        m_tcp_type = QString("TCP LAN Server");
        m_auto_fill_type_information = true;
    }

    bool tcp_lan()
    {
        return m_tcp_type == QString("TCP LAN Server");
    }

    bool tcp_wan()
    {
        return m_tcp_type == QString("TCP WAN Server");
    }

    bool tcp_client()
    {
        return m_tcp_type == QString("TCP Client");
    }

    ~ShapesDemoOptions()
    {

    }

};

class ShapePublisher;
class ShapeSubscriber;
class Shape;
class MainWindow;

/**
 * @brief The ShapesDemo class, implements the basic behaviour of the demo.
 */
class ShapesDemo
{
    friend class DrawArea;

public:

    ShapesDemo(
            MainWindow* mw);
    ~ShapesDemo();
    /**
     * @brief Initialize the demo.
     * @return True if correctly initialized.
     */
    bool init();
    /**
     * @brief Stop the demo (removes the RTPSParticipants and all publishers and subscribers.)
     */
    void stop();
    /**
     * @brief Get a pointer to the DomainParticipant.
     * @return DomainParticipant pointer.
     */
    DomainParticipant* getParticipant();
    /**
     * @brief Add a ShapePublisher to the demo.
     * @param SP Pointer to the ShapePublisher object.
     */
    void addPublisher(
            ShapePublisher* SP);
    /**
     * @brief Add a ShapeSubscriber to the demo.
     * @param SS Pointer to the ShapeSubscriber object.
     */
    void addSubscriber(
            ShapeSubscriber* SS);
    /**
     * @brief Remove a ShapePublisher.
     * @param SP Pointer to the ShapePublisher object.
     */
    void removePublisher(
            ShapePublisher* SP);
    /**
     * @brief Remove a ShapeSubscriber.
     * @param SS Pointer to the ShapeSubscriber object.
     */
    void removeSubscriber(
            ShapeSubscriber* SS);

    uint32_t getRandomX(
            uint32_t size = 10);
    uint32_t getRandomY(
            uint32_t size = 10);

    //    /**
    //     * @brief Get the shapes to draw.
    //     * @param shvec Pointer to a shapevector.
    //     * @return True if found.
    //     */
    //    bool getShapes(std::vector<Shape*>* shvec);

    //     QMutex* getMutex()
    //     {
    //         return &m_mutex;
    //     }
    /**
     * @brief Move all shapes from all shapesPublishers.
     */
    void moveAllShapes();
    /**
     * @brief Write all shapes.
     */
    void writeAll();
    /**
     * @brief Set the options for the shapesDemo.
     * @param opt Reference to the ShapesDemoOptions object.
     */
    void setOptions(
            ShapesDemoOptions& opt);
    /**
     * @brief Get Options.
     * @return
     */
    ShapesDemoOptions getOptions();
    /**
     * @brief Tells if the demo is initialized.
     * @return
     */
    bool isInitialized()
    {
        return this->m_isInitialized;
    }

    Topic* getTopic(
            std::string topic_name);

<<<<<<< HEAD
    bool data_sharing_enable ()
    {
        return m_data_sharing_enable;
    }

    // NOTE: there is no other way to check ownership strength unless using DomainParticipant callback listener
    // on_publisher_discovery and storing to a map

    //! Add ownership strength to a writer
    bool add_writer_strength(
            const eprosima::fastrtps::rtps::GUID_t& guid,
            uint32_t strength);

    //! Erase ownership strength from a writer (When writer drops)
    bool remove_writer_strength(
            eprosima::fastrtps::rtps::GUID_t guid);

    //! Get writer strength
    uint32_t writer_strength(
            eprosima::fastrtps::rtps::GUID_t guid);

=======
>>>>>>> 0fc2837 (Remove Data-Sharing option from ShapesDemo (#113))
private:

    std::map<eprosima::fastrtps::rtps::GUID_t, uint32_t> m_ownership_strength_map;

    std::vector<ShapePublisher*> m_publishers;
    std::vector<ShapeSubscriber*> m_subscribers;
    eprosima::fastdds::dds::DomainParticipant* mp_participant;

    //std::vector<ShapeType*> m_shapes;
    bool m_isInitialized;

    uint32_t minX, minY, maxX, maxY;


    void moveShape(
            Shape* sh);

    // Modify X axis or Y axis
    void getNewDirection(
            Shape* sh);

    ShapesDemoOptions m_options;
    MainWindow* m_mainWindow;
    QMutex m_mutex;
    TypeSupport m_type;
#ifdef ENABLE_ROS_COMPONENTS
    TypeSupport m_ros_type;
#endif // ifdef ENABLE_ROS_COMPONENTS
    std::map<std::string, Topic*> m_topics;
<<<<<<< HEAD
    bool m_data_sharing_enable;

    class Listener : public eprosima::fastdds::dds::DomainParticipantListener
    {
    public:

        Listener(
                ShapesDemo* participant)
            : mp_parent_(participant)
        {
        }

        /* Custom Callback on_publisher_discovery */
        virtual void on_publisher_discovery(
                eprosima::fastdds::dds::DomainParticipant*,
                eprosima::fastrtps::rtps::WriterDiscoveryInfo&& info)
        {
            switch (info.status){
                case eprosima::fastrtps::rtps::WriterDiscoveryInfo::DISCOVERED_WRITER:
                case eprosima::fastrtps::rtps::WriterDiscoveryInfo::CHANGED_QOS_WRITER:
                    // Add strength to Participant map
                    mp_parent_->add_writer_strength(info.info.guid(), info.info.m_qos.m_ownershipStrength.value);
                    break;
                case eprosima::fastrtps::rtps::WriterDiscoveryInfo::REMOVED_WRITER:
                    // Erase strength to Participant map
                    mp_parent_->remove_writer_strength(info.info.guid());
                    break;
            }
        }

    private:

        ShapesDemo* mp_parent_;
    }
    m_listener;
=======
>>>>>>> 0fc2837 (Remove Data-Sharing option from ShapesDemo (#113))
};

#endif /* SHAPESDEMO_H_ */
