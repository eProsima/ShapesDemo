/********************************************************************************
** Form generated from reading UI file 'publishdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUBLISHDIALOG_H
#define UI_PUBLISHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_PublishDialog
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *combo_Shape;
    QComboBox *combo_Color;
    QSpinBox *spin_Size;
    QCheckBox *checkBox_A;
    QCheckBox *checkBox_B;
    QCheckBox *checkBox_C;
    QCheckBox *checkBox_D;
    QCheckBox *checkBox_Asterisk;
    QLabel *label_5;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QSpinBox *spin_HistoryQos;
    QLabel *label_7;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QComboBox *comboBox_liveliness;
    QLabel *label_8;
    QLineEdit *lineEdit_leaseDuration;
    QLabel *label_10;
    QComboBox *comboBox_durability;
    QLabel *label_13;
    QCheckBox *checkBox_reliable;
    QLabel *label_6;
    QFrame *frame_3;
    QGridLayout *gridLayout_3;
    QLabel *label_11;
    QComboBox *comboBox_ownership;
    QLabel *label_12;
    QSpinBox *spin_ownershipStrength;
    QDialogButtonBox *button_OkCancel;

    void setupUi(QDialog *PublishDialog)
    {
        if (PublishDialog->objectName().isEmpty())
            PublishDialog->setObjectName(QStringLiteral("PublishDialog"));
        PublishDialog->resize(452, 444);
        gridLayout_5 = new QGridLayout(PublishDialog);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(PublishDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(13);
        label_2->setFont(font);
        label_2->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(PublishDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_3 = new QLabel(PublishDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(PublishDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(label_4, 0, 3, 1, 2);

        combo_Shape = new QComboBox(PublishDialog);
        combo_Shape->setObjectName(QStringLiteral("combo_Shape"));

        gridLayout->addWidget(combo_Shape, 1, 0, 1, 1);

        combo_Color = new QComboBox(PublishDialog);
        combo_Color->setObjectName(QStringLiteral("combo_Color"));

        gridLayout->addWidget(combo_Color, 1, 1, 1, 1);

        spin_Size = new QSpinBox(PublishDialog);
        spin_Size->setObjectName(QStringLiteral("spin_Size"));
        spin_Size->setMinimum(1);
        spin_Size->setValue(30);

        gridLayout->addWidget(spin_Size, 1, 2, 1, 1);

        checkBox_A = new QCheckBox(PublishDialog);
        checkBox_A->setObjectName(QStringLiteral("checkBox_A"));

        gridLayout->addWidget(checkBox_A, 1, 3, 1, 1);

        checkBox_B = new QCheckBox(PublishDialog);
        checkBox_B->setObjectName(QStringLiteral("checkBox_B"));

        gridLayout->addWidget(checkBox_B, 1, 4, 1, 1);

        checkBox_C = new QCheckBox(PublishDialog);
        checkBox_C->setObjectName(QStringLiteral("checkBox_C"));

        gridLayout->addWidget(checkBox_C, 1, 5, 1, 1);

        checkBox_D = new QCheckBox(PublishDialog);
        checkBox_D->setObjectName(QStringLiteral("checkBox_D"));

        gridLayout->addWidget(checkBox_D, 1, 6, 1, 1);

        checkBox_Asterisk = new QCheckBox(PublishDialog);
        checkBox_Asterisk->setObjectName(QStringLiteral("checkBox_Asterisk"));

        gridLayout->addWidget(checkBox_Asterisk, 0, 5, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        label_5 = new QLabel(PublishDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        label_5->setTextFormat(Qt::AutoText);

        gridLayout_5->addWidget(label_5, 1, 0, 1, 1);

        frame = new QFrame(PublishDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        spin_HistoryQos = new QSpinBox(frame);
        spin_HistoryQos->setObjectName(QStringLiteral("spin_HistoryQos"));
        spin_HistoryQos->setMinimum(1);
        spin_HistoryQos->setMaximum(200);
        spin_HistoryQos->setValue(1);

        gridLayout_4->addWidget(spin_HistoryQos, 0, 1, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);
        label_7->setTextFormat(Qt::AutoText);

        gridLayout_4->addWidget(label_7, 2, 0, 1, 1);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        comboBox_liveliness = new QComboBox(frame_2);
        comboBox_liveliness->setObjectName(QStringLiteral("comboBox_liveliness"));

        gridLayout_2->addWidget(comboBox_liveliness, 0, 1, 1, 2);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(label_8, 1, 0, 1, 2);

        lineEdit_leaseDuration = new QLineEdit(frame_2);
        lineEdit_leaseDuration->setObjectName(QStringLiteral("lineEdit_leaseDuration"));

        gridLayout_2->addWidget(lineEdit_leaseDuration, 1, 2, 1, 1);


        gridLayout_4->addWidget(frame_2, 3, 0, 1, 3);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setTextFormat(Qt::AutoText);

        gridLayout_4->addWidget(label_10, 1, 0, 1, 1);

        comboBox_durability = new QComboBox(frame);
        comboBox_durability->setObjectName(QStringLiteral("comboBox_durability"));

        gridLayout_4->addWidget(comboBox_durability, 1, 1, 1, 1);

        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);
        label_13->setTextFormat(Qt::AutoText);

        gridLayout_4->addWidget(label_13, 4, 0, 1, 2);

        checkBox_reliable = new QCheckBox(frame);
        checkBox_reliable->setObjectName(QStringLiteral("checkBox_reliable"));
        checkBox_reliable->setFont(font);
        checkBox_reliable->setChecked(true);

        gridLayout_4->addWidget(checkBox_reliable, 0, 2, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setTextFormat(Qt::AutoText);

        gridLayout_4->addWidget(label_6, 0, 0, 1, 1);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);
        label_11->setTextFormat(Qt::AutoText);

        gridLayout_3->addWidget(label_11, 0, 0, 1, 1);

        comboBox_ownership = new QComboBox(frame_3);
        comboBox_ownership->setObjectName(QStringLiteral("comboBox_ownership"));

        gridLayout_3->addWidget(comboBox_ownership, 0, 1, 1, 2);

        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);
        label_12->setTextFormat(Qt::AutoText);

        gridLayout_3->addWidget(label_12, 2, 0, 1, 2);

        spin_ownershipStrength = new QSpinBox(frame_3);
        spin_ownershipStrength->setObjectName(QStringLiteral("spin_ownershipStrength"));
        spin_ownershipStrength->setMinimum(0);
        spin_ownershipStrength->setMaximum(10000);
        spin_ownershipStrength->setValue(0);

        gridLayout_3->addWidget(spin_ownershipStrength, 2, 2, 1, 1);


        gridLayout_4->addWidget(frame_3, 5, 0, 1, 3);

        label_6->raise();
        spin_HistoryQos->raise();
        checkBox_reliable->raise();
        label_7->raise();
        frame_2->raise();
        label_10->raise();
        comboBox_durability->raise();
        label_13->raise();
        frame_3->raise();

        gridLayout_5->addWidget(frame, 2, 0, 1, 1);

        button_OkCancel = new QDialogButtonBox(PublishDialog);
        button_OkCancel->setObjectName(QStringLiteral("button_OkCancel"));
        button_OkCancel->setOrientation(Qt::Horizontal);
        button_OkCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_5->addWidget(button_OkCancel, 3, 0, 1, 1);


        retranslateUi(PublishDialog);
        QObject::connect(button_OkCancel, SIGNAL(accepted()), PublishDialog, SLOT(accept()));
        QObject::connect(button_OkCancel, SIGNAL(rejected()), PublishDialog, SLOT(reject()));

        comboBox_durability->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PublishDialog);
    } // setupUi

    void retranslateUi(QDialog *PublishDialog)
    {
        PublishDialog->setWindowTitle(QApplication::translate("PublishDialog", "Publish", 0));
        label_2->setText(QApplication::translate("PublishDialog", "Shape", 0));
        label->setText(QApplication::translate("PublishDialog", "Color", 0));
        label_3->setText(QApplication::translate("PublishDialog", "Size", 0));
        label_4->setText(QApplication::translate("PublishDialog", "Partition", 0));
        combo_Shape->clear();
        combo_Shape->insertItems(0, QStringList()
         << QApplication::translate("PublishDialog", "Square", 0)
         << QApplication::translate("PublishDialog", "Triangle", 0)
         << QApplication::translate("PublishDialog", "Circle", 0)
        );
        combo_Color->clear();
        combo_Color->insertItems(0, QStringList()
         << QApplication::translate("PublishDialog", "RED", 0)
         << QApplication::translate("PublishDialog", "BLUE", 0)
         << QApplication::translate("PublishDialog", "GREEN", 0)
         << QApplication::translate("PublishDialog", "YELLOW", 0)
         << QApplication::translate("PublishDialog", "ORANGE", 0)
         << QApplication::translate("PublishDialog", "CYAN", 0)
         << QApplication::translate("PublishDialog", "MAGENTA", 0)
         << QApplication::translate("PublishDialog", "PURPLE", 0)
         << QApplication::translate("PublishDialog", "GRAY", 0)
         << QApplication::translate("PublishDialog", "BLACK", 0)
        );
        checkBox_A->setText(QApplication::translate("PublishDialog", "A", 0));
        checkBox_B->setText(QApplication::translate("PublishDialog", "B", 0));
        checkBox_C->setText(QApplication::translate("PublishDialog", "C", 0));
        checkBox_D->setText(QApplication::translate("PublishDialog", "D", 0));
        checkBox_Asterisk->setText(QApplication::translate("PublishDialog", "*", 0));
        label_5->setText(QApplication::translate("PublishDialog", "QoS Settings", 0));
        label_7->setText(QApplication::translate("PublishDialog", "Liveliness", 0));
        label_9->setText(QApplication::translate("PublishDialog", "Kind:", 0));
        comboBox_liveliness->clear();
        comboBox_liveliness->insertItems(0, QStringList()
         << QApplication::translate("PublishDialog", "AUTOMATIC", 0)
         << QApplication::translate("PublishDialog", "MANUAL_BY_RTPSParticipant", 0)
         << QApplication::translate("PublishDialog", "MANUAL_BY_TOPIC", 0)
        );
        label_8->setText(QApplication::translate("PublishDialog", "Lease Duration (ms):", 0));
        lineEdit_leaseDuration->setText(QApplication::translate("PublishDialog", "INF", 0));
        label_10->setText(QApplication::translate("PublishDialog", "Durability:", 0));
        comboBox_durability->clear();
        comboBox_durability->insertItems(0, QStringList()
         << QApplication::translate("PublishDialog", "VOLATILE", 0)
         << QApplication::translate("PublishDialog", "TRANSIENT_LOCAL", 0)
        );
        label_13->setText(QApplication::translate("PublishDialog", "Ownership", 0));
        checkBox_reliable->setText(QApplication::translate("PublishDialog", "Reliable", 0));
        label_6->setText(QApplication::translate("PublishDialog", "History:", 0));
        label_11->setText(QApplication::translate("PublishDialog", "Kind:", 0));
        comboBox_ownership->clear();
        comboBox_ownership->insertItems(0, QStringList()
         << QApplication::translate("PublishDialog", "SHARED_OWNERSHIP", 0)
         << QApplication::translate("PublishDialog", "EXCLUSIVE_OWNERSHIP", 0)
        );
        label_12->setText(QApplication::translate("PublishDialog", "Ownership Strength:", 0));
    } // retranslateUi

};

namespace Ui {
    class PublishDialog: public Ui_PublishDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBLISHDIALOG_H
