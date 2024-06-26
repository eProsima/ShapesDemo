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

#include <fastdds/config.hpp> // FASTDDS_STATISTICS availability

#include "eprosimashapesdemo/qt/participantdialog.h"
#include "ui_participantdialog.h"
#include "eprosimashapesdemo/shapesdemo/ShapesDemo.h"
#include "eprosimashapesdemo/qt/mainwindow.h"

ParticipantDialog::ParticipantDialog(
        MainWindow* mw,
        ShapesDemo* psd,
        QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ParticipantDialog)
    , mp_sd(psd)
    , mp_mw(mw)
    , mb_started(true)
{
    ui->setupUi(this);
    m_options = new ShapesDemoOptions(this->mp_sd->getOptions());

    // Domain ID Configuration
    this->ui->spin_domainId->setValue(m_options->m_domainId);

    // TCP Configuration
    this->ui->spin_server_port->setValue(m_options->m_serverPort);
    this->ui->spin_listen_port->setValue(m_options->m_listenPort);
    this->ui->lineEdit_server_ip->setText(QString::fromStdString(m_options->m_serverIp));

    // Transport Configurations
    this->ui->IntraprocesscheckBox->setChecked(m_options->m_intraprocess_transport);
    this->ui->SHMcheckBox->setChecked(m_options->m_shm_transport);
    this->ui->UDPcheckBox->setChecked(m_options->m_udp_transport);
    this->ui->TCPcheckBox->setChecked(m_options->m_tcp_transport);

    // Statistics Button
    // Show if it is checked or not
    this->ui->statisticsCheckBox->setChecked(m_options->m_statistics);
    this->ui->monitorServiceCheckBox->setChecked(m_options->m_monitor_service);
#ifdef ENABLE_ROS_COMPONENTS
    this->ui->rosTopicCheckBox->setChecked(m_options->m_ros2_topic);
#else
    this->ui->line_5->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->rosTopicCheckBox->setVisible(false);
#endif // ifdef ENABLE_ROS_COMPONENTS

    this->ui->typeinformationCheckBox->setChecked(m_options->m_auto_fill_type_information);

    // Percentage loss Configuration
    this->ui->lossSpin->setValue(m_options->m_lossPerc);

    setEnableState();
    setAttribute ( Qt::WA_DeleteOnClose, true );
}

ParticipantDialog::~ParticipantDialog()
{
    delete m_options;
    delete ui;
}

void ParticipantDialog::setEnableState()
{
    if (this->mp_sd->isInitialized())
    {
        mb_started = false;
    }
    else
    {
        mb_started = true;
    }

    // Enable in Stop
    this->ui->pushButton_start->setEnabled(mb_started);
    this->ui->spin_domainId->setEnabled(mb_started);
    this->ui->statisticsCheckBox->setEnabled(mb_started);
    this->ui->monitorServiceCheckBox->setEnabled(mb_started);
#ifdef ENABLE_ROS_COMPONENTS
    if (!detect_ros_2_installation())
    {
        this->ui->rosTopicCheckBox->setToolTip("Only available when a valid ROS 2 installation is detected");
        this->ui->rosTopicCheckBox->setDisabled(true);
    }
    else
    {
        this->ui->rosTopicCheckBox->setEnabled(mb_started);
    }
#endif // ifdef ENABLE_ROS_COMPONENTS
    this->ui->IntraprocesscheckBox->setEnabled(mb_started);
    this->ui->SHMcheckBox->setEnabled(mb_started);
    this->ui->UDPcheckBox->setEnabled(mb_started);
    this->ui->TCPcheckBox->setEnabled(mb_started);
    this->ui->typeinformationCheckBox->setEnabled(mb_started);
    this->ui->lossCheckBox->setEnabled(mb_started);
    this->ui->lossSpin->setEnabled(this->ui->lossCheckBox->isChecked());
    this->ui->label_7->setEnabled(this->ui->lossCheckBox->isChecked());

    // Enable in Running
    this->ui->pushButton_stop->setEnabled(!mb_started);

    // Disable statistics if the statistics Module is not compiled
#ifndef FASTDDS_STATISTICS
    this->ui->statisticsCheckBox->setEnabled(false);
#endif // #ifndef FASTDDS_STATISTICS

    // Transports enabled
    tcp_enable_buttons();
}

void ParticipantDialog::on_pushButton_start_clicked()
{
    this->mp_mw->on_actionStart_triggered();
    this->close();
}

void ParticipantDialog::on_pushButton_stop_clicked()
{
    this->mp_mw->on_actionStop_triggered();
    m_options->m_lossSampleEnabled = false;
    setEnableState();
}

