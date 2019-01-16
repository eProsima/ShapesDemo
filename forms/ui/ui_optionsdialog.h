/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_server_ip;
    QPushButton *pushButton_tcp_server_2;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_tcp_server;
    QSpinBox *spin_listen_port;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_udp;
    QSpinBox *spin_domainId;
    QPushButton *pushButton_start;
    QSlider *horizontalSlider_speed;
    QSpinBox *spin_server_port;
    QLabel *label_6;
    QPushButton *pushButton_tcp_client;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *spin_updateInterval;
    QLabel *label_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QString::fromUtf8("OptionsDialog"));
        OptionsDialog->resize(459, 326);
        gridLayout = new QGridLayout(OptionsDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(OptionsDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_server_ip = new QLineEdit(OptionsDialog);
        lineEdit_server_ip->setObjectName(QString::fromUtf8("lineEdit_server_ip"));

        gridLayout->addWidget(lineEdit_server_ip, 2, 4, 1, 1);

        pushButton_tcp_server_2 = new QPushButton(OptionsDialog);
        pushButton_tcp_server_2->setObjectName(QString::fromUtf8("pushButton_tcp_server_2"));
        pushButton_tcp_server_2->setEnabled(true);
        pushButton_tcp_server_2->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_tcp_server_2, 2, 2, 1, 1);

        label_2 = new QLabel(OptionsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 7, 0, 1, 2);

        label_3 = new QLabel(OptionsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 8, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        pushButton_tcp_server = new QPushButton(OptionsDialog);
        pushButton_tcp_server->setObjectName(QString::fromUtf8("pushButton_tcp_server"));
        pushButton_tcp_server->setEnabled(true);
        pushButton_tcp_server->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_tcp_server, 1, 2, 1, 1);

        spin_listen_port = new QSpinBox(OptionsDialog);
        spin_listen_port->setObjectName(QString::fromUtf8("spin_listen_port"));
        spin_listen_port->setMaximum(65535);
        spin_listen_port->setValue(80);

        gridLayout->addWidget(spin_listen_port, 1, 4, 1, 1);

        pushButton_stop = new QPushButton(OptionsDialog);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_stop, 4, 4, 1, 1);

        pushButton_udp = new QPushButton(OptionsDialog);
        pushButton_udp->setObjectName(QString::fromUtf8("pushButton_udp"));
        pushButton_udp->setEnabled(true);
        pushButton_udp->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_udp, 0, 2, 1, 1);

        spin_domainId = new QSpinBox(OptionsDialog);
        spin_domainId->setObjectName(QString::fromUtf8("spin_domainId"));
        spin_domainId->setValue(80);

        gridLayout->addWidget(spin_domainId, 4, 2, 1, 1);

        pushButton_start = new QPushButton(OptionsDialog);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_start, 4, 3, 1, 1);

        horizontalSlider_speed = new QSlider(OptionsDialog);
        horizontalSlider_speed->setObjectName(QString::fromUtf8("horizontalSlider_speed"));
        horizontalSlider_speed->setMinimum(0);
        horizontalSlider_speed->setMaximum(25);
        horizontalSlider_speed->setValue(5);
        horizontalSlider_speed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_speed, 8, 2, 1, 3);

        spin_server_port = new QSpinBox(OptionsDialog);
        spin_server_port->setObjectName(QString::fromUtf8("spin_server_port"));
        spin_server_port->setMaximum(65535);
        spin_server_port->setValue(80);

        gridLayout->addWidget(spin_server_port, 3, 4, 1, 1);

        label_6 = new QLabel(OptionsDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 3, 1, 1);

        pushButton_tcp_client = new QPushButton(OptionsDialog);
        pushButton_tcp_client->setObjectName(QString::fromUtf8("pushButton_tcp_client"));
        pushButton_tcp_client->setEnabled(true);
        pushButton_tcp_client->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_tcp_client, 3, 2, 1, 1);

        label = new QLabel(OptionsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        label_7 = new QLabel(OptionsDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 3, 1, 1);

        label_8 = new QLabel(OptionsDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 3, 1, 1);

        spin_updateInterval = new QSpinBox(OptionsDialog);
        spin_updateInterval->setObjectName(QString::fromUtf8("spin_updateInterval"));
        spin_updateInterval->setMinimum(50);
        spin_updateInterval->setMaximum(10000);
        spin_updateInterval->setValue(75);

        gridLayout->addWidget(spin_updateInterval, 7, 3, 1, 1);

        label_4 = new QLabel(OptionsDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 6, 0, 1, 2);

        buttonBox = new QDialogButtonBox(OptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 9, 3, 1, 2);

        QWidget::setTabOrder(pushButton_udp, pushButton_tcp_server);
        QWidget::setTabOrder(pushButton_tcp_server, pushButton_tcp_server_2);
        QWidget::setTabOrder(pushButton_tcp_server_2, pushButton_tcp_client);
        QWidget::setTabOrder(pushButton_tcp_client, spin_listen_port);
        QWidget::setTabOrder(spin_listen_port, lineEdit_server_ip);
        QWidget::setTabOrder(lineEdit_server_ip, spin_server_port);
        QWidget::setTabOrder(spin_server_port, spin_domainId);
        QWidget::setTabOrder(spin_domainId, pushButton_start);
        QWidget::setTabOrder(pushButton_start, pushButton_stop);
        QWidget::setTabOrder(pushButton_stop, spin_updateInterval);
        QWidget::setTabOrder(spin_updateInterval, horizontalSlider_speed);

        retranslateUi(OptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "Options", nullptr));
        label_5->setText(QApplication::translate("OptionsDialog", "Transport:", nullptr));
        pushButton_tcp_server_2->setText(QApplication::translate("OptionsDialog", "TCP WAN Server", nullptr));
        label_2->setText(QApplication::translate("OptionsDialog", "Update interval (ms):", nullptr));
        label_3->setText(QApplication::translate("OptionsDialog", "Speed:", nullptr));
        pushButton_tcp_server->setText(QApplication::translate("OptionsDialog", "TCP LAN Server", nullptr));
        spin_listen_port->setSpecialValueText(QString());
        spin_listen_port->setSuffix(QString());
        pushButton_stop->setText(QApplication::translate("OptionsDialog", "Stop", nullptr));
        pushButton_udp->setText(QApplication::translate("OptionsDialog", "UDP", nullptr));
        spin_domainId->setSpecialValueText(QString());
        spin_domainId->setSuffix(QString());
        pushButton_start->setText(QApplication::translate("OptionsDialog", "Start", nullptr));
        spin_server_port->setSpecialValueText(QString());
        spin_server_port->setSuffix(QString());
        label_6->setText(QApplication::translate("OptionsDialog", "Server IP:", nullptr));
        pushButton_tcp_client->setText(QApplication::translate("OptionsDialog", "TCP Client", nullptr));
        label->setText(QApplication::translate("OptionsDialog", "Domain ID:", nullptr));
        label_7->setText(QApplication::translate("OptionsDialog", "Server Port:", nullptr));
        label_8->setText(QApplication::translate("OptionsDialog", "Listen Port:", nullptr));
        spin_updateInterval->setSpecialValueText(QString());
        spin_updateInterval->setSuffix(QString());
        label_4->setText(QApplication::translate("OptionsDialog", "Shape Movements:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
