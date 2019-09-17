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


#include <QIntValidator>
#include <QMessageBox>

#include <eprosimashapesdemo/qt/mainwindow.h>

SubscribeDialog::SubscribeDialog(
        ShapesDemo* psd,
        QWidget *parent)
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
    ShapeSubscriber* SSub = new ShapeSubscriber((MainWindow*)mp_parent, this->mp_sd->getParticipant());

    //SHAPE/TOPIC:
    if (this->ui->combo_Shape->currentText() == QString("Square"))
    {
        SSub->m_shapeType = SQUARE;
        SSub->m_attributes.topic.topicName = "Square";
    }
    else if (this->ui->combo_Shape->currentText() == QString("Triangle"))
    {
        SSub->m_shapeType= TRIANGLE;
        SSub->m_attributes.topic.topicName = "Triangle";
    }
    else if (this->ui->combo_Shape->currentText() == QString("Circle"))
    {
        SSub->m_shapeType = CIRCLE;
        SSub->m_attributes.topic.topicName = "Circle";
    }
    SSub->m_attributes.topic.topicDataType = "ShapeType";
    SSub->m_attributes.topic.topicKind = rtps::WITH_KEY;

    //HISTORY
    SSub->m_attributes.expectsInlineQos = false;
    SSub->m_attributes.topic.historyQos.kind = KEEP_LAST_HISTORY_QOS;
    SSub->m_attributes.topic.historyQos.depth = this->ui->spin_HistoryQos->value();
    SSub->m_shapeHistory.m_history_depth = this->ui->spin_HistoryQos->value();

    SSub->m_attributes.qos.m_presentation.hasChanged = true;

    //RELIABILITY
    if (this->ui->checkBox_reliable->isChecked())
    {
        SSub->m_attributes.qos.m_reliability.kind = RELIABLE_RELIABILITY_QOS;
    }

    //DURABILITY
    switch (this->ui->comboBox_durability->currentIndex())
    {
        case 0: SSub->m_attributes.qos.m_durability.kind = VOLATILE_DURABILITY_QOS; break;
        case 1: SSub->m_attributes.qos.m_durability.kind = TRANSIENT_LOCAL_DURABILITY_QOS; break;
    }

    //LIVELINESS
    QString lease_duration_value;
    if (this->ui->comboBox_liveliness->currentIndex() == 0)
    {
       SSub->m_attributes.qos.m_liveliness.kind = AUTOMATIC_LIVELINESS_QOS;
    }
    if (this->ui->comboBox_liveliness->currentIndex() == 1)
    {
       SSub->m_attributes.qos.m_liveliness.kind = MANUAL_BY_PARTICIPANT_LIVELINESS_QOS;
    }
    if (this->ui->comboBox_liveliness->currentIndex() == 2)
    {
       SSub->m_attributes.qos.m_liveliness.kind = MANUAL_BY_TOPIC_LIVELINESS_QOS;
    }
    if (this->ui->lineEdit_leaseDuration->text()=="INF")
    {
       SSub->m_attributes.qos.m_liveliness.lease_duration = c_TimeInfinite;
    }
    else
    {
        lease_duration_value = this->ui->lineEdit_leaseDuration->text();
        if (lease_duration_value.toDouble()>0)
        {
            SSub->m_attributes.qos.m_liveliness.lease_duration = rtps::TimeConv::MilliSeconds2Time_t(lease_duration_value.toDouble()).to_duration_t();
        }
    }
    if (this->ui->lineEdit_announcementPeriod->text()=="INF" && SSub->m_attributes.qos.m_liveliness.lease_duration == c_TimeInfinite)
    {
        SSub->m_attributes.qos.m_liveliness.announcement_period = c_TimeInfinite;
    }
    else if (this->ui->lineEdit_announcementPeriod->text()=="INF" && SSub->m_attributes.qos.m_liveliness.lease_duration != c_TimeInfinite)
    {
        SSub->m_attributes.qos.m_liveliness.announcement_period = rtps::TimeConv::MilliSeconds2Time_t(lease_duration_value.toDouble()/2).to_duration_t();
    }
    else
    {
        QString value = this->ui->lineEdit_announcementPeriod->text();
        if (value.toDouble()>0)
        {
            SSub->m_attributes.qos.m_liveliness.announcement_period = rtps::TimeConv::MilliSeconds2Time_t(value.toDouble()).to_duration_t();
        }
    }

    //OWNERSHIP
    switch (this->ui->comboBox_ownership->currentIndex())
    {
        case 0: SSub->m_attributes.qos.m_ownership.kind = SHARED_OWNERSHIP_QOS; break;
        case 1:
        {
            SSub->m_attributes.qos.m_ownership.kind = EXCLUSIVE_OWNERSHIP_QOS;
            SSub->m_shapeHistory.m_isExclusiveOwnership = true;
            break;
        }
    }

    //DEADLINE
    if (this->ui->lineEdit_Deadline->text()=="INF")
    {
        SSub->m_attributes.qos.m_deadline.period = c_TimeInfinite;
    }
    else
    {
        QString value = this->ui->lineEdit_Deadline->text();
        if (value.toDouble()>0)
        {
            SSub->m_attributes.qos.m_deadline.period = rtps::TimeConv::MilliSeconds2Time_t(value.toDouble()).to_duration_t();
        }
    }

    //LIFESPAN
    if (this->ui->lineEdit_Lifespan->text()=="INF")
    {
        SSub->m_attributes.qos.m_lifespan.duration = c_TimeInfinite;
    }
    else
    {
        QString value = this->ui->lineEdit_Lifespan->text();
        if (value.toDouble()>0)
        {
            SSub->m_attributes.qos.m_lifespan.duration = rtps::TimeConv::MilliSeconds2Time_t(value.toDouble()).to_duration_t();
        }
    }

    //PARTITIONS
    if (this->ui->checkBox_Asterisk->isChecked())
    {
        SSub->m_attributes.qos.m_partition.push_back("*");
    }
    if (this->ui->checkBox_A->isChecked())
    {
        SSub->m_attributes.qos.m_partition.push_back("A");
    }
    if (this->ui->checkBox_B->isChecked())
    {
        SSub->m_attributes.qos.m_partition.push_back("B");
    }
    if (this->ui->checkBox_C->isChecked())
    {
        SSub->m_attributes.qos.m_partition.push_back("C");
    }
    if (this->ui->checkBox_D->isChecked())
    {
        SSub->m_attributes.qos.m_partition.push_back("D");
    }

    //TIME FILTER
    if (this->ui->checkBox_timeBasedFilter->isChecked())
    {
        SSub->m_shapeHistory.m_filter.m_useTimeFilter = true;
        if (this->ui->lineEdit_TimeBasedFilter->text()=="INF")
        {
            //pWarning("Setting TimeBasedFilter as Infinite should be avoided, putting 0 instead"<<endl);
            SSub->m_attributes.qos.m_timeBasedFilter.minimum_separation.seconds = 0;
        }
        else
        {
            QString value = this->ui->lineEdit_TimeBasedFilter->text();
            //cout << "TIME VALUE: "<< value.toStdString() << endl;
            if (value.toInt()>0)
            {
                SSub->m_attributes.qos.m_timeBasedFilter.minimum_separation =
                    rtps::TimeConv::MilliSeconds2Time_t(value.toInt()).to_duration_t();
            }

        }
        SSub->m_shapeHistory.m_filter.m_minimumSeparation = SSub->m_attributes.qos.m_timeBasedFilter.minimum_separation;
    }

    //CONTENT FILTER
    if (this->ui->checkBox_contentBasedFilter->isChecked())
    {
        SSub->m_shapeHistory.m_filter.m_useContentFilter = true;
    }
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
        if (this->ui->comboBox_ownership->currentIndex()==1)
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
