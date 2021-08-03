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

#include "eprosimashapesdemo/qt/subscribedialog.h"
#include "ui_subscribedialog.h"
#include "eprosimashapesdemo/shapesdemo/ShapesDemo.h"
#include "eprosimashapesdemo/shapesdemo/ShapeSubscriber.h"

#include "fastrtps/utils/TimeConversion.h"

#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/qos/SubscriberQos.hpp>

#include <QIntValidator>
#include <QMessageBox>

#include <eprosimashapesdemo/qt/mainwindow.h>

SubscribeDialog::SubscribeDialog(
        ShapesDemo* psd,
        QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::SubscribeDialog)
    , mp_sd(psd)
    , mp_parent((MainWindow*)parent)
{
    ui->setupUi(this);

    //    ui->lineEdit_maxX->setValidator(new QIntValidator(this));
    //    ui->lineEdit_maxY->setValidator(new QIntValidator(this));
    //    ui->lineEdit_minX->setValidator(new QIntValidator(this));
    //    ui->lineEdit_minY->setValidator(new QIntValidator(this));
    ui->lineEdit_TimeBasedFilter->setValidator(new QIntValidator(this));
    setAttribute ( Qt::WA_DeleteOnClose, true );
}

SubscribeDialog::~SubscribeDialog()
{
    delete ui;
}

