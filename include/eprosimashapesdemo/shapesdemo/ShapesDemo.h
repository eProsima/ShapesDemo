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

#include <array>
#include <map>
#include <string>

#include <QMutex>

#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/topic/TopicDescription.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/rtps/common/Guid.hpp>

#include "eprosimashapesdemo/shapesdemo/ShapeDefinitions.h"
#include "types/ShapePubSubTypes.hpp"

using namespace eprosima::fastdds::dds;

std::string qos_policy_id_to_string(
        QosPolicyId_t policy_id);

#ifdef ENABLE_ROS_COMPONENTS
bool detect_ros_2_installation();
#endif // ifdef ENABLE_ROS_COMPONENTS

/**
 * @brief The ShapesDemoOptions class, used to transmit the options between the options menu and the ShapesDemo class.
 */
class ShapesDemoOptions
{
public:

    bool m_udp_transport {true};
    bool m_tcp_transport {false};
    bool m_intraprocess_transport {true};
    bool m_shm_transport {true};
    bool m_statistics {true};
    bool m_ros2_topic;
    bool m_monitor_service {true};
    QString m_tcp_type {"TCP LAN Server"};
    uint16_t m_listenPort {5100};
    uint16_t m_serverPort {5100};
    std::string m_serverIp {"127.0.0.1"};
    uint32_t m_updateIntervalMs {INITIAL_INTERVAL_MS};
    uint32_t m_movementSpeed {7};
    uint32_t m_domainId {0};
    uint32_t m_lossPerc {1};
    bool m_lossSampleEnabled {false};
    static std::array<std::pair<std::string, std::string>, 3> TYPE_PROPAGATION_VALUES;
    std::pair<std::string, std::string> type_propagation {TYPE_PROPAGATION_VALUES.at(0)};

    ShapesDemoOptions()
    {
#ifdef ENABLE_ROS_COMPONENTS
        m_ros2_topic = detect_ros_2_installation();
#else
        m_ros2_topic = false;
#endif // ifdef ENABLE_ROS_COMPONENTS
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
            const ShapesDemoOptions& opt);
    /**
     * @brief Get Options.
     * @return
     */
    const ShapesDemoOptions& getOptions() const;
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

private:

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
};

#endif /* SHAPESDEMO_H_ */
