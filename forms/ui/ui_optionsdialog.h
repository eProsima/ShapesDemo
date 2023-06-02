/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:

    QGridLayout* gridLayout;
    QDialogButtonBox* buttonBox;
    QLabel* listeningPort_label;
    QSpinBox* spin_updateInterval;
    QPushButton* pushButton_udp;
    QSlider* horizontalSlider_speed;
    QLabel* label_5;
    QSpinBox* spin_listen_port;
    QPushButton* pushButton_tcp_client;
    QPushButton* pushButton_tcp_server;
    QSpinBox* spin_server_port;
    QLabel* serverIP_label;
    QLabel* label_3;
    QLineEdit* lineEdit_server_ip;
    QLabel* serverPort_label;
    QPushButton* pushButton_tcp_WAN_server;
    QLabel* label_2;
    QLabel* label_4;
    QFrame* line_2;
    QComboBox* comboBox;
    QFrame* line;
    QLabel* label_9;
    QFrame* line_3;
    QCheckBox* statisticsCheckBox;
    QFrame* line_5;
    QLabel* label_12;
    QCheckBox* rosTopicCheckBox;
    QSpinBox* spin_domainId;
    QPushButton* pushButton_start;
    QPushButton* pushButton_stop;
    QLabel* label_10;

    void setupUi(
            QDialog* OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
        {
            OptionsDialog->setObjectName(QString::fromUtf8("OptionsDialog"));
        }
        OptionsDialog->resize(467, 335);
        gridLayout = new QGridLayout(OptionsDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(OptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 15, 3, 1, 2);

        listeningPort_label = new QLabel(OptionsDialog);
        listeningPort_label->setObjectName(QString::fromUtf8("listeningPort_label"));

        gridLayout->addWidget(listeningPort_label, 2, 3, 1, 1);

        spin_updateInterval = new QSpinBox(OptionsDialog);
        spin_updateInterval->setObjectName(QString::fromUtf8("spin_updateInterval"));
        spin_updateInterval->setMinimum(50);
        spin_updateInterval->setMaximum(10000);
        spin_updateInterval->setValue(75);

        gridLayout->addWidget(spin_updateInterval, 13, 3, 1, 1);

        pushButton_udp = new QPushButton(OptionsDialog);
        pushButton_udp->setObjectName(QString::fromUtf8("pushButton_udp"));
        pushButton_udp->setEnabled(true);
        pushButton_udp->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_udp, 1, 2, 1, 1);

        horizontalSlider_speed = new QSlider(OptionsDialog);
        horizontalSlider_speed->setObjectName(QString::fromUtf8("horizontalSlider_speed"));
        horizontalSlider_speed->setMinimum(0);
        horizontalSlider_speed->setMaximum(25);
        horizontalSlider_speed->setValue(5);
        horizontalSlider_speed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_speed, 14, 2, 1, 3);

        label_5 = new QLabel(OptionsDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        spin_listen_port = new QSpinBox(OptionsDialog);
        spin_listen_port->setObjectName(QString::fromUtf8("spin_listen_port"));
        spin_listen_port->setMaximum(65535);
        spin_listen_port->setValue(80);

        gridLayout->addWidget(spin_listen_port, 2, 4, 1, 1);

        pushButton_tcp_client = new QPushButton(OptionsDialog);
        pushButton_tcp_client->setObjectName(QString::fromUtf8("pushButton_tcp_client"));
        pushButton_tcp_client->setEnabled(true);
        pushButton_tcp_client->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_tcp_client, 4, 2, 1, 1);

        pushButton_tcp_server = new QPushButton(OptionsDialog);
        pushButton_tcp_server->setObjectName(QString::fromUtf8("pushButton_tcp_server"));
        pushButton_tcp_server->setEnabled(true);
        pushButton_tcp_server->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_tcp_server, 2, 2, 1, 1);

        spin_server_port = new QSpinBox(OptionsDialog);
        spin_server_port->setObjectName(QString::fromUtf8("spin_server_port"));
        spin_server_port->setMaximum(65535);
        spin_server_port->setValue(80);

        gridLayout->addWidget(spin_server_port, 4, 4, 1, 1);

        serverIP_label = new QLabel(OptionsDialog);
        serverIP_label->setObjectName(QString::fromUtf8("serverIP_label"));

        gridLayout->addWidget(serverIP_label, 3, 3, 1, 1);

        label_3 = new QLabel(OptionsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 14, 0, 1, 1);

        lineEdit_server_ip = new QLineEdit(OptionsDialog);
        lineEdit_server_ip->setObjectName(QString::fromUtf8("lineEdit_server_ip"));

        gridLayout->addWidget(lineEdit_server_ip, 3, 4, 1, 1);

        serverPort_label = new QLabel(OptionsDialog);
        serverPort_label->setObjectName(QString::fromUtf8("serverPort_label"));

        gridLayout->addWidget(serverPort_label, 4, 3, 1, 1);

        pushButton_tcp_WAN_server = new QPushButton(OptionsDialog);
        pushButton_tcp_WAN_server->setObjectName(QString::fromUtf8("pushButton_tcp_WAN_server"));
        pushButton_tcp_WAN_server->setEnabled(true);
        pushButton_tcp_WAN_server->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_tcp_WAN_server, 3, 2, 1, 1);

        label_2 = new QLabel(OptionsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 13, 0, 1, 2);

        label_4 = new QLabel(OptionsDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 9, 0, 1, 1);

        line_2 = new QFrame(OptionsDialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 8, 0, 1, 1);

        comboBox = new QComboBox(OptionsDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 15, 0, 1, 1);

        line = new QFrame(OptionsDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 5, 0, 1, 1);

        label_9 = new QLabel(OptionsDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 12, 0, 1, 1);

        line_3 = new QFrame(OptionsDialog);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 11, 0, 1, 1);

        statisticsCheckBox = new QCheckBox(OptionsDialog);
        statisticsCheckBox->setObjectName(QString::fromUtf8("statisticsCheckBox"));

        gridLayout->addWidget(statisticsCheckBox, 9, 2, 1, 1);

