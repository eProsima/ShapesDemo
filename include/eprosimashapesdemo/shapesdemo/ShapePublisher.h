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

#include "ShapeInfo.h"

#include <QMutex>
#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/publisher/PublisherListener.h>

#include <fastrtps/fastrtps_fwd.h>

class MainWindow;

using namespace eprosima::fastrtps;

/**
 * @brief The ShapePublisher class, implements a Publisher to transmit shapes.
 */
class ShapePublisher: public PublisherListener {
public:
    ShapePublisher(
            MainWindow*,
            Participant* par);

    virtual ~ShapePublisher();

    PublisherAttributes m_attributes;
    Publisher* mp_pub;
    Participant* mp_participant;

    /**
     * @brief Initialize the publisher.
     * @return  True if correct.
     */
    bool initPublisher();

    /**
     * @brief Write the shape.
     */
    void write();

    /**
     * @brief onPublicationMatched
     * @param info
     */
    void onPublicationMatched(
            Publisher* pub,
            rtps::MatchingInfo& info);

    void on_offered_deadline_missed(
            Publisher*,
            const OfferedDeadlineMissedStatus&) override;

    void on_liveliness_lost(
            Publisher*,
            const LivelinessLostStatus&) override;

    Shape m_shape;
    QMutex m_mutex;
    bool isInitialized;
    bool hasWritten;
    MainWindow* m_mainWindow;
};


#endif /* SHAPEPUBLISHER_H_ */