void SubscribeDialog::on_buttonBox_accepted()
{
    // Check the participant is created
    if (!this->mp_sd->init())
    {
        std::cerr << "Error initializing Participant when creating Subscriber" << std::endl;
        return;
    }

    // Get Topic if exist or add one
    Topic* topic = this->mp_sd->getTopic(this->ui->combo_Shape->currentText().toUtf8().constData());

    ShapeSubscriber* SSub = new ShapeSubscriber((MainWindow*)mp_parent, this->mp_sd, topic);

    // Set shape type
    if (this->ui->combo_Shape->currentText() == QString("Square"))
    {
        SSub->m_shapeType = SQUARE;
    }
    else if (this->ui->combo_Shape->currentText() == QString("Triangle"))
    {
        SSub->m_shapeType = TRIANGLE;
    }
    else if (this->ui->combo_Shape->currentText() == QString("Circle"))
    {
        SSub->m_shapeType = CIRCLE;
    }

    //HISTORY
    SSub->m_dr_qos.expects_inline_qos(false);
    SSub->m_dr_qos.history().kind = eprosima::fastdds::dds::KEEP_LAST_HISTORY_QOS;
    SSub->m_dr_qos.history().depth = this->ui->spin_HistoryQos->value();
    SSub->m_shapeHistory.m_history_depth = this->ui->spin_HistoryQos->value();

    SSub->m_sub_qos.presentation().hasChanged = true; // Not implemented yet

    //RELIABILITY
    if (this->ui->checkBox_reliable->isChecked())
    {
        SSub->m_dr_qos.reliability().kind = eprosima::fastdds::dds::RELIABLE_RELIABILITY_QOS;
    }

    //DURABILITY
    switch (this->ui->comboBox_durability->currentIndex())
    {
        case 0: SSub->m_dr_qos.durability().kind = eprosima::fastdds::dds::VOLATILE_DURABILITY_QOS; break;
        case 1: SSub->m_dr_qos.durability().kind = eprosima::fastdds::dds::TRANSIENT_LOCAL_DURABILITY_QOS; break;
    }

    //LIVELINESS
    if (this->ui->comboBox_liveliness->currentIndex() == 0)
    {
        SSub->m_dr_qos.liveliness().kind = eprosima::fastdds::dds::AUTOMATIC_LIVELINESS_QOS;
    }
    if (this->ui->comboBox_liveliness->currentIndex() == 1)
    {
        SSub->m_dr_qos.liveliness().kind = eprosima::fastdds::dds::MANUAL_BY_PARTICIPANT_LIVELINESS_QOS;
    }
    if (this->ui->comboBox_liveliness->currentIndex() == 2)
    {
        SSub->m_dr_qos.liveliness().kind = eprosima::fastdds::dds::MANUAL_BY_TOPIC_LIVELINESS_QOS;
    }

    if (this->ui->lineEdit_leaseDuration->text() == "INF")
    {
        SSub->m_dr_qos.liveliness().lease_duration = c_TimeInfinite;
    }
    else
    {
        QString value = this->ui->lineEdit_leaseDuration->text();
        if (value.toDouble() > 0)
        {
            // Liveliness is retrieving by user in ms and is stored in s
            SSub->m_dr_qos.liveliness().lease_duration = eprosima::fastrtps::Duration_t(value.toDouble() * 1e-3);
        }
    }

    //OWNERSHIP
    switch (this->ui->comboBox_ownership->currentIndex())
    {
        case 0: SSub->m_dr_qos.ownership().kind = eprosima::fastdds::dds::SHARED_OWNERSHIP_QOS; break;
        case 1:
        {
            SSub->m_dr_qos.ownership().kind = eprosima::fastdds::dds::EXCLUSIVE_OWNERSHIP_QOS;
            SSub->m_shapeHistory.m_isExclusiveOwnership = true;
            break;
        }
    }

    //DEADLINE
    if (this->ui->lineEdit_Deadline->text() == "INF")
    {
        SSub->m_dr_qos.deadline().period = c_TimeInfinite;
    }
    else
    {
        QString value = this->ui->lineEdit_Deadline->text();
        if (value.toDouble() > 0)
        {
            SSub->m_dr_qos.deadline().period = eprosima::fastrtps::Duration_t(value.toDouble() * 1e-3);
        }
    }

    //LIFESPAN
    if (this->ui->lineEdit_Lifespan->text() == "INF")
    {
        SSub->m_dr_qos.lifespan().duration = c_TimeInfinite;
    }
    else
    {
        QString value = this->ui->lineEdit_Lifespan->text();
        if (value.toDouble() > 0)
        {
            SSub->m_dr_qos.lifespan().duration = eprosima::fastrtps::Duration_t(value.toDouble() * 1e-3);
        }
    }

    //PARTITIONS
    if (this->ui->checkBox_Asterisk->isChecked())
    {
        SSub->m_sub_qos.partition().push_back("*");
    }
    if (this->ui->checkBox_A->isChecked())
    {
        SSub->m_sub_qos.partition().push_back("A");
    }
    if (this->ui->checkBox_B->isChecked())
    {
        SSub->m_sub_qos.partition().push_back("B");
    }
    if (this->ui->checkBox_C->isChecked())
    {
        SSub->m_sub_qos.partition().push_back("C");
    }
    if (this->ui->checkBox_D->isChecked())
    {
        SSub->m_sub_qos.partition().push_back("D");
    }

    //TIME FILTER
    if (this->ui->checkBox_timeBasedFilter->isChecked())
    {
        SSub->m_shapeHistory.m_filter.m_useTimeFilter = true;
        if (this->ui->lineEdit_TimeBasedFilter->text() == "INF")
        {
            //pWarning("Setting TimeBasedFilter as Infinite should be avoided, putting 0 instead"<<endl);
            SSub->m_dr_qos.time_based_filter().minimum_separation.seconds = 0;
        }
        else
        {
            QString value = this->ui->lineEdit_TimeBasedFilter->text();
            //cout << "TIME VALUE: "<< value.toStdString() << endl;
            if (value.toInt() > 0)
            {
                SSub->m_dr_qos.time_based_filter().minimum_separation =
                    eprosima::fastrtps::Duration_t(value.toDouble() * 1e-3);
            }

        }
        SSub->m_shapeHistory.m_filter.m_minimumSeparation = SSub->m_dr_qos.time_based_filter().minimum_separation;
    }

    //CONTENT FILTER
    if (this->ui->checkBox_contentBasedFilter->isChecked())
    {
        SSub->m_shapeHistory.m_filter.m_useContentFilter = true;
    }

    // Data Sharing
    if (this->mp_sd->data_sharing_enable())
    {
        SSub->m_dr_qos.data_sharing().automatic();
    }
    else
    {
        SSub->m_dr_qos.data_sharing().off();
    }

    // Create Subscriber
    if (SSub->initSubscriber())
    {
        this->mp_sd->addSubscriber(SSub);
    }
}

void SubscribeDialog::on_comboBox_ownership_currentIndexChanged(
        int index)
{
    if (index == 1)
    {
        this->ui->checkBox_reliable->setChecked(true);
    }
}

void SubscribeDialog::on_checkBox_reliable_toggled(
        bool checked)
{
    if (!checked)
    {
        if (this->ui->comboBox_ownership->currentIndex() == 1)
        {
            QMessageBox msgBox;
            msgBox.setText("EXCLUSIVE OWNERSHIP only available with Reliable subscribers");
            msgBox.exec();
        }
        this->ui->comboBox_ownership->setCurrentIndex(0);
    }
}

void SubscribeDialog::on_checkBox_timeBasedFilter_clicked(
        bool checked)
{
    this->ui->lineEdit_TimeBasedFilter->setEnabled(checked);
}
