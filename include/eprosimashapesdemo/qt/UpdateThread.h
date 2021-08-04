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


class UpdateThread : public QThread
{
    Q_OBJECT

public:

    explicit UpdateThread(
            QObject* parent = 0,
            uint32_t threadN = 200);
    ~UpdateThread();

    void setMainW(
            MainWindow* mw);
    void updateInterval(
            uint32_t interval)
    {
        //  cout << "UPDATE: Thread ID: "<< this->thread()->currentThreadId()<<endl;
        m_interval = interval;
        m_hasIntervalChanged = true;
    }

private slots:

    void updateAll(
            void);

protected:

    void run(
            void);

private:

    MainWindow* m_mainW;
    QTimer* m_timer;
    uint32_t m_interval;
    uint32_t m_threadNumber;
    bool m_hasIntervalChanged;
};



#endif /* UPDATETHREAD_H_ */
