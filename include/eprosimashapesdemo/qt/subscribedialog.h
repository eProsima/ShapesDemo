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
