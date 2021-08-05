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

#ifndef PUBLISHDIALOG_H
#define PUBLISHDIALOG_H

#include <QDialog>


namespace Ui {
class PublishDialog;
} // namespace Ui

class ShapesDemo;
class ShapePublisher;
class MainWindow;

class PublishDialog : public QDialog
{
    Q_OBJECT

public:

    explicit PublishDialog(
            ShapesDemo* psd,
            QWidget* parent = 0);
    ~PublishDialog();

private slots:

    void on_button_OkCancel_accepted();

    void on_comboBox_ownership_currentIndexChanged(
            int index);
    void on_comboBox_liveliness_currentIndexChanged(
            int index);

private:

    Ui::PublishDialog* ui;
    ShapesDemo* mp_sd;

    void setShapeAttributes(
            ShapePublisher* SP);

    MainWindow* mp_parent;
};

#endif // PUBLISHDIALOG_H
