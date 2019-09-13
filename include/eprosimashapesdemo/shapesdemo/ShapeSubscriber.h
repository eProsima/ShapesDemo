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


#include "eprosimashapesdemo/shapesdemo/Shape.h"
#include "eprosimashapesdemo/shapesdemo/ShapesDemo.h"
#include "eprosimashapesdemo/shapesdemo/ShapeHistory.h"
#include <QMutex>

#include "fastrtps/attributes/SubscriberAttributes.h"
#include "fastrtps/subscriber/SubscriberListener.h"

#include "fastrtps/fastrtps_fwd.h"

using namespace eprosima::fastrtps;

class ContentFilterSelector;
class MainWindow;

/**
 * @brief The ShapeSubscriber class, implements a Subscriber to receive shapes.
 */
class ShapeSubscriber: public SubscriberListener {
public:
    ShapeSubscriber(
            MainWindow*,
            Participant* par);

    virtual ~ShapeSubscriber();

    SubscriberAttributes m_attributes;
    Subscriber* mp_sub;
    Participant* mp_participant;

    /**
     * @brief Initialize the subscriber
     * @return True if correct.
     */
    bool initSubscriber();

    void onNewDataMessage(
            Subscriber* sub);

    void onSubscriptionMatched(
            Subscriber* sub,
            rtps::MatchingInfo& info);

    void adjustContentFilter(
            ShapeFilter& m_filter);

    void assignContentFilterPointer(
            ContentFilterSelector* p)
    {
        mp_contentFilter = p;
    }

    void on_requested_deadline_missed(
            Subscriber*,
            const RequestedDeadlineMissedStatus&) override;

    void on_liveliness_changed(
            Subscriber*,
            const LivelinessChangedStatus&) override;

    bool hasReceived;
    QMutex m_mutex;
    std::vector<rtps::GUID_t> m_remoteWriters;
    ShapeHistory m_shapeHistory;
    TYPESHAPE m_shapeType;
    ContentFilterSelector* mp_contentFilter;
    MainWindow* m_mainWindow;
};

#endif /* SHAPESUBSCRIBER_H_ */
