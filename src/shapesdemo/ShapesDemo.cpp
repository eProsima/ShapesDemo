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

#include <eprosimashapesdemo/shapesdemo/ShapesDemo.h>

#include <ctime>
#include <iostream>
#include <sstream>

#include <fastdds/dds/domain/qos/DomainParticipantQos.hpp>
#include <fastdds/rtps/transport/shared_mem/SharedMemTransportDescriptor.h>
#include <fastdds/rtps/transport/TCPv4TransportDescriptor.h>
#include <fastdds/rtps/transport/UDPv4TransportDescriptor.h>
#include <fastdds/rtps/transport/test_UDPv4TransportDescriptor.h>
#include <fastrtps/config.h> // FASTDDS_STATISTICS availability
#include <fastrtps/utils/IPLocator.h>
#include <fastrtps/xmlparser/XMLProfileManager.h>

#include <eprosimashapesdemo/qt/mainwindow.h>
#include <eprosimashapesdemo/shapesdemo/ShapeInfo.h>
#include <eprosimashapesdemo/shapesdemo/ShapePublisher.h>
#include <eprosimashapesdemo/shapesdemo/ShapeSubscriber.h>
#include <types/ShapeTypeObject.h>
#ifdef ENABLE_ROS_COMPONENTS
#include <types/KeylessShapeTypePubSubTypes.h>
#include <types/KeylessShapeTypeTypeObject.h>
#endif // ifdef ENABLE_ROS_COMPONENTS

using namespace eprosima::fastdds::dds;
using namespace eprosima::fastdds::rtps;
using namespace eprosima::fastrtps::rtps;

ShapesDemo::ShapesDemo(
        MainWindow* mw)
    : mp_participant(nullptr)
    , m_isInitialized(false)
    , minX(0)
    , minY(0)
    , maxX(0)
    , maxY(0)
    , m_mainWindow(mw)
    , m_mutex(QMutex::Recursive)
    , m_type(new ShapeTypePubSubType())
#ifdef ENABLE_ROS_COMPONENTS
    , m_ros_type(new shapes_demo_typesupport::idl::KeylessShapeTypePubSubType())
#endif // ifdef ENABLE_ROS_COMPONENTS
    , m_data_sharing_enable(false)
{
    srand (time(nullptr));
    minX = 0;
    minY = 0;
    maxX = MAX_DRAW_AREA_X;
    maxY = MAX_DRAW_AREA_Y;

    m_type->auto_fill_type_object(false);
    m_type->auto_fill_type_information(true);

#ifdef ENABLE_ROS_COMPONENTS
    m_ros_type->auto_fill_type_object(false);
    m_ros_type->auto_fill_type_information(true);

    registerKeylessShapeTypeTypes();
#endif // ifdef ENABLE_ROS_COMPONENTS

    registerShapeTypes();
}

ShapesDemo::~ShapesDemo()
{
    stop();
}

DomainParticipant* ShapesDemo::getParticipant()
{
    if (m_isInitialized && mp_participant != nullptr)
    {
        return mp_participant;
    }
    else
    {
        if (init())
        {
            return mp_participant;
        }
    }
    return nullptr;
}

