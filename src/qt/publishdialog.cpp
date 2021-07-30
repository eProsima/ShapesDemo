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

#include <eprosimashapesdemo/qt/publishdialog.h>
#include "ui_publishdialog.h"
#include <eprosimashapesdemo/shapesdemo/ShapeInfo.h>
#include <eprosimashapesdemo/shapesdemo/ShapesDemo.h>
#include <eprosimashapesdemo/shapesdemo/ShapePublisher.h>

#include "fastrtps/utils/TimeConversion.h"
#include <fastdds/dds/publisher/qos/DataWriterQos.hpp>
#include <fastdds/dds/publisher/qos/PublisherQos.hpp>

#include <eprosimashapesdemo/qt/mainwindow.h>

PublishDialog::PublishDialog(
        ShapesDemo* psd,
        QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::PublishDialog)
    , mp_sd(psd)
    , mp_parent((MainWindow*)parent)
{
    setAttribute ( Qt::WA_DeleteOnClose, true );
    ui->setupUi(this);
}

PublishDialog::~PublishDialog()
{
    delete ui;
}

void PublishDialog::on_button_OkCancel_accepted()
{
    // Check the participant is created
    if (!this->mp_sd->init())
    {
        std::cerr << "Error initializing Participant when creating Publisher" << std::endl;
        return;
    }

    // Get Topic if exist or add one
    TopicDescription* topic_desc = this->mp_sd->getTopic(this->ui->combo_Shape->currentText().toUtf8().constData());
    Topic* topic = dynamic_cast<Topic*>(topic_desc);

    // Create ShapePublisher object with a Publisher and a DataWriter
    ShapePublisher* SP = new ShapePublisher(mp_parent, this->mp_sd->getParticipant(), topic);

    // Set shape type
    if (this->ui->combo_Shape->currentText() == QString("Square"))
    {
        SP->m_shape.m_type = SQUARE;
    }
    else if (this->ui->combo_Shape->currentText() == QString("Triangle"))
    {
        SP->m_shape.m_type = TRIANGLE;
    }
    else if (this->ui->combo_Shape->currentText() == QString("Circle"))
    {
        SP->m_shape.m_type = CIRCLE;
    }

    //ShapeAttributes
    setShapeAttributes(SP);

    //HISTORY
    SP->m_dw_qos.history().kind = eprosima::fastdds::dds::KEEP_LAST_HISTORY_QOS;
    SP->m_dw_qos.history().depth = this->ui->spin_HistoryQos->value();

    //RELIABILITY
    if (this->ui->checkBox_reliable->isChecked())
    {
        SP->m_dw_qos.reliability().kind = eprosima::fastdds::dds::RELIABLE_RELIABILITY_QOS;
    }
    else
    {
        SP->m_dw_qos.reliability().kind = eprosima::fastdds::dds::BEST_EFFORT_RELIABILITY_QOS;
    }

    //LIVELINESS
    QString lease_duration_value;
    if (this->ui->comboBox_liveliness->currentIndex() == 0)
    {
        SP->m_dw_qos.liveliness().kind = eprosima::fastdds::dds::AUTOMATIC_LIVELINESS_QOS;
    }
    if (this->ui->comboBox_liveliness->currentIndex() == 1)
    {
        SP->m_dw_qos.liveliness().kind = eprosima::fastdds::dds::MANUAL_BY_PARTICIPANT_LIVELINESS_QOS;
    }
    if (this->ui->comboBox_liveliness->currentIndex() == 2)
    {
        SP->m_dw_qos.liveliness().kind = eprosima::fastdds::dds::MANUAL_BY_TOPIC_LIVELINESS_QOS;
    }

    if (this->ui->lineEdit_leaseDuration->text() == "INF")
    {
        SP->m_dw_qos.liveliness().lease_duration = c_TimeInfinite;
    }
    else
    {
        lease_duration_value = this->ui->lineEdit_leaseDuration->text();
        if (lease_duration_value.toDouble() > 0)
        {
            SP->m_dw_qos.liveliness().lease_duration = rtps::TimeConv::MilliSeconds2Time_t(
                lease_duration_value.toDouble()).to_duration_t();
        }
    }

    if (this->ui->lineEdit_announcementPeriod->text() == "INF" &&
            SP->m_dw_qos.liveliness().lease_duration == c_TimeInfinite)
    {
        SP->m_dw_qos.liveliness().announcement_period = c_TimeInfinite;
    }
    else if (this->ui->lineEdit_announcementPeriod->text() == "INF" &&
            SP->m_dw_qos.liveliness().lease_duration != c_TimeInfinite)
    {
        SP->m_dw_qos.liveliness().announcement_period = rtps::TimeConv::MilliSeconds2Time_t(
            lease_duration_value.toDouble() * 0.1).to_duration_t();
    }
    else
    {
        QString value = this->ui->lineEdit_announcementPeriod->text();
        if (value.toDouble() > 0)
        {
            SP->m_dw_qos.liveliness().announcement_period =
                    rtps::TimeConv::MilliSeconds2Time_t(value.toDouble()).to_duration_t();
        }
    }

    //DURABILITY
    switch (this->ui->comboBox_durability->currentIndex())
    {
        case 0: SP->m_dw_qos.durability().kind = eprosima::fastdds::dds::VOLATILE_DURABILITY_QOS; break;
        case 1: SP->m_dw_qos.durability().kind = eprosima::fastdds::dds::TRANSIENT_LOCAL_DURABILITY_QOS; break;
    }

    //Ownership:
    switch (this->ui->comboBox_ownership->currentIndex())
    {
        case 0: SP->m_dw_qos.ownership().kind = eprosima::fastdds::dds::SHARED_OWNERSHIP_QOS; break;
        case 1: SP->m_dw_qos.ownership().kind = eprosima::fastdds::dds::EXCLUSIVE_OWNERSHIP_QOS; break;
    }
    if (SP->m_dw_qos.ownership().kind == eprosima::fastdds::dds::EXCLUSIVE_OWNERSHIP_QOS)
    {
        SP->m_dw_qos.ownership_strength().value = this->ui->spin_ownershipStrength->value();
    }

    //DEADLINE
    if (this->ui->lineEdit_Deadline->text() == "INF")
    {
        SP->m_dw_qos.deadline().period = c_TimeInfinite;
    }
    else
    {
        QString value = this->ui->lineEdit_Deadline->text();
        if (value.toDouble() > 0)
        {
            SP->m_dw_qos.deadline().period = rtps::TimeConv::MilliSeconds2Time_t(value.toDouble()).to_duration_t();
        }
    }

    //LIFESPAN
    if (this->ui->lineEdit_Lifespan->text() == "INF")
    {
        SP->m_dw_qos.lifespan().duration = c_TimeInfinite;
    }
    else
    {
        QString value = this->ui->lineEdit_Lifespan->text();
        if (value.toDouble() > 0)
        {
            SP->m_dw_qos.lifespan().duration = rtps::TimeConv::MilliSeconds2Time_t(value.toDouble()).to_duration_t();
        }
    }

    //PARTITIONS
    if (this->ui->checkBox_Asterisk->isChecked())
    {
        SP->m_pub_qos.partition().push_back("*");
    }
    if (this->ui->checkBox_A->isChecked())
    {
        SP->m_pub_qos.partition().push_back("A");
    }
    if (this->ui->checkBox_B->isChecked())
    {
        SP->m_pub_qos.partition().push_back("B");
    }
    if (this->ui->checkBox_C->isChecked())
    {
        SP->m_pub_qos.partition().push_back("C");
    }
    if (this->ui->checkBox_D->isChecked())
    {
        SP->m_pub_qos.partition().push_back("D");
    }

    // Data Sharing
    if (this->mp_sd->data_sharing_enable())
    {
        SP->m_dw_qos.data_sharing().automatic();
    }
    else
    {
        SP->m_dw_qos.data_sharing().off();
    }

    // Create Publisher
    if (SP->initPublisher())
    {
        this->mp_sd->addPublisher(SP);
    }
}

