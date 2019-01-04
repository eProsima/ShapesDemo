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

OptionsDialog::OptionsDialog(MainWindow *mw, ShapesDemo* psd, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsDialog),
    mp_sd(psd),
    mp_mw(mw),
    mb_started(true)
{
    ui->setupUi(this);
    m_options = new ShapesDemoOptions(this->mp_sd->getOptions());
    this->ui->spin_domainId->setValue(m_options->m_domainId);
    if (mp_sd->isInitialized())
    {
        this->ui->spin_domainId->setEnabled(false);
    }
    this->ui->spin_updateInterval->setValue(m_options->m_updateIntervalMs);
    this->ui->horizontalSlider_speed->setValue(m_options->m_movementSpeed);
    this->ui->spin_server_port->setValue(m_options->m_serverPort);
    this->ui->spin_listen_port->setValue(m_options->m_listenPort);
    this->ui->lineEdit_server_ip->setText(QString::fromStdString(m_options->m_serverIp));
	this->ui->lineEdit_wam_ip->setText(QString::fromStdString(m_options->m_WANIp));

    setEnableState();
    UpdateTransportControls();
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

    UpdateTransportControls();

    this->ui->pushButton_start->setEnabled(mb_started);
    this->ui->spin_domainId->setEnabled(mb_started);
    this->ui->pushButton_stop->setEnabled(!mb_started);
}

void OptionsDialog::on_OptionsDialog_accepted()
{
}

void OptionsDialog::on_pushButton_udp_clicked()
{
    m_options->m_udpTransport = true;
    mp_sd->setOptions(*m_options);

    UpdateTransportControls();
}

void OptionsDialog::on_pushButton_tcp_client_clicked()
{
    m_options->m_tcpServer = false;
    m_options->m_udpTransport = false;
    mp_sd->setOptions(*m_options);

    UpdateTransportControls();
}

void OptionsDialog::on_pushButton_tcp_server_clicked()
{
    m_options->m_tcpServer = true;
    m_options->m_udpTransport = false;
    mp_sd->setOptions(*m_options);

    UpdateTransportControls();
}

void OptionsDialog::on_pushButton_start_clicked()
{
    this->mp_mw->on_actionStart_triggered();
    setEnableState();
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

void OptionsDialog::on_lineEdit_wam_ip_textChanged(const QString& arg)
{
	m_options->m_WANIp = arg.toStdString();
	mp_sd->setOptions(*m_options);
}

void OptionsDialog::UpdateTransportControls()
{
    this->ui->pushButton_tcp_client->setEnabled(mb_started && (m_options->m_udpTransport || m_options->m_tcpServer));
    this->ui->spin_server_port->setEnabled(mb_started && !m_options->m_udpTransport && !m_options->m_tcpServer);
    this->ui->lineEdit_server_ip->setEnabled(mb_started && !m_options->m_udpTransport && !m_options->m_tcpServer);
	this->ui->lineEdit_wam_ip->setEnabled(mb_started && !m_options->m_udpTransport && !m_options->m_tcpServer);
	
    this->ui->pushButton_tcp_server->setEnabled(mb_started && (m_options->m_udpTransport || !m_options->m_tcpServer));
    this->ui->spin_listen_port->setEnabled(mb_started && !m_options->m_udpTransport && m_options->m_tcpServer);
    this->ui->pushButton_udp->setEnabled(mb_started && !m_options->m_udpTransport);
}