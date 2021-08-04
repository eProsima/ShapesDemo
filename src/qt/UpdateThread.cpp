// Copyright 2021 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// This file is part of eProsima Fast DDS Shapes-Demo.
//
// eProsima Fast DDS Shapes-Demo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// eProsima Fast DDS Shapes-Demo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with eProsima Fast DDS Shapes-Demo. If not, see <https://www.gnu.org/licenses/>.

/**
 * @file UpdateThread.cpp
 *
 */

#include "eprosimashapesdemo/qt/UpdateThread.h"
#include "eprosimashapesdemo/qt/mainwindow.h"

#include "eprosimashapesdemo/shapesdemo/ShapesDemo.h"


UpdateThread::UpdateThread(
        QObject* parent,
        uint32_t threadN)
    : QThread(parent)
    , m_mainW(NULL)
    , m_timer(NULL)
    , m_interval(INITIAL_INTERVAL_MS)
    , m_threadNumber(threadN)
    , m_hasIntervalChanged(false)
{

}

UpdateThread::~UpdateThread()
{
    if (m_timer != NULL)
    {
        delete m_timer;
    }
    quit();
}

void UpdateThread::run(
        void)
{
    if (m_timer == NULL)
    {
        QTimer::singleShot(0, this, SLOT(updateAll()));
    }
    //cout << "RUN: Thread ID: "<< this->thread()->currentThreadId()<<endl;
    exec();
}

void UpdateThread::updateAll(
        void)
{
    if (m_timer == NULL)
    {
        m_timer = new QTimer(this);
        connect(m_timer, SIGNAL(timeout()), this, SLOT(updateAll()));
        // cout << "START: Thread ID: "<< this->thread()->currentThreadId()<<endl;
        m_timer->start(m_interval);
    }

    // cout << "WRITE TIMER: "<< this->m_timer->interval();
    //cout << "WRITE: Thread ID: "<< this->thread()->currentThreadId()<<endl;
    if (this->m_threadNumber == 1)
    {
        m_mainW->writeNewSamples();
    }
    if (m_timer != NULL && m_hasIntervalChanged)
    {
        //cout << "Changing interval timer"<<endl;
        m_timer->setInterval(m_interval);
        m_hasIntervalChanged = false;
    }

}

void UpdateThread::setMainW(
        MainWindow* mw)
{
    m_mainW = mw;
}