bool ShapesDemo::init()
{
    if (!m_isInitialized)
    {
        std::cout << "Creating new Participant in domain: " << m_options.m_domainId << std::endl;

        DomainParticipantQos qos;

        qos.name("Fast DDS ShapesDemo Participant");
        qos.transport().use_builtin_transports = false;
        qos.wire_protocol().builtin.typelookup_config.use_server = true;

        // Set Participant properties
        qos.properties().properties().emplace_back("fastdds.application.id", "SHAPES_DEMO", true);
        qos.properties().properties().emplace_back("fastdds.application.metadata", "", true);

        if (m_options.m_monitor_service)
        {
            qos.properties().properties().emplace_back(
                "fastdds.enable_monitor_service",
                "true");
        }
        // Intraprocess
        LibrarySettingsAttributes library_settings;
        library_settings.intraprocess_delivery = m_options.m_intraprocess_transport ?
                IntraprocessDeliveryType::INTRAPROCESS_FULL : IntraprocessDeliveryType::INTRAPROCESS_OFF;
        xmlparser::XMLProfileManager::library_settings(library_settings);

        // Data Sharing
        m_data_sharing_enable = m_options.m_datasharing_transport;

        // Shared Memory
        if (m_options.m_shm_transport)
        {
            // Configure SHM Transport
            std::shared_ptr<SharedMemTransportDescriptor> shm_transport =
                    std::make_shared<SharedMemTransportDescriptor>();
            qos.transport().user_transports.push_back(shm_transport);
        }

        // UDP
        if (m_options.m_udp_transport)
        {
            // Configure UDP Transport
            std::shared_ptr<UDPv4TransportDescriptor> descriptor = std::make_shared<UDPv4TransportDescriptor>();
            qos.transport().user_transports.push_back(descriptor);
        }

        // UDP SAMPLE LOSS
        if (m_options.m_lossSampleEnabled)
        {
            // Configure UDP Transport with Sample Loss
            auto udp_lossy_descriptor = std::make_shared<test_UDPv4TransportDescriptor>();
            // Lambda function as a filter to drop only user data samples
            udp_lossy_descriptor->drop_data_messages_filter_ = [this](CDRMessage_t& msg) -> bool {

                uint32_t old_pos = msg.pos;

                // See RTPS DDS 9.4.5.3 Data Submessage
                EntityId_t writer_id;
                SequenceNumber_t sn;

                msg.pos += 2; // Flags
                msg.pos += 2; // Octets to inline quos
                msg.pos += 4; // ReaderEntityId
                CDRMessage::readEntityId(&msg, &writer_id);

                // Restore buffer pos
                msg.pos = old_pos;

                // Drop only user data messages
                if ((writer_id.value[3] & 0xC0) == 0)
                {
                    uint32_t random_number = rand() % 100;
                    return random_number < m_options.m_lossPerc;
                }
                else
                {
                    return false;
                }
            };
            qos.transport().user_transports.push_back(udp_lossy_descriptor);
        }

        // TCP
        if (m_options.m_tcp_transport)
        {
            std::shared_ptr<TCPv4TransportDescriptor> descriptor = std::make_shared<TCPv4TransportDescriptor>();

            descriptor->wait_for_tcp_negotiation = false;
            descriptor->maxInitialPeersRange = 20;

            if (m_options.tcp_lan() || m_options.tcp_wan())
            {
                if (m_options.tcp_wan())
                {
                    descriptor->set_WAN_address(m_options.m_serverIp);
                }

                descriptor->add_listener_port(m_options.m_listenPort);
            }
            else
            {
                Locator_t initial_peer_locator;
                initial_peer_locator.kind = LOCATOR_KIND_TCPv4;
                IPLocator::setIPv4(initial_peer_locator, m_options.m_serverIp);
                initial_peer_locator.port = m_options.m_serverPort;

                qos.wire_protocol().builtin.initialPeersList.push_back(initial_peer_locator);
            }

            qos.transport().user_transports.push_back(descriptor);
            qos.wire_protocol().builtin.discovery_config.leaseDuration_announcementperiod.seconds = 5;
        }

        if (!m_options.m_shm_transport &&
                !m_options.m_udp_transport &&
                !m_options.m_tcp_transport &&
                !m_options.m_lossSampleEnabled)
        {
            m_mainWindow->addMessageToOutput(
                QString("No Transport configured, using Fast DDS transports by default"), true);
            qos.transport().use_builtin_transports = true;
        }

        // Set the statistics if clicked
        if (m_options.m_statistics)
        {
            qos.properties().properties().emplace_back(
                "fastdds.statistics",
                "HISTORY_LATENCY_TOPIC;" \
                "NETWORK_LATENCY_TOPIC;" \
                "PUBLICATION_THROUGHPUT_TOPIC;" \
                "SUBSCRIPTION_THROUGHPUT_TOPIC;" \
                "RTPS_SENT_TOPIC;" \
                "RTPS_LOST_TOPIC;" \
                "HEARTBEAT_COUNT_TOPIC;" \
                "ACKNACK_COUNT_TOPIC;" \
                "NACKFRAG_COUNT_TOPIC;" \
                "GAP_COUNT_TOPIC;" \
                "DATA_COUNT_TOPIC;" \
                "RESENT_DATAS_TOPIC;" \
                "SAMPLE_DATAS_TOPIC;" \
                "PDP_PACKETS_TOPIC;" \
                "EDP_PACKETS_TOPIC;" \
                "DISCOVERY_TOPIC;" \
                "PHYSICAL_DATA_TOPIC;" \
                "MONITOR_SERVICE_TOPIC");

            // In case the Statistics are not compiled, show an error
#ifndef FASTDDS_STATISTICS
            std::cerr << "Statistics Module is not available" << std::endl;
#endif // #ifndef FASTDDS_STATISTICS
        }

        mp_participant = DomainParticipantFactory::get_instance()->create_participant(
            m_options.m_domainId,
            qos);

        if (nullptr == mp_participant)
        {
            return false;
        }

        // If the creation has been correct, register type
        m_isInitialized = true;
        m_type.register_type(mp_participant);
#ifdef ENABLE_ROS_COMPONENTS
        m_ros_type.register_type(mp_participant);
#endif // ifdef ENABLE_ROS_COMPONENTS
        std::cout << "Participant created correctly" << std::endl;
    }
    return true;
}

