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

#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

namespace Ui {
class OptionsDialog;
}

class ShapesDemoOptions;
class ShapesDemo;
class MainWindow;

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsDialog(MainWindow* mw,ShapesDemo* psd,QWidget *parent = 0);
    ~OptionsDialog();

private slots:
    void on_OptionsDialog_accepted();

    void on_pushButton_udp_clicked();
    void on_pushButton_tcp_client_clicked();
    void on_pushButton_tcp_server_clicked();
    void on_pushButton_tcp_WAN_server_clicked();
    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
    void on_spin_domainId_valueChanged(int arg1);
    void on_spin_server_port_valueChanged(int arg1);
    void on_spin_listen_port_valueChanged(int arg1);
    void on_lineEdit_server_ip_textChanged(const QString& arg1);
    void on_spin_updateInterval_valueChanged(int arg1);
    void on_horizontalSlider_speed_valueChanged(int arg1);
    void on_statisticsCheckBox_stateChanged(int arg1);

private:
    ShapesDemoOptions* m_options;
    Ui::OptionsDialog *ui;
    ShapesDemo* mp_sd;
    MainWindow* mp_mw;
    bool mb_started;

    void setEnableState();

    void UpdateTransportControls();
};

#endif // OPTIONSDIALOG_H
