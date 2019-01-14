/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *spin_server_port;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QSpinBox *spin_domainId;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QSlider *horizontalSlider_speed;
    QLabel *label_3;
    QSpinBox *spin_updateInterval;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_udp;
    QLabel *label_8;
    QSpinBox *spin_listen_port;
    QLineEdit *lineEdit_server_ip;
    QPushButton *pushButton_tcp_client;
    QPushButton *pushButton_tcp_server;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QStringLiteral("OptionsDialog"));
        OptionsDialog->resize(410, 319);
        verticalLayout = new QVBoxLayout(OptionsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_6 = new QLabel(OptionsDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        label_7 = new QLabel(OptionsDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 2, 1, 1);

        spin_server_port = new QSpinBox(OptionsDialog);
        spin_server_port->setObjectName(QStringLiteral("spin_server_port"));
        spin_server_port->setMaximum(65535);
        spin_server_port->setValue(80);

        gridLayout->addWidget(spin_server_port, 3, 3, 1, 1);

        pushButton_start = new QPushButton(OptionsDialog);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_start, 5, 2, 1, 1);

        pushButton_stop = new QPushButton(OptionsDialog);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_stop, 5, 3, 1, 1);

        spin_domainId = new QSpinBox(OptionsDialog);
        spin_domainId->setObjectName(QStringLiteral("spin_domainId"));
        spin_domainId->setValue(80);

        gridLayout->addWidget(spin_domainId, 5, 1, 1, 1);

        label = new QLabel(OptionsDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 3);

        horizontalSlider_speed = new QSlider(OptionsDialog);
        horizontalSlider_speed->setObjectName(QStringLiteral("horizontalSlider_speed"));
        horizontalSlider_speed->setMinimum(0);
        horizontalSlider_speed->setMaximum(25);
        horizontalSlider_speed->setValue(5);
        horizontalSlider_speed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_speed, 10, 1, 1, 3);

        label_3 = new QLabel(OptionsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 10, 0, 1, 1);

        spin_updateInterval = new QSpinBox(OptionsDialog);
        spin_updateInterval->setObjectName(QStringLiteral("spin_updateInterval"));
        spin_updateInterval->setMinimum(50);
        spin_updateInterval->setMaximum(10000);
        spin_updateInterval->setValue(75);

        gridLayout->addWidget(spin_updateInterval, 9, 2, 1, 1);

        label_2 = new QLabel(OptionsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 9, 0, 1, 1);

        label_4 = new QLabel(OptionsDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 7, 0, 1, 2);

        label_5 = new QLabel(OptionsDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        pushButton_udp = new QPushButton(OptionsDialog);
        pushButton_udp->setObjectName(QStringLiteral("pushButton_udp"));
        pushButton_udp->setEnabled(true);
        pushButton_udp->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_udp, 0, 1, 1, 1);

        label_8 = new QLabel(OptionsDialog);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        spin_listen_port = new QSpinBox(OptionsDialog);
        spin_listen_port->setObjectName(QStringLiteral("spin_listen_port"));
        spin_listen_port->setMaximum(65535);
        spin_listen_port->setValue(80);

        gridLayout->addWidget(spin_listen_port, 1, 3, 1, 1);

        lineEdit_server_ip = new QLineEdit(OptionsDialog);
        lineEdit_server_ip->setObjectName(QStringLiteral("lineEdit_server_ip"));

        gridLayout->addWidget(lineEdit_server_ip, 2, 3, 1, 1);

        pushButton_tcp_client = new QPushButton(OptionsDialog);
        pushButton_tcp_client->setObjectName(QStringLiteral("pushButton_tcp_client"));
        pushButton_tcp_client->setEnabled(true);
        pushButton_tcp_client->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_tcp_client, 2, 1, 1, 1);

        pushButton_tcp_server = new QPushButton(OptionsDialog);
        pushButton_tcp_server->setObjectName(QStringLiteral("pushButton_tcp_server"));
        pushButton_tcp_server->setEnabled(true);
        pushButton_tcp_server->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_tcp_server, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(OptionsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(OptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "Options", nullptr));
        label_6->setText(QApplication::translate("OptionsDialog", "Server IP:", nullptr));
        label_7->setText(QApplication::translate("OptionsDialog", "Server Port:", nullptr));
        spin_server_port->setSpecialValueText(QString());
        spin_server_port->setSuffix(QString());
        pushButton_start->setText(QApplication::translate("OptionsDialog", "Start", nullptr));
        pushButton_stop->setText(QApplication::translate("OptionsDialog", "Stop", nullptr));
        spin_domainId->setSpecialValueText(QString());
        spin_domainId->setSuffix(QString());
        label->setText(QApplication::translate("OptionsDialog", "Domain ID:", nullptr));
        label_3->setText(QApplication::translate("OptionsDialog", "Speed:", nullptr));
        spin_updateInterval->setSpecialValueText(QString());
        spin_updateInterval->setSuffix(QString());
        label_2->setText(QApplication::translate("OptionsDialog", "Update interval (ms):", nullptr));
        label_4->setText(QApplication::translate("OptionsDialog", "Shape Movements:", nullptr));
        label_5->setText(QApplication::translate("OptionsDialog", "Transport:", nullptr));
        pushButton_udp->setText(QApplication::translate("OptionsDialog", "UDP", nullptr));
        label_8->setText(QApplication::translate("OptionsDialog", "Listen Port:", nullptr));
        spin_listen_port->setSpecialValueText(QString());
        spin_listen_port->setSuffix(QString());
        pushButton_tcp_client->setText(QApplication::translate("OptionsDialog", "TCP Client", nullptr));
        pushButton_tcp_server->setText(QApplication::translate("OptionsDialog", "TCP Server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