void ShapesDemo::stop()
{
    QMutexLocker lock(&m_mutex);
    if (m_isInitialized)
    {
        this->m_mainWindow->quitThreads();

        // Remove all publishers
        for (std::vector<ShapePublisher*>::iterator it = m_publishers.begin();
                it != m_publishers.end(); ++it)
        {
            delete(*it);
        }
        m_publishers.clear();

        // Remove all subscribers
        for (std::vector<ShapeSubscriber*>::iterator it = m_subscribers.begin();
                it != m_subscribers.end(); ++it)
        {
            delete(*it);
        }
        m_subscribers.clear();

        // Eliminate topics
        for (auto it : m_topics)
        {
            mp_participant->delete_topic(it.second);
        }
        m_topics.clear();

        // Remove Participant
        if (eprosima::fastrtps::types::ReturnCode_t::RETCODE_OK !=
                DomainParticipantFactory::get_instance()->delete_participant(mp_participant))
        {
            std::cerr << "Error deleting Participant" << std::endl;
            return;
        }
        mp_participant = nullptr;
        m_isInitialized = false;
    }
}

void ShapesDemo::addPublisher(
        ShapePublisher* SP)
{
    if (m_isInitialized)
    {
        m_publishers.push_back(SP);
        this->m_mainWindow->addPublisherToTable(SP);
    }
    else
    {
        delete SP;
    }
}

void ShapesDemo::addSubscriber(
        ShapeSubscriber* SSub)
{
    if (m_isInitialized)
    {
        m_subscribers.push_back(SSub);
        this->m_mainWindow->addSubscriberToTable(SSub);
    }
    else
    {
        delete SSub;
    }
}

uint32_t ShapesDemo::getRandomX(
        uint32_t size)
{
    return minX + size + (uint32_t)(((maxX - size) - (minX + size)) * ((double) rand() / (RAND_MAX)));
}

uint32_t ShapesDemo::getRandomY(
        uint32_t size)
{
    return minY + size + (uint32_t)(((maxY - size) - (minY + size)) * ((double) rand() / (RAND_MAX)));
}

void ShapesDemo::moveAllShapes()
{
    for (std::vector<ShapePublisher*>::iterator it = m_publishers.begin();
            it != m_publishers.end(); ++it)
    {
        (*it)->m_mutex.lock();
        moveShape(&(*it)->m_shape);
        (*it)->m_mutex.unlock();
    }
}

void ShapesDemo::moveShape(
        Shape* sh)
{
    //TODO ESTAS DOS LINEAS NO SON NECESARIAS.
    if (sh->m_changeDir)
    {
        getNewDirection(sh);
    }
    //Apply movement
    int nx = sh->m_shape.x() + m_options.m_movementSpeed * sh->m_dirX;
    int ny = sh->m_shape.y() + m_options.m_movementSpeed * sh->m_dirY;
    //Check if the movement is correct
    bool cond1 = nx + (int)sh->m_shape.shapesize() / 2 > (int)maxX;
    bool cond2 = nx - (int)sh->m_shape.shapesize() / 2 < (int)minX;
    bool cond3 = ny + (int)sh->m_shape.shapesize() / 2 > (int)maxY;
    bool cond4 = ny - (int)sh->m_shape.shapesize() / 2 < (int)minY;
    while (cond1 || cond2 || cond3 || cond4)
    {
        getNewDirection(sh);
        nx = sh->m_shape.x() + m_options.m_movementSpeed * sh->m_dirX;
        ny = sh->m_shape.y() + m_options.m_movementSpeed * sh->m_dirY;
        cond1 = nx + (int)sh->m_shape.shapesize() / 2 > (int)maxX;
        cond2 = nx - (int)sh->m_shape.shapesize() / 2 < (int)minX;
        cond3 = ny + (int)sh->m_shape.shapesize() / 2 > (int)maxY;
        cond4 = ny - (int)sh->m_shape.shapesize() / 2 < (int)minY;
    }
    sh->m_shape.x(nx);
    sh->m_shape.y(ny);
}