#ifdef ENABLE_ROS_COMPONENTS
        line_5 = new QFrame(OptionsDialog);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 11, 0, 1, 1);

        label_12 = new QLabel(OptionsDialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        gridLayout->addWidget(label_4, 9, 0, 1, 1);

        rosTopicCheckBox = new QCheckBox(OptionsDialog);
        rosTopicCheckBox->setObjectName(QString::fromUtf8("rosTopicCheckBox"));

        gridLayout->addWidget(rosTopicCheckBox, 9, 2, 1, 1);
#endif

        spin_domainId = new QSpinBox(OptionsDialog);
        spin_domainId->setObjectName(QString::fromUtf8("spin_domainId"));
        spin_domainId->setValue(80);

        gridLayout->addWidget(spin_domainId, 6, 2, 1, 1);

        pushButton_start = new QPushButton(OptionsDialog);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_start, 6, 3, 1, 1);

        pushButton_stop = new QPushButton(OptionsDialog);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_stop, 6, 4, 1, 1);

        label_10 = new QLabel(OptionsDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        QWidget::setTabOrder(pushButton_udp, pushButton_tcp_server);
        QWidget::setTabOrder(pushButton_tcp_server, pushButton_tcp_WAN_server);
        QWidget::setTabOrder(pushButton_tcp_WAN_server, pushButton_tcp_client);
        QWidget::setTabOrder(pushButton_tcp_client, spin_listen_port);
        QWidget::setTabOrder(spin_listen_port, lineEdit_server_ip);
        QWidget::setTabOrder(lineEdit_server_ip, spin_server_port);
        QWidget::setTabOrder(spin_server_port, spin_updateInterval);
        QWidget::setTabOrder(spin_updateInterval, horizontalSlider_speed);

        retranslateUi(OptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(
            QDialog* OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "Options", nullptr));
        listeningPort_label->setText(QApplication::translate("OptionsDialog", "Listen Port:", nullptr));
        spin_updateInterval->setSpecialValueText(QString());
        spin_updateInterval->setSuffix(QString());
        pushButton_udp->setText(QApplication::translate("OptionsDialog", "UDP", nullptr));
        label_5->setText(QApplication::translate("OptionsDialog", "Domain", nullptr));
        spin_listen_port->setSpecialValueText(QString());
        spin_listen_port->setSuffix(QString());
        pushButton_tcp_client->setText(QApplication::translate("OptionsDialog", "TCP Client", nullptr));
        pushButton_tcp_server->setText(QApplication::translate("OptionsDialog", "TCP LAN Server", nullptr));
        spin_server_port->setSpecialValueText(QString());
        spin_server_port->setSuffix(QString());
        serverIP_label->setText(QApplication::translate("OptionsDialog", "Server IP:", nullptr));
        label_3->setText(QApplication::translate("OptionsDialog", "Speed:", nullptr));
        serverPort_label->setText(QApplication::translate("OptionsDialog", "Server Port:", nullptr));
        pushButton_tcp_WAN_server->setText(QApplication::translate("OptionsDialog", "TCP WAN Server", nullptr));
        label_2->setText(QApplication::translate("OptionsDialog", "Update interval (ms):", nullptr));
        label_4->setText(QApplication::translate("OptionsDialog", "Statistics", nullptr));
        label_9->setText(QApplication::translate("OptionsDialog", "Shape Movements", nullptr));
        statisticsCheckBox->setText(QApplication::translate("OptionsDialog", "Active Statistics", nullptr));
        rosTopicCheckBox->setText(QApplication::translate("OptionsDialog", "Use ROS 2 Topics", nullptr));

        spin_domainId->setSpecialValueText(QString());
        spin_domainId->setSuffix(QString());
        pushButton_start->setText(QApplication::translate("OptionsDialog", "Start", nullptr));
        pushButton_stop->setText(QApplication::translate("OptionsDialog", "Stop", nullptr));
        label_10->setText(QApplication::translate("OptionsDialog", "Transport", nullptr));
    } // retranslateUi

};

namespace Ui {
class OptionsDialog : public Ui_OptionsDialog
{
};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
