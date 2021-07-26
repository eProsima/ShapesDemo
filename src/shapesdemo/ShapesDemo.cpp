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

#include <iostream>
#include <sstream>
#include <ctime>

#include <eprosimashapesdemo/shapesdemo/ShapesDemo.h>
#include <eprosimashapesdemo/shapesdemo/ShapePublisher.h>
#include <eprosimashapesdemo/shapesdemo/ShapeSubscriber.h>
#include <eprosimashapesdemo/shapesdemo/ShapeInfo.h>
#include <eprosimashapesdemo/qt/mainwindow.h>

#include <fastdds/dds/domain/qos/DomainParticipantQos.hpp>
#include <fastdds/rtps/transport/TCPv4TransportDescriptor.h>
#include <fastdds/rtps/transport/UDPv4TransportDescriptor.h>
#include <fastrtps/utils/IPLocator.h>

using namespace eprosima::fastdds::dds;
using namespace eprosima::fastdds::rtps;
using namespace eprosima::fastrtps::rtps;

ShapesDemo::ShapesDemo(MainWindow *mw)
    : mp_participant(nullptr)
    , m_isInitialized(false)
    , minX(0),minY(0),maxX(0),maxY(0)
    , m_mainWindow(mw)
    , m_mutex(QMutex::Recursive)
    , m_type(new ShapeTypePubSubType())
{
    srand (time(nullptr));
    minX = 0;
    minY = 0;
    maxX = MAX_DRAW_AREA_X;
    maxY = MAX_DRAW_AREA_Y;
}

ShapesDemo::~ShapesDemo()
{
    stop();
}

DomainParticipant* ShapesDemo::getParticipant()
{
    if(m_isInitialized && mp_participant !=nullptr)
        return mp_participant;
    else
    {
        if(init())
            return mp_participant;
    }
    return nullptr;
}