void ShapesDemo::getNewDirection(
        Shape* sh)
{
    sh->m_dirX = ((double) rand() / (RAND_MAX)) * 2 - 1;
    sh->m_dirY = ((double) rand() / (RAND_MAX)) * 2 - 1;
    //Normalize
    float module = sqrt(pow(sh->m_dirX, 2) + pow(sh->m_dirY, 2));
    sh->m_dirX /= module;
    sh->m_dirY /= module;
    sh->m_changeDir = false;
}

void ShapesDemo::writeAll()
{
    for (std::vector<ShapePublisher*>::iterator it = m_publishers.begin();
            it != m_publishers.end(); ++it)
    {
        (*it)->write();
    }
}

void ShapesDemo::setOptions(
        ShapesDemoOptions& opt)
{
    m_options = opt;
    m_mainWindow->updateInterval(m_options.m_updateIntervalMs);

}

ShapesDemoOptions ShapesDemo::getOptions()
{
    return m_options;
}

void ShapesDemo::removePublisher(
        ShapePublisher* SP)
{
    if (!SP || !SP->isInitialized)
    {
        return;
    }

    //cout << "REMOVING PUBLISHER"<<endl;
    for (std::vector<ShapePublisher*>::iterator it = this->m_publishers.begin();
            it != this->m_publishers.end(); ++it)
    {
        if (SP->mp_datawriter->guid() == (*it)->mp_datawriter->guid())
        {
            m_publishers.erase(it);
            delete SP;
            return;
        }
    }
}

void ShapesDemo::removeSubscriber(
        ShapeSubscriber* SS)
{
    if (!SS || !SS->mp_datareader) // There is no SS initialized variable
    {
        return;
    }

    //cout << "REMOVING SUBSCRIBER"<<endl;
    for (std::vector<ShapeSubscriber*>::iterator it = this->m_subscribers.begin();
            it != this->m_subscribers.end(); ++it)
    {
        if (SS->mp_datareader->guid() == (*it)->mp_datareader->guid())
        {
            m_subscribers.erase(it);
            delete SS;
            return;
        }
    }
}

Topic* ShapesDemo::getTopic(
        std::string topic_name)
{
    QMutexLocker lock(&m_mutex);

    // Look up if topic already exists
    std::map<std::string, Topic*>::iterator it = m_topics.find(topic_name);

    if (it != m_topics.end())
    {
        // Topic already exists
        return it->second;
    }
    else
    {
        Topic* topic;
        // Create new Topic

#ifdef ENABLE_ROS_COMPONENTS
        if (m_options.m_ros2_topic)
        {
            topic = mp_participant->create_topic(
                topic_name,     // Topic name
                m_ros_type.get_type_name(),
                TOPIC_QOS_DEFAULT); // TODO check if default QoS is correct

            // Add new topic to map
            m_topics[topic_name] = topic;

            return topic;
        }
        else
#endif // ifdef ENABLE_ROS_COMPONENTS
        {
            topic = mp_participant->create_topic(
                topic_name,     // Topic name
                "ShapeType",    // Always the same type
                TOPIC_QOS_DEFAULT); // TODO check if default QoS is correct

            // Add new topic to map
            m_topics[topic_name] = topic;
        }
        return topic;
    }
}