void PublishDialog::setShapeAttributes(
        ShapePublisher* SP)
{
    //COLOR:
    if (this->ui->combo_Color->currentText() == QString("PURPLE"))
    {
        SP->m_shape.define(SD_PURPLE);
    }
    else if (this->ui->combo_Color->currentText() == QString("BLUE"))
    {
        SP->m_shape.define(SD_BLUE);
    }
    else if (this->ui->combo_Color->currentText() == QString("RED"))
    {
        SP->m_shape.define(SD_RED);
    }
    else if (this->ui->combo_Color->currentText() == QString("GREEN"))
    {
        SP->m_shape.define(SD_GREEN);
    }
    else if (this->ui->combo_Color->currentText() == QString("YELLOW"))
    {
        SP->m_shape.define(SD_YELLOW);
    }
    else if (this->ui->combo_Color->currentText() == QString("CYAN"))
    {
        SP->m_shape.define(SD_CYAN);
    }
    else if (this->ui->combo_Color->currentText() == QString("MAGENTA"))
    {
        SP->m_shape.define(SD_MAGENTA);
    }
    else if (this->ui->combo_Color->currentText() == QString("ORANGE"))
    {
        SP->m_shape.define(SD_ORANGE);
    }
    else if (this->ui->combo_Color->currentText() == QString("GRAY"))
    {
        SP->m_shape.define(SD_GRAY);
    }
    else if (this->ui->combo_Color->currentText() == QString("BLACK"))
    {
        SP->m_shape.define(SD_BLACK);
    }
    //SIZE:
    SP->m_shape.m_shape.shapesize(this->ui->spin_Size->value());
    //POSITION IS RANDOM:
    SP->m_shape.m_shape.x(this->mp_sd->getRandomX(SP->m_shape.m_shape.shapesize()));
    SP->m_shape.m_shape.y(this->mp_sd->getRandomY(SP->m_shape.m_shape.shapesize()));

}

void PublishDialog::on_comboBox_ownership_currentIndexChanged(
        int index)
{
    if (index == 1)
    {
        this->ui->checkBox_reliable->setChecked(true);
    }
}

void PublishDialog::on_comboBox_liveliness_currentIndexChanged(
        int index)
{
    switch (index)
    {
        case 2: this->ui->lineEdit_announcementPeriod->setEnabled(false); break;
        default: this->ui->lineEdit_announcementPeriod->setEnabled(true); break;
    }
}
