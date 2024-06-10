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

#include <eprosimashapesdemo/qt/publishdialog.h>
#include "ui_publishdialog.h"
#include <eprosimashapesdemo/shapesdemo/ShapeInfo.h>
#include <eprosimashapesdemo/shapesdemo/ShapesDemo.h>
#include <eprosimashapesdemo/shapesdemo/ShapePublisher.h>

#include <fastdds/dds/publisher/qos/DataWriterQos.hpp>
#include <fastdds/dds/publisher/qos/PublisherQos.hpp>
#include <fastdds/rtps/common/Time_t.h>

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
    this->ui->spin_ownershipStrength->setEnabled(false);
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
    TopicDescription* topic_desc;
    if (mp_sd->getOptions().m_ros2_topic)
    {
        std::string topicName("rt/");
        topicName.append(this->ui->combo_Shape->currentText().toUtf8().constData());
        topic_desc = this->mp_sd->getTopic(topicName);
    }
    else
    {
        topic_desc = this->mp_sd->getTopic(this->ui->combo_Shape->currentText().toUtf8().constData());
    }
    Topic* topic = dynamic_cast<Topic*>(topic_desc);

    // Create ShapePublisher object with a Publisher and a DataWriter
    ShapePublisher* SP = new ShapePublisher(mp_parent, this->mp_sd, topic);

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
            SP->m_dw_qos.liveliness().lease_duration =
                    eprosima::fastdds::Duration_t(lease_duration_value.toDouble() * 1e-3);
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
        SP->m_dw_qos.liveliness().announcement_period =
                eprosima::fastdds::Duration_t(lease_duration_value.toDouble() * 1e-3);
    }
    else
    {
        QString value = this->ui->lineEdit_announcementPeriod->text();
        if (value.toDouble() > 0)
        {
            SP->m_dw_qos.liveliness().announcement_period = eprosima::fastdds::Duration_t(value.toDouble() * 1e-3);
        }
    }

    //DURABILITY
    switch (this->ui->comboBox_durability->currentIndex())
    {
        case 0: SP->m_dw_qos.durability().kind = eprosima::fastdds::dds::VOLATILE_DURABILITY_QOS; break;
        case 1: SP->m_dw_qos.durability().kind = eprosima::fastdds::dds::TRANSIENT_LOCAL_DURABILITY_QOS; break;
    }

    //DATA REPRESENTATION
    switch (this->ui->comboBox_representation->currentIndex())
    {
        case 0:
        {
            SP->m_dw_qos.representation().m_value.push_back(eprosima::fastdds::dds::XCDR_DATA_REPRESENTATION);
            break;
        }
        case 1:
        {
            SP->m_dw_qos.representation().m_value.push_back(eprosima::fastdds::dds::XCDR2_DATA_REPRESENTATION);
            break;
        }
    }


    //OWNERSHIP:
    switch (this->ui->comboBox_ownership->currentIndex())
    {
        case 0: SP->m_dw_qos.ownership().kind = eprosima::fastdds::dds::SHARED_OWNERSHIP_QOS; break;
        case 1:
        {
            SP->m_dw_qos.ownership().kind = eprosima::fastdds::dds::EXCLUSIVE_OWNERSHIP_QOS;
            SP->m_dw_qos.ownership_strength().value = this->ui->spin_ownershipStrength->value();
            break;
        }
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
            SP->m_dw_qos.deadline().period = eprosima::fastdds::Duration_t(value.toDouble() * 1e-3);
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
            SP->m_dw_qos.lifespan().duration = eprosima::fastdds::Duration_t(value.toDouble() * 1e-3);
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
    switch (index)
    {
        case 0:
        {
            this->ui->spin_ownershipStrength->setEnabled(false);

            if (this->ui->spin_ownershipStrength->isEnabled())
            {
                this->ui->spin_ownershipStrength->setEnabled(false);
            }

            break;
        }
        case 1:
        {
            this->ui->checkBox_reliable->setChecked(true);

            if (!this->ui->spin_ownershipStrength->isEnabled())
            {
                this->ui->spin_ownershipStrength->setEnabled(true);
            }

            break;
        }
    }

    update();
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