std::string qos_policy_id_to_string(
        QosPolicyId_t policy_id)
{
    std::string ret_val{"UnknownQoS"};
    switch (policy_id)
    {
        case USERDATA_QOS_POLICY_ID:
            ret_val = "USERDATA_QOS";
            break;
        case DURABILITY_QOS_POLICY_ID:
            ret_val = "DURABILITY_QOS";
            break;
        case PRESENTATION_QOS_POLICY_ID:
            ret_val = "PRESENTATION_QOS";
            break;
        case DEADLINE_QOS_POLICY_ID:
            ret_val = "DEADLINE_QOS";
            break;
        case LATENCYBUDGET_QOS_POLICY_ID:
            ret_val = "LATENCYBUDGET_QOS";
            break;
        case OWNERSHIP_QOS_POLICY_ID:
            ret_val = "OWNERSHIP_QOS";
            break;
        case OWNERSHIPSTRENGTH_QOS_POLICY_ID:
            ret_val = "OWNERSHIPSTRENGTH_QOS";
            break;
        case LIVELINESS_QOS_POLICY_ID:
            ret_val = "LIVELINESS_QOS";
            break;
        case TIMEBASEDFILTER_QOS_POLICY_ID:
            ret_val = "TIMEBASEDFILTER_QOS";
            break;
        case PARTITION_QOS_POLICY_ID:
            ret_val = "PARTITION_QOS";
            break;
        case RELIABILITY_QOS_POLICY_ID:
            ret_val = "RELIABILITY_QOS";
            break;
        case DESTINATIONORDER_QOS_POLICY_ID:
            ret_val = "DESTINATIONORDER_QOS";
            break;
        case HISTORY_QOS_POLICY_ID:
            ret_val = "HISTORY_QOS";
            break;
        case RESOURCELIMITS_QOS_POLICY_ID:
            ret_val = "RESOURCELIMITS_QOS";
            break;
        case ENTITYFACTORY_QOS_POLICY_ID:
            ret_val = "ENTITYFACTORY_QOS";
            break;
        case WRITERDATALIFECYCLE_QOS_POLICY_ID:
            ret_val = "WRITERDATALIVECYCLE_QOS";
            break;
        case READERDATALIFECYCLE_QOS_POLICY_ID:
            ret_val = "READERDATALIFECYCLE_QOS";
            break;
        case TOPICDATA_QOS_POLICY_ID:
            ret_val = "TOPICDATA_QOS";
            break;
        case GROUPDATA_QOS_POLICY_ID:
            ret_val = "GROUPDATA_QOS";
            break;
        case TRANSPORTPRIORITY_QOS_POLICY_ID:
            ret_val = "TRANSPORTPRIORITY_QOS";
            break;
        case LIFESPAN_QOS_POLICY_ID:
            ret_val = "LIFESPAN_QOS";
            break;
        case DURABILITYSERVICE_QOS_POLICY_ID:
            ret_val = "DURABILITYSERVICE_QOS";
            break;
        case DATAREPRESENTATION_QOS_POLICY_ID:
            ret_val = "DATAREPRESENTATION_QOS";
            break;
        case TYPECONSISTENCYENFORCEMENT_QOS_POLICY_ID:
            ret_val = "TYPECONSISTENCYENFORCEMENT_QOS";
            break;
        case DISABLEPOSITIVEACKS_QOS_POLICY_ID:
            ret_val = "DISABLEPOSITIVEACKS_QOS";
            break;
        case PARTICIPANTRESOURCELIMITS_QOS_POLICY_ID:
            ret_val = "PARTICIPANTRESOURCELIMITS_QOS";
            break;
        case PROPERTYPOLICY_QOS_POLICY_ID:
            ret_val = "PROPERTYPOLICY_QOS";
            break;
        case PUBLISHMODE_QOS_POLICY_ID:
            ret_val = "PUBLISHMODE_QOS";
            break;
        case READERRESOURCELIMITS_QOS_POLICY_ID:
            ret_val = "READERRESOURCELIMITS_QOS";
            break;
        case RTPSENDPOINT_QOS_POLICY_ID:
            ret_val = "RTPSENDPOINT_QOS";
            break;
        case RTPSRELIABLEREADER_QOS_POLICY_ID:
            ret_val = "RTPSRELIABLEREADER_QOS";
            break;
        case RTPSRELIABLEWRITER_QOS_POLICY_ID:
            ret_val = "RTPSRELIABLEWRITER_QOS";
            break;
        case TRANSPORTCONFIG_QOS_POLICY_ID:
            ret_val = "TRANSPORTCONFIG_QOS";
            break;
        case TYPECONSISTENCY_QOS_POLICY_ID:
            ret_val = "TYPECONSISTENCY_QOS";
            break;
        case WIREPROTOCOLCONFIG_QOS_POLICY_ID:
            ret_val = "WIREPROTOCOLCONFIG_QOS";
            break;
        case WRITERRESOURCELIMITS_QOS_POLICY_ID:
            ret_val = "WRITERRESOURCELIMITS_QOS";
            break;
        default:
            break;
    }

    return ret_val;
}

#ifdef ENABLE_ROS_COMPONENTS
bool detect_ros_2_installation()
{
    char* distro = nullptr;
    distro = getenv(ROS_2_ENVIRONMENT_VAR);

    if (nullptr != distro)
    {
        return true;
    }

    return false;
}

#endif // ifdef ENABLE_ROS_COMPONENTS
