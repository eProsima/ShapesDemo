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

#include "eprosimashapesdemo/qt/optionsdialog.h"
#include "ui_optionsdialog.h"
#include "eprosimashapesdemo/shapesdemo/ShapesDemo.h"
#include "eprosimashapesdemo/qt/mainwindow.h"

#include <fastrtps/config.h> // FASTDDS_STATISTICS availability

OptionsDialog::OptionsDialog(MainWindow *mw, ShapesDemo* psd, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog),
    mp_sd(psd),
    mp_mw(mw),
    mb_started(true)
{
    ui->setupUi(this);
    m_options = new ShapesDemoOptions(this->mp_sd->getOptions());

    // Domain ID Configuration
    this->ui->spin_domainId->setValue(m_options->m_domainId);

    // Running Congiguration
    this->ui->spin_updateInterval->setValue(m_options->m_updateIntervalMs);
    this->ui->horizontalSlider_speed->setValue(m_options->m_movementSpeed);

    // TCP Configuration
    this->ui->spin_server_port->setValue(m_options->m_serverPort);
    this->ui->spin_listen_port->setValue(m_options->m_listenPort);
    this->ui->lineEdit_server_ip->setText(QString::fromStdString(m_options->m_serverIp));

    // Transport Configurations
    this->ui->IntraprocesscheckBox->setChecked(m_options->m_intraprocess_transport);
    this->ui->DataSharingcheckBox->setChecked(m_options->m_datasharing_transport);
    this->ui->SHMcheckBox->setChecked(m_options->m_shm_transport);
    this->ui->UDPcheckBox->setChecked(m_options->m_udp_transport);
    this->ui->TCPcheckBox->setChecked(m_options->m_tcp_transport);

    // Statistics Button
    // Show if it is checked or not
    this->ui->statisticsCheckBox->setChecked(m_options->m_statistics);

    setEnableState();
    setAttribute ( Qt::WA_DeleteOnClose, true );
}

OptionsDialog::~OptionsDialog()
{
    delete m_options;
    delete ui;
}

void OptionsDialog::setEnableState()
{
    if(this->mp_sd->isInitialized())
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
    this->ui->IntraprocesscheckBox->setEnabled(mb_started);
    this->ui->DataSharingcheckBox->setEnabled(mb_started);
    this->ui->SHMcheckBox->setEnabled(mb_started);
    this->ui->UDPcheckBox->setEnabled(mb_started);
    this->ui->TCPcheckBox->setEnabled(mb_started);

    // Enable in Running
    this->ui->pushButton_stop->setEnabled(!mb_started);

    // Disable statistics if the statistics Module is not compiled
#ifndef FASTDDS_STATISTICS
    this->ui->statisticsCheckBox->setEnabled(false);
#endif // #ifndef FASTDDS_STATISTICS

    // Transports enabled
    tcp_enable_buttons();
}

void OptionsDialog::on_OptionsDialog_accepted()
{
}

void OptionsDialog::on_pushButton_start_clicked()
{
    this->mp_mw->on_actionStart_triggered();
    this->close();
}

void OptionsDialog::on_pushButton_stop_clicked()
{
    this->mp_mw->on_actionStop_triggered();
    setEnableState();
}

void OptionsDialog::on_spin_updateInterval_valueChanged(int arg1)
{
    m_options->m_updateIntervalMs = arg1;
    mp_sd->setOptions(*m_options);
}

void OptionsDialog::on_horizontalSlider_speed_valueChanged(int arg1)
{
    m_options->m_movementSpeed = arg1;
    mp_sd->setOptions(*m_options);
}

void OptionsDialog::on_spin_domainId_valueChanged(int arg1)
{
    m_options->m_domainId = arg1;
    mp_sd->setOptions(*m_options);
}

void OptionsDialog::on_spin_server_port_valueChanged(int arg1)
{
    m_options->m_serverPort = arg1;
    mp_sd->setOptions(*m_options);
}

void OptionsDialog::on_spin_listen_port_valueChanged(int arg1)
{
    m_options->m_listenPort = arg1;
    mp_sd->setOptions(*m_options);
}

void OptionsDialog::on_lineEdit_server_ip_textChanged(const QString& arg1)
{
    m_options->m_serverIp = arg1.toStdString();
    mp_sd->setOptions(*m_options);
}

void OptionsDialog::on_statisticsCheckBox_stateChanged(int arg1)
{
    m_options->m_statistics = arg1;
    mp_sd->setOptions(*m_options);
}

void OptionsDialog::tcp_enable_buttons()
{
    // Enable Combo Box
    this->ui->TCPcomboBox->setEnabled(m_options->m_tcp_transport && mb_started);

    // Enable/Disable buttons depending on transport
    this->ui->spin_listen_port->setEnabled(m_options->m_tcp_transport && mb_started);
    this->ui->spin_server_port->setEnabled(m_options->m_tcp_transport && mb_started);
    this->ui->lineEdit_server_ip->setEnabled(m_options->m_tcp_transport && mb_started);

    if (QString("TCP LAN Server") == m_options->m_tcp_type)
    {
        this->ui->spin_server_port->setEnabled(false);
        this->ui->lineEdit_server_ip->setEnabled(false);
    }
    if (QString("TCP WAN Server") == m_options->m_tcp_type)
    {
        this->ui->spin_server_port->setEnabled(false);
    }
    if (QString("TCP Client") == m_options->m_tcp_type)
    {
        this->ui->spin_listen_port->setEnabled(false);
    }
}

void OptionsDialog::on_IntraprocesscheckBox_stateChanged(int arg1)
{
    m_options->m_intraprocess_transport = arg1;
    mp_sd->setOptions(*m_options);
}

void OptionsDialog::on_DataSharingcheckBox_stateChanged(int arg1)
{
    m_options->m_datasharing_transport = arg1;
    mp_sd->setOptions(*m_options);
}

void OptionsDialog::on_SHMcheckBox_stateChanged(int arg1)
{
    m_options->m_shm_transport = arg1;
    mp_sd->setOptions(*m_options);
    check_transports();
}

void OptionsDialog::on_UDPcheckBox_stateChanged(int arg1)
{
    m_options->m_udp_transport = arg1;
    mp_sd->setOptions(*m_options);
    check_transports();
}

void OptionsDialog::on_TCPcheckBox_stateChanged(int arg1)
{
    m_options->m_tcp_transport = arg1;
    mp_sd->setOptions(*m_options);

    tcp_enable_buttons();
    check_transports();
}

void OptionsDialog::on_TCPcomboBox_currentTextChanged(const QString &arg1)
{
    m_options->m_tcp_type = arg1;
    mp_sd->setOptions(*m_options);

    tcp_enable_buttons();
}

void OptionsDialog::check_transports()
{
    if (!m_options->m_tcp_transport && !m_options->m_udp_transport && !m_options->m_shm_transport)
    {
        this->ui->UDPcheckBox->setChecked(mb_started);
    }
}
