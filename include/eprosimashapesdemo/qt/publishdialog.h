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

#ifndef PUBLISHDIALOG_H
#define PUBLISHDIALOG_H

#include <QDialog>


namespace Ui {
class PublishDialog;
}

class ShapesDemo;
class ShapePublisher;
class MainWindow;

class PublishDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PublishDialog(ShapesDemo* psd,QWidget *parent = 0);
    ~PublishDialog();

private slots:

    void on_button_OkCancel_accepted();

    void on_comboBox_ownership_currentIndexChanged(int index);

private:
    Ui::PublishDialog *ui;
    ShapesDemo* mp_sd;

    void setShapeAttributes(ShapePublisher* SP);
    MainWindow* mp_parent;
};

#endif // PUBLISHDIALOG_H
