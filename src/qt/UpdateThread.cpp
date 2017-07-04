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
 * @file UpdateThread.cpp
 *
 */

#include "eprosimashapesdemo/qt/UpdateThread.h"
#include "eprosimashapesdemo/qt/mainwindow.h"

#include "eprosimashapesdemo/shapesdemo/ShapesDemo.h"


UpdateThread::UpdateThread(QObject *parent, uint32_t threadN):
    QThread(parent),
    m_mainW(NULL),
    m_timer(NULL),
    m_interval(INITIAL_INTERVAL_MS),
    m_threadNumber(threadN),
    m_hasIntervalChanged(false)
{

}

UpdateThread::~UpdateThread()
{
    if(m_timer != NULL)
       delete m_timer;
    quit();
}

void UpdateThread::run(void)
{
    if(m_timer==NULL)
    {
        QTimer::singleShot(0,this,SLOT(updateAll()));
    }
    //cout << "RUN: Thread ID: "<< this->thread()->currentThreadId()<<endl;
    exec();
}


void UpdateThread::updateAll(void)
{
    if(m_timer == NULL)
    {
        m_timer = new QTimer(this);
        connect(m_timer,SIGNAL(timeout()),this,SLOT(updateAll()));
   // cout << "START: Thread ID: "<< this->thread()->currentThreadId()<<endl;
        m_timer->start(m_interval);
    }

   // cout << "WRITE TIMER: "<< this->m_timer->interval();
    //cout << "WRITE: Thread ID: "<< this->thread()->currentThreadId()<<endl;
    if(this->m_threadNumber == 1)
        m_mainW->writeNewSamples();
    if(m_timer !=NULL && m_hasIntervalChanged)
    {
        //cout << "Changing interval timer"<<endl;
        m_timer->setInterval(m_interval);
        m_hasIntervalChanged = false;
    }

}

 void UpdateThread::setMainW(MainWindow* mw)
{
    m_mainW = mw;
}
