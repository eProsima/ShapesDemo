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

OptionsDialog::OptionsDialog(
        MainWindow* mw,
        ShapesDemo* psd,
        QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::OptionsDialog)
    , mp_sd(psd)
    , mp_mw(mw)
    , mb_started(true)
{
    ui->setupUi(this);
    m_options = new ShapesDemoOptions(this->mp_sd->getOptions());

    // Running Congiguration
    this->ui->spin_updateInterval->setValue(m_options->m_updateIntervalMs);
    this->ui->horizontalSlider_speed->setValue(m_options->m_movementSpeed);

    setAttribute ( Qt::WA_DeleteOnClose, true );
}

OptionsDialog::~OptionsDialog()
{
    delete m_options;
    delete ui;
}

void OptionsDialog::on_spin_updateInterval_valueChanged(
        int arg1)
{
    m_options->m_updateIntervalMs = arg1;
    mp_sd->setOptions(*m_options);
}

void OptionsDialog::on_horizontalSlider_speed_valueChanged(
        int arg1)
{
    m_options->m_movementSpeed = arg1;
    mp_sd->setOptions(*m_options);
}

void OptionsDialog::on_pushButton_stop_clicked()
{
    this->close();
}
