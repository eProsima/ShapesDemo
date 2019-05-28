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

#include <eprosimashapesdemo/qt/mainwindow.h>

PublishDialog::PublishDialog(ShapesDemo* psd,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PublishDialog),
    mp_sd(psd),
    mp_parent((MainWindow*)parent)
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
    ShapePublisher* SP = new ShapePublisher(mp_parent, this->mp_sd->getParticipant());
       //Get the different elements
    //ShapeAttributes
    setShapeAttributes(SP);

    //SHAPE/TOPIC:
    if(this->ui->combo_Shape->currentText() == QString("Square"))
    {
        SP->m_shape.m_type = SQUARE;
        SP->m_attributes.topic.topicName = "Square";
    }
    else if(this->ui->combo_Shape->currentText() == QString("Triangle"))
    {
        SP->m_shape.m_type = TRIANGLE;
        SP->m_attributes.topic.topicName = "Triangle";
    }
    else if(this->ui->combo_Shape->currentText() == QString("Circle"))
    {
        SP->m_shape.m_type = CIRCLE;
        SP->m_attributes.topic.topicName = "Circle";
    }
    SP->m_attributes.topic.topicDataType = "ShapeType";
    SP->m_attributes.topic.topicKind = rtps::WITH_KEY;

    //History:
    SP->m_attributes.topic.historyQos.kind = KEEP_LAST_HISTORY_QOS;
    SP->m_attributes.topic.historyQos.depth = this->ui->spin_HistoryQos->value();

    //Reliability
    if (this->ui->checkBox_reliable->isChecked())
    {
        SP->m_attributes.qos.m_reliability.kind = RELIABLE_RELIABILITY_QOS;
    }
    else
    {
        SP->m_attributes.qos.m_reliability.kind = BEST_EFFORT_RELIABILITY_QOS;
    }

    //LIVELINESS:
   // cout << "LIVELINESS "<<this->ui->comboBox_liveliness->currentIndex()<<endl;
   if(this->ui->comboBox_liveliness->currentIndex() == 0)
       SP->m_attributes.qos.m_liveliness.kind = AUTOMATIC_LIVELINESS_QOS;
   if(this->ui->comboBox_liveliness->currentIndex() == 1)
       SP->m_attributes.qos.m_liveliness.kind = MANUAL_BY_PARTICIPANT_LIVELINESS_QOS;
   if(this->ui->comboBox_liveliness->currentIndex() == 2)
       SP->m_attributes.qos.m_liveliness.kind = MANUAL_BY_TOPIC_LIVELINESS_QOS;
   if(this->ui->lineEdit_leaseDuration->text()=="INF")
       SP->m_attributes.qos.m_liveliness.lease_duration = c_TimeInfinite;
   else
   {
        QString value = this->ui->lineEdit_leaseDuration->text();
        if(value.toDouble()>0)
        {
            SP->m_attributes.qos.m_liveliness.lease_duration = rtps::TimeConv::MilliSeconds2Time_t(value.toDouble()).to_duration_t();
            SP->m_attributes.qos.m_liveliness.announcement_period =
                rtps::TimeConv::MilliSeconds2Time_t(value.toDouble()/2).to_duration_t();
        }
   }
   //DURABILITY
   //cout << "Durability INDEX: "<< this->ui->comboBox_durability->currentIndex() << endl;
   switch(this->ui->comboBox_durability->currentIndex())
   {
   case 0: SP->m_attributes.qos.m_durability.kind = VOLATILE_DURABILITY_QOS; break;
   case 1: SP->m_attributes.qos.m_durability.kind = TRANSIENT_LOCAL_DURABILITY_QOS; break;
   }
   //Ownership:
   switch(this->ui->comboBox_ownership->currentIndex())
   {
   case 0: SP->m_attributes.qos.m_ownership.kind = SHARED_OWNERSHIP_QOS; break;
   case 1: SP->m_attributes.qos.m_ownership.kind = EXCLUSIVE_OWNERSHIP_QOS; break;
   }
   if(SP->m_attributes.qos.m_ownership.kind == EXCLUSIVE_OWNERSHIP_QOS)
       SP->m_attributes.qos.m_ownershipStrength.value = this->ui->spin_ownershipStrength->value();
    // Deadline
    if(this->ui->lineEdit_Dead->text()=="INF")
    {
        SP->m_attributes.qos.m_deadline.period = c_TimeInfinite;
    }
    else
    {
        QString value = this->ui->lineEdit_Dead->text();
        if(value.toDouble()>0)
        {
            SP->m_attributes.qos.m_deadline.period = rtps::TimeConv::MilliSeconds2Time_t(value.toDouble()).to_duration_t();
        }
    }
    // Lifespan
    if(this->ui->lineEdit_Life->text()=="INF")
    {
        SP->m_attributes.qos.m_lifespan.duration = c_TimeInfinite;
    }
    else
    {
        QString value = this->ui->lineEdit_Life->text();
        if(value.toDouble()>0)
        {
            SP->m_attributes.qos.m_lifespan.duration = rtps::TimeConv::MilliSeconds2Time_t(value.toDouble()).to_duration_t();
        }
    }
    //PARTITIONS:
   if(this->ui->checkBox_Asterisk->isChecked())
       SP->m_attributes.qos.m_partition.push_back("*");
    if(this->ui->checkBox_A->isChecked())
        SP->m_attributes.qos.m_partition.push_back("A");
    if(this->ui->checkBox_B->isChecked())
        SP->m_attributes.qos.m_partition.push_back("B");
    if(this->ui->checkBox_C->isChecked())
        SP->m_attributes.qos.m_partition.push_back("C");
    if(this->ui->checkBox_D->isChecked())
        SP->m_attributes.qos.m_partition.push_back("D");



    if(SP->initPublisher())
     this->mp_sd->addPublisher(SP);



}