bool ShapesDemo::init()
{
    //cout << "Initializing ShapesDemo "<< m_isInitialized <<endl;
    if(!m_isInitialized)
    {
        //cout <<"Creating new Participant"<<endl;
        ParticipantAttributes pparam;
        DomainParticipantQos qos;

        qos.name("Fast-DDS ShapesDemo Participant");
        qos.transport().use_builtin_transports = false;

        if (m_options.m_udpTransport)
        {
            std::shared_ptr<UDPv4TransportDescriptor> descriptor = std::make_shared<UDPv4TransportDescriptor>();
            qos.transport().user_transports.push_back(descriptor);
        }
        else
        {
            std::shared_ptr<TCPv4TransportDescriptor> descriptor = std::make_shared<TCPv4TransportDescriptor>();

            descriptor->wait_for_tcp_negotiation = false;
            descriptor->maxInitialPeersRange = 20;

            if (m_options.m_tcpServer)
            {
                if (m_options.m_tcpWAN)
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

        // Create a single publisher and subscriber per Participant
        mp_publisher = mp_participant->create_publisher(PUBLISHER_QOS_DEFAULT);
        mp_subscriber = mp_participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT);

    }
    return true;
}

void ShapesDemo::stop()
{
    if(m_isInitialized)
    {
        QMutexLocker lock(&m_mutex);
        this->m_mainWindow->quitThreads();

        // Remove all publishers
        for(std::vector<ShapePublisher*>::iterator it = m_publishers.begin();
            it!=m_publishers.end();++it)
        {
            delete(*it);
        }
        m_publishers.clear();

        // Remove all subscribers
        for(std::vector<ShapeSubscriber*>::iterator it = m_subscribers.begin();
            it!=m_subscribers.end();++it)
        {
            delete(*it);
        }
        m_subscribers.clear();

        // Eliminate topics
        for (auto it : m_topics)
        {
            mp_participant->delete_topic(it.second);
        }

        // Remove Participant
        DomainParticipantFactory::get_instance()->delete_participant(mp_participant);
        mp_participant = nullptr;
        m_isInitialized = false;
    }
}

void ShapesDemo::addPublisher(ShapePublisher* SP)
{
    m_publishers.push_back(SP);
    this->m_mainWindow->addPublisherToTable(SP);
}

void ShapesDemo::addSubscriber(ShapeSubscriber* SSub)
{
    m_subscribers.push_back(SSub);
    this->m_mainWindow->addSubscriberToTable(SSub);
}

uint32_t ShapesDemo::getRandomX(uint32_t size)
{
    return minX+size+(uint32_t)(((maxX-size)-(minX+size))*((double) rand() / (RAND_MAX)));
}

uint32_t ShapesDemo::getRandomY(uint32_t size)
{
    return minY+size+(uint32_t)(((maxY-size)-(minY+size))*((double) rand() / (RAND_MAX)));
}

void ShapesDemo::moveAllShapes()
{
    for(std::vector<ShapePublisher*>::iterator it = m_publishers.begin();
        it!=m_publishers.end();++it)
    {
        (*it)->m_mutex.lock();
        moveShape(&(*it)->m_shape);
        (*it)->m_mutex.unlock();
    }
}

void ShapesDemo::moveShape(Shape* sh)
{
    //TODO ESTAS DOS LINEAS NO SON NECESARIAS.
    if(sh->m_changeDir)
        getNewDirection(sh);
    //Apply movement
    int nx = sh->m_shape.x() + m_options.m_movementSpeed*sh->m_dirX;
    int ny = sh->m_shape.y() + m_options.m_movementSpeed*sh->m_dirY;
    //Check if the movement is correct
    bool cond1 = nx+(int)sh->m_shape.shapesize() /2 > (int)maxX;
    bool cond2 = nx-(int)sh->m_shape.shapesize() /2 < (int)minX;
    bool cond3 = ny+(int)sh->m_shape.shapesize() /2 > (int)maxY;
    bool cond4 = ny-(int)sh->m_shape.shapesize() /2 < (int)minY;
    while(cond1 || cond2 || cond3 || cond4)
    {
        getNewDirection(sh);
        nx = sh->m_shape.x() + m_options.m_movementSpeed*sh->m_dirX;
        ny = sh->m_shape.y() + m_options.m_movementSpeed*sh->m_dirY;
        cond1 = nx+(int)sh->m_shape.shapesize() /2 > (int)maxX;
        cond2 = nx-(int)sh->m_shape.shapesize() /2 < (int)minX;
        cond3 = ny+(int)sh->m_shape.shapesize() /2 > (int)maxY;
        cond4 = ny-(int)sh->m_shape.shapesize() /2 < (int)minY;
    }
    sh->m_shape.x(nx);
    sh->m_shape.y(ny);
}

void ShapesDemo::getNewDirection(Shape* sh)
{
    sh->m_dirX = ((double) rand() / (RAND_MAX))*2-1;
    sh->m_dirY = ((double) rand() / (RAND_MAX))*2-1;
    //Normalize
    float module = sqrt(pow(sh->m_dirX,2)+pow(sh->m_dirY,2));
    sh->m_dirX /= module;
    sh->m_dirY /= module;
    sh->m_changeDir = false;
}

void ShapesDemo::writeAll()
{
    for(std::vector<ShapePublisher*>::iterator it = m_publishers.begin();
        it!=m_publishers.end();++it)
    {
        (*it)->write();
    }
}

void ShapesDemo::setOptions(ShapesDemoOptions& opt)
{
    m_options = opt;
    m_mainWindow->updateInterval(m_options.m_updateIntervalMs);

}

ShapesDemoOptions ShapesDemo::getOptions()
{
    return m_options;
}

void ShapesDemo::removePublisher(ShapePublisher* SP)
{
    //cout << "REMOVING PUBLISHER"<<endl;
    for(std::vector<ShapePublisher*>::iterator it = this->m_publishers.begin();
        it!=this->m_publishers.end();++it)
    {
        if(SP->mp_datawriter->guid() == (*it)->mp_datawriter->guid())
        {
            m_publishers.erase(it);
            delete SP;
            break;
        }
    }

}

void ShapesDemo::removeSubscriber(ShapeSubscriber* SS)
{
    //cout << "REMOVING SUBSCRIBER"<<endl;
    for(std::vector<ShapeSubscriber*>::iterator it = this->m_subscribers.begin();
        it!=this->m_subscribers.end();++it)
    {
        if(SS->mp_datareader->guid() == (*it)->mp_datareader->guid())
        {
            m_subscribers.erase(it);
            delete SS;
            break;
        }
    }
}

Topic* ShapesDemo::getTopic(std::string topic_name)
{
    QMutexLocker lock(&m_mutex);

    // Look up if topic already exists
    auto it = m_topics.find(topic_name);

    if (it != m_topics.end())
    {
        // Topic already exists
        return it->second;
    }
    else
    {
        // Create new Topic
        Topic* topic = mp_participant->create_topic(
            topic_name,         // Topic name
            "ShapeType",        // Alwaysa same type
            TOPIC_QOS_DEFAULT); // TODO check if default QoS is correct

        // Add new topic to map
        m_topics[topic_name] = topic;

        return topic;
    }
}
