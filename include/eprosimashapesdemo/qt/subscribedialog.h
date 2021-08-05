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

#ifndef SUBSCRIBEDIALOG_H
#define SUBSCRIBEDIALOG_H

#include <QDialog>

namespace Ui {
class SubscribeDialog;
} // namespace Ui

class ShapesDemo;
class ShapeSubscriber;
class MainWindow;

class SubscribeDialog : public QDialog
{
    Q_OBJECT

public:

    explicit SubscribeDialog(
            ShapesDemo* psd,
            QWidget* parent = 0);

    ~SubscribeDialog();

private slots:

    void on_buttonBox_accepted();

    void on_comboBox_ownership_currentIndexChanged(
            int index);


    void on_checkBox_reliable_toggled(
            bool checked);

    void on_checkBox_timeBasedFilter_clicked(
            bool checked);

private:

    Ui::SubscribeDialog* ui;
    ShapesDemo* mp_sd;
    MainWindow* mp_parent;
};

#endif // SUBSCRIBEDIALOG_H
