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
 * @file ShapesDemo.h
 *
 */

#ifndef SHAPESDEMO_H_
#define SHAPESDEMO_H_

#include "eprosimashapesdemo/shapesdemo/ShapePubSubTypes.h"
#include "eprosimashapesdemo/shapesdemo/ShapeDefinitions.h"
#include <QMutex>
#include <vector>

namespace eprosima
{
namespace fastrtps
{
class Participant;
}
}

using namespace eprosima::fastrtps;



/**
 * @brief The ShapesDemoOptions class, used to transmit the options between the options menu and the ShapesDemo class.
 */
class ShapesDemoOptions
{
public:
    bool m_udpTransport;
    bool m_tcpServer;
    uint32_t m_listenPort;
    uint32_t m_serverPort;
    std::string m_serverIp;
	std::string m_WANIp;
    uint32_t m_updateIntervalMs;
    uint32_t m_movementSpeed;
    uint32_t m_domainId;
    ShapesDemoOptions()
    {
        m_udpTransport = true;
        m_tcpServer = true;
        m_listenPort = 5100;
        m_serverPort = 5100;
        m_serverIp = "127.0.0.1";
		m_WANIp = "";	// An empty string means not to use WAN, the actual format should be the same as in m_serverIp
        m_updateIntervalMs = INITIAL_INTERVAL_MS;
        m_movementSpeed = 7;
        m_domainId = 0;
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
    ShapesDemo(MainWindow* mw);
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
     * @brief Get a pointer to the Participant.
     * @return Participant pointer.
     */
    Participant* getParticipant();
    /**
     * @brief Add a ShapePublisher to the demo.
     * @param SP Pointer to the ShapePublisher object.
     */
    void addPublisher(ShapePublisher* SP);
    /**
     * @brief Add a ShapeSubscriber to the demo.
     * @param SS Pointer to the ShapeSubscriber object.
     */
    void addSubscriber(ShapeSubscriber* SS);
    /**
     * @brief Remove a ShapePublisher.
     * @param SP Pointer to the ShapePublisher object.
     */
    void removePublisher(ShapePublisher* SP);
    /**
     * @brief Remove a ShapeSubscriber.
     * @param SS Pointer to the ShapeSubscriber object.
     */
    void removeSubscriber(ShapeSubscriber* SS);

    uint32_t getRandomX(uint32_t size=10);
    uint32_t getRandomY(uint32_t size=10);

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
    void setOptions(ShapesDemoOptions& opt);
    /**
     * @brief Get Options.
     * @return
     */
    ShapesDemoOptions getOptions();
    /**
     * @brief Tells if the demo is initialized.
     * @return
     */
    bool isInitialized(){return this->m_isInitialized;}


private:
    std::vector<ShapePublisher*> m_publishers;
    std::vector<ShapeSubscriber*> m_subscribers;
    Participant* mp_participant;

    //std::vector<ShapeType*> m_shapes;
    bool m_isInitialized;

    uint32_t minX,minY,maxX,maxY;


    void moveShape(Shape* sh);
    void getNewDirection(Shape* sh);

    ShapeTypePubSubType m_shapeTopicDataType;
    ShapesDemoOptions m_options;
    MainWindow* m_mainWindow;
    QMutex m_mutex;

};



#endif /* SHAPESDEMO_H_ */
