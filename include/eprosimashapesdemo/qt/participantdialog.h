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

#ifndef PARTICIPANTDIALOG_H
#define PARTICIPANTDIALOG_H

#include <QDialog>

namespace Ui {
class ParticipantDialog;
} // namespace Ui

class ShapesDemoOptions;
class ShapesDemo;
class MainWindow;

class ParticipantDialog : public QDialog
{
    Q_OBJECT

public:

    explicit ParticipantDialog(
            MainWindow* mw,
            ShapesDemo* psd,
            QWidget* parent = 0);
    ~ParticipantDialog();

private slots:

    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
    void on_spin_domainId_valueChanged(
            int arg1);
    void on_spin_server_port_valueChanged(
            int arg1);
    void on_spin_listen_port_valueChanged(
            int arg1);
    void on_lineEdit_server_ip_textChanged(
            const QString& arg1);

    void on_statisticsCheckBox_stateChanged(
            int arg1);

    void on_rosTopicCheckBox_stateChanged(
            int arg1);

    void on_IntraprocesscheckBox_stateChanged(
            int arg1);

    void on_DataSharingcheckBox_stateChanged(
            int arg1);

    void on_SHMcheckBox_stateChanged(
            int arg1);

    void on_UDPcheckBox_stateChanged(
            int arg1);

    void on_TCPcheckBox_stateChanged(
            int arg1);

    void on_TCPcomboBox_currentTextChanged(
            const QString& arg1);

    void tcp_enable_buttons();

private:

    ShapesDemoOptions* m_options;
    Ui::ParticipantDialog* ui;
    ShapesDemo* mp_sd;
    MainWindow* mp_mw;
    bool mb_started;

    void setEnableState();
};

#endif // PARTICIPANTDIALOG_H
