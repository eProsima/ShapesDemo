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
 * @file UpdateThread.h
 *
 */

#ifndef UPDATETHREAD_H_
#define UPDATETHREAD_H_

#include <QThread>
#include <QTimer>
#include <cstdint>

#include <iostream>
using namespace std;

class MainWindow;


class UpdateThread: public QThread
{
     Q_OBJECT
public:
    explicit UpdateThread(QObject* parent = 0,uint32_t threadN=200);
    ~UpdateThread();

    void setMainW(MainWindow* mw);
    void updateInterval(uint32_t interval)
    {
      //  cout << "UPDATE: Thread ID: "<< this->thread()->currentThreadId()<<endl;
        m_interval = interval;
        m_hasIntervalChanged = true;
    }

private slots:
    void updateAll(void);
protected:
    void run(void);
private:
    MainWindow* m_mainW;
    QTimer* m_timer;
    uint32_t m_interval;
    uint32_t m_threadNumber;
    bool m_hasIntervalChanged;
};



#endif /* UPDATETHREAD_H_ */
