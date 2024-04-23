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

#include <fastdds/config.h> // FASTDDS_STATISTICS availability

#include "eprosimashapesdemo/qt/optionsdialog.h"
#include "ui_optionsdialog.h"
#include "eprosimashapesdemo/shapesdemo/ShapesDemo.h"
#include "eprosimashapesdemo/qt/mainwindow.h"

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
