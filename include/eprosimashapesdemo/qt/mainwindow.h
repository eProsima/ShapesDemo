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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "eprosimashapesdemo/shapesdemo/ShapesDemo.h"


namespace Ui {
class MainWindow;
} // namespace Ui

class UpdateThread;
class QStandardItemModel;

/**
 * @brief The SD_ENDP_TYPE enum, defined if the endpoint is a publisher or a subscriber.
 */
enum SD_ENDP_TYPE
{
    PUB,
    SUB
};
/**
 * @brief The SD_Endpoint struct, stores information about a specific endpoint and its position in the table.
 */
struct SD_Endpoint
{
    SD_ENDP_TYPE type;
    ShapePublisher* pub;
    ShapeSubscriber* sub;
    int pos;
};
/**
 * @brief The MainWindow class, implements the main window.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(
            QWidget* parent = 0);
    ~MainWindow();
    /**
     * @brief getShapesDemo, gets a pointer to the shapesDemo object.
     * @return Pointer to the shapesDemo.
     */
    ShapesDemo* getShapesDemo()
    {
        return &m_shapesDemo;
    }

    /**
     * @brief writeNewSamples, move and write the samples for all subscribers.
     */
    void writeNewSamples();
    /**
     * @brief updateInterval, update the write event timer period.
     * @param ms Period in ms.
     */
    void updateInterval(
            uint32_t ms);
    /**
     * @brief quitThreads, stops all threads.
     */
    void quitThreads();
    /**
     * @brief addPublisherToTable, add a Publisher to the table.
     * @param spub Pointer to the ShapePublisher.
     */
    void addPublisherToTable(
            ShapePublisher* spub);
    /**
     * @brief addSubscriberToTable, add a Subscriber to the table.
     * @param ssub Pointer to the ShapeSubscriber.
     */
    void addSubscriberToTable(
            ShapeSubscriber* ssub);

    void keyPressEvent(
            QKeyEvent* event);

    void addMessageToOutput(
            QString str,
            bool addtostatus = false);

private slots:

    void on_bt_publish_clicked();

    void on_bt_subscribe_clicked();

    void on_actionPreferences_triggered();
    void on_actionParticipant_triggered();



    void on_actionExit_triggered();

    void on_tableEndpoint_customContextMenuRequested(
            const QPoint& pos);

    void on_actionDelete_Enpoint_triggered();

    void on_tableEndpoint_clicked(
            const QModelIndex& index);

    void on_MainWindow_destroyed();

    void closeEvent(
            QCloseEvent* event);

    void on_actionAbout_triggered();

    void on_actionUser_Manual_triggered();

    void on_actionInteroperability_Troubleshooting_triggered();

public slots:

    void on_actionStart_triggered();

    void on_actionStop_triggered();

private:

    Ui::MainWindow* ui;
    ShapesDemo m_shapesDemo;
    UpdateThread* mp_writeThread;
    QStandardItemModel* m_pubsub;
    std::vector<SD_Endpoint> m_pubsub_pointers;
    int m_tableRow;
    void removeRow(
            int row);
};

#endif // MAINWINDOW_H