void PublishDialog::setShapeAttributes(ShapePublisher* SP)
{
    //COLOR:
    if(this->ui->combo_Color->currentText() == QString("PURPLE"))
        SP->m_shape.define(SD_PURPLE);
    else if(this->ui->combo_Color->currentText() == QString("BLUE"))
        SP->m_shape.define(SD_BLUE);
    else if(this->ui->combo_Color->currentText() == QString("RED"))
        SP->m_shape.define(SD_RED);
    else if(this->ui->combo_Color->currentText() == QString("GREEN"))
        SP->m_shape.define(SD_GREEN);
    else if(this->ui->combo_Color->currentText() == QString("YELLOW"))
        SP->m_shape.define(SD_YELLOW);
    else if(this->ui->combo_Color->currentText() == QString("CYAN"))
        SP->m_shape.define(SD_CYAN);
    else if(this->ui->combo_Color->currentText() == QString("MAGENTA"))
        SP->m_shape.define(SD_MAGENTA);
    else if(this->ui->combo_Color->currentText() == QString("ORANGE"))
        SP->m_shape.define(SD_ORANGE);
    else if(this->ui->combo_Color->currentText() == QString("GRAY"))
        SP->m_shape.define(SD_GRAY);
    else if(this->ui->combo_Color->currentText() == QString("BLACK"))
        SP->m_shape.define(SD_BLACK);
    //SIZE:
    SP->m_shape.m_shape.shapesize(this->ui->spin_Size->value());
    //POSITION IS RANDOM:
    SP->m_shape.m_shape.x(this->mp_sd->getRandomX(SP->m_shape.m_shape.shapesize()));
    SP->m_shape.m_shape.y(this->mp_sd->getRandomY(SP->m_shape.m_shape.shapesize()));

}

void PublishDialog::on_comboBox_ownership_currentIndexChanged(int index)
{
    if(index == 1)
    {
        this->ui->checkBox_reliable->setChecked(true);
    }
}
