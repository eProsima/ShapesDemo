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

#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>

namespace Ui {
class OptionsDialog;
} // namespace Ui

class ShapesDemoOptions;
class ShapesDemo;
class MainWindow;

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:

    explicit OptionsDialog(
            MainWindow* mw,
            ShapesDemo* psd,
            QWidget* parent = 0);
    ~OptionsDialog();

private slots:

    void on_spin_updateInterval_valueChanged(
            int arg1);
    void on_horizontalSlider_speed_valueChanged(
            int arg1);

    void on_pushButton_stop_clicked();

private:

    ShapesDemoOptions* m_options;
    Ui::OptionsDialog* ui;
    ShapesDemo* mp_sd;
    MainWindow* mp_mw;
    bool mb_started;

    void setEnableState();
};

#endif // OPTIONSDIALOG_H