void ParticipantDialog::on_spin_domainId_valueChanged(
        int arg1)
{
    m_options->m_domainId = arg1;
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::on_spin_server_port_valueChanged(
        int arg1)
{
    m_options->m_serverPort = arg1;
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::on_spin_listen_port_valueChanged(
        int arg1)
{
    m_options->m_listenPort = arg1;
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::on_lineEdit_server_ip_textChanged(
        const QString& arg1)
{
    m_options->m_serverIp = arg1.toStdString();
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::on_statisticsCheckBox_stateChanged(
        int arg1)
{
    m_options->m_statistics = arg1;
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::on_rosTopicCheckBox_stateChanged(
        int arg1)
{
    m_options->m_ros2_topic = arg1;
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::tcp_enable_buttons()
{
    // Enable Combo Box
    this->ui->TCPcomboBox->setEnabled(m_options->m_tcp_transport && mb_started);

    // Enable/Disable buttons depending on transport
    this->ui->spin_listen_port->setEnabled(m_options->m_tcp_transport && mb_started);
    this->ui->spin_server_port->setEnabled(m_options->m_tcp_transport && mb_started);
    this->ui->lineEdit_server_ip->setEnabled(m_options->m_tcp_transport && mb_started);

    // Enable/Disable labels depending on transport
    this->ui->listeningPort_label->setEnabled(m_options->m_tcp_transport && mb_started);
    this->ui->serverPort_label->setEnabled(m_options->m_tcp_transport && mb_started);
    this->ui->serverIP_label->setEnabled(m_options->m_tcp_transport && mb_started);

    if (QString("TCP LAN Server") == m_options->m_tcp_type)
    {
        this->ui->spin_server_port->setEnabled(false);
        this->ui->lineEdit_server_ip->setEnabled(false);
        this->ui->serverIP_label->setEnabled(false);
        this->ui->serverPort_label->setEnabled(false);
    }
    if (QString("TCP WAN Server") == m_options->m_tcp_type)
    {
        this->ui->spin_server_port->setEnabled(false);
        this->ui->serverPort_label->setEnabled(false);
    }
    if (QString("TCP Client") == m_options->m_tcp_type)
    {
        this->ui->spin_listen_port->setEnabled(false);
        this->ui->listeningPort_label->setEnabled(false);
    }

    this->ui->TCPcomboBox->setCurrentText(m_options->m_tcp_type);
}

void ParticipantDialog::on_IntraprocesscheckBox_stateChanged(
        int arg1)
{
    m_options->m_intraprocess_transport = arg1;
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::on_SHMcheckBox_stateChanged(
        int arg1)
{
    m_options->m_shm_transport = arg1;
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::on_UDPcheckBox_stateChanged(
        int arg1)
{
    m_options->m_udp_transport = arg1;
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::on_TCPcheckBox_stateChanged(
        int arg1)
{
    m_options->m_tcp_transport = arg1;
    mp_sd->setOptions(*m_options);

    tcp_enable_buttons();
}

void ParticipantDialog::on_TCPcomboBox_currentTextChanged(
        const QString& arg1)
{
    m_options->m_tcp_type = arg1;
    mp_sd->setOptions(*m_options);

    tcp_enable_buttons();
}

void ParticipantDialog::on_monitorServiceCheckBox_stateChanged(
        int arg1)
{
    m_options->m_monitor_service = arg1;
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::on_lossSpin_valueChanged(
        int arg1)
{
    m_options->m_lossPerc = arg1;
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::on_typeinformationCheckBox_stateChanged(
        int arg1)
{
    m_options->m_auto_fill_type_information = arg1;
    mp_sd->setOptions(*m_options);
}

void ParticipantDialog::on_lossCheckBox_stateChanged(
        int arg1)
{
    if (arg1)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("Enabling this modality results in sample loss! Do you want to continue?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int out_ = msgBox.exec();
        switch (out_){
            case QMessageBox::Ok:
            {
                // Transport Configurations
                this->ui->IntraprocesscheckBox->setEnabled(false);
                this->ui->SHMcheckBox->setEnabled(false);
                this->ui->UDPcheckBox->setEnabled(false);
                this->ui->TCPcheckBox->setEnabled(false);
                this->ui->IntraprocesscheckBox->setChecked(false);
                this->ui->SHMcheckBox->setChecked(false);
                this->ui->UDPcheckBox->setChecked(false);
                this->ui->TCPcheckBox->setChecked(false);
                m_options->m_intraprocess_transport = (false);
                m_options->m_shm_transport = (false);
                m_options->m_udp_transport = (false);
                m_options->m_tcp_transport = (false);

                this->ui->lossSpin->setEnabled(true);
                this->ui->label_7->setEnabled(true);
                m_options->m_lossSampleEnabled = true;
                mp_sd->setOptions(*m_options);
            }
            break;
            case QMessageBox::Cancel:
            {
                this->ui->lossCheckBox->setCheckState(Qt::Unchecked);
                m_options->m_lossSampleEnabled = false;
            }
            break;
            default:
                // should never be reached
                break;
        }
    }
    else
    {
        this->ui->IntraprocesscheckBox->setEnabled(true);
        this->ui->SHMcheckBox->setEnabled(true);
        this->ui->UDPcheckBox->setEnabled(true);
        this->ui->TCPcheckBox->setEnabled(true);
        this->ui->IntraprocesscheckBox->setChecked(true);
        this->ui->SHMcheckBox->setChecked(true);
        this->ui->UDPcheckBox->setChecked(true);
        this->ui->TCPcheckBox->setChecked(false);
        m_options->m_intraprocess_transport = (true);
        m_options->m_shm_transport = (true);
        m_options->m_udp_transport = (true);
        m_options->m_tcp_transport = (false);

        this->ui->lossSpin->setEnabled(arg1);
        this->ui->label_7->setEnabled(arg1);
        m_options->m_lossSampleEnabled = false;
        mp_sd->setOptions(*m_options);
    }
}
