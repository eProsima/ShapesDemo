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
    QVBoxLayout* verticalLayout;
    QGridLayout* gridLayout;
    QSpacerItem* verticalSpacer;
    QLabel* label_2; //Shape
    QComboBox* combo_Shape;
    QLabel* label; //Color
    QComboBox* combo_Color;
    QLabel* label_3; //Size
    QSpinBox* spin_Size;
    QLabel* label_4; //Parition
    QCheckBox* checkBox_A;
    QCheckBox* checkBox_B;
    QCheckBox* checkBox_C;
    QCheckBox* checkBox_D;
    QCheckBox* checkBox_Asterisk;
    QLabel* label_5; //Qos settings
    QFrame* frame;
    QGridLayout* outer_gridLayout;
    QCheckBox* checkBox_reliable;
    QLabel* label_6; //History
    QSpinBox* spin_HistoryQos;
    QLabel* label_10; //Durability
    QComboBox* comboBox_durability;
    QLabel* label_7; //Liveliness
    QFrame* frame_2;
    QGridLayout* gridLayout_2;
    QLabel* label_9; //Liveliness kind
    QComboBox* comboBox_liveliness;
    QLabel* label_8; //Lease Duration
    QLineEdit* lineEdit_leaseDuration;
    QLabel* label_17; //Ownership
    QFrame* frame_3;
    QGridLayout* gridLayout_3;
    QLabel* label_11; //Ownership kind
    QComboBox* comboBox_ownership;
    QLabel* label_12; //Ownership strength
    QSpinBox* spin_ownershipStrength;
    QLabel* label_14; //Deadline
    QFrame* frame_4;
    QGridLayout* gridLayout_4;
    QLabel* label_19; //Deadline duration
    QLineEdit* lineEdit_Deadline;
    QLabel* label_18; //Lifespan
    QFrame* frame_5;
    QGridLayout* gridLayout_5;
    QLabel* label_20; //Lifespan duration
    QLineEdit* lineEdit_Lifespan;
    QDialogButtonBox* button_OkCancel;

    void setupUi(
            QDialog* PublishDialog)
    {
        if (PublishDialog->objectName().isEmpty())
        {
            PublishDialog->setObjectName(QStringLiteral("PublishDialog"));
        }
        PublishDialog->resize(452, 444);
        verticalLayout = new QVBoxLayout(PublishDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
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


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);
        verticalLayout->addItem(verticalSpacer);

        label_5 = new QLabel(PublishDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        label_5->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(label_5);

        frame = new QFrame(PublishDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        outer_girdLayout = new QGridLayout(frame);
        outer_girdLayout->setObjectName(QStringLiteral("outer_girdLayout"));
        spin_HistoryQos = new QSpinBox(frame);
        spin_HistoryQos->setObjectName(QStringLiteral("spin_HistoryQos"));
        spin_HistoryQos->setMinimum(1);
        spin_HistoryQos->setMaximum(200);
        spin_HistoryQos->setValue(1);

        outer_girdLayout->addWidget(spin_HistoryQos, 0, 1, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        label_6->setTextFormat(Qt::AutoText);

        outer_girdLayout->addWidget(label_6, 0, 0, 1, 1);

        checkBox_reliable = new QCheckBox(frame);
        checkBox_reliable->setObjectName(QStringLiteral("checkBox_reliable"));
        checkBox_reliable->setFont(font);
        checkBox_reliable->setChecked(true);

        outer_girdLayout->addWidget(checkBox_reliable, 0, 2, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setTextFormat(Qt::AutoText);

        outer_girdLayout->addWidget(label_10, 1, 0, 1, 1);

        comboBox_durability = new QComboBox(frame);
        comboBox_durability->setObjectName(QStringLiteral("comboBox_durability"));

        outer_girdLayout->addWidget(comboBox_durability, 1, 1, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);
        label_7->setTextFormat(Qt::AutoText);

        outer_girdLayout->addWidget(label_7, 2, 0, 1, 1);

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

        outer_girdLayout->addWidget(gridLayout_2, 3, 0, 1, 3);

        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);
        label_17->setTextFormat(Qt::AutoText);

        outer_girdLayout->addWidget(label_17, 0, 0, 1, 1);

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

        outer_girdLayout->addWidget(gridLayout_3, 5, 0, 1, 3);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);
        label_14->setTextFormat(Qt::AutoText);

        outer_gridLayout->addWidget(label_14, 2, 0, 1, 2);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_19 = new QLabel(frame_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);
        label_19->setTextFormat(Qt::AutoText);

        lineEdit_Deadline = new QLineEdit(frame_4);
        lineEdit_Deadline->setObjectName(QStringLiteral("lineEdit_Deadline"));

        gridLayout_4->addWidget(lineEdit_Deadline, 1, 2, 1, 1);

        outer_girdLayout->addWidget(gridLayout_4, 5, 0, 1, 3);

        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);
        label_18->setTextFormat(Qt::AutoText);

        outer_gridLayout->addWidget(label_18, 2, 0, 1, 2);

        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_3);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_20 = new QLabel(frame_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);
        label_20->setTextFormat(Qt::AutoText);

        lineEdit_Lifespan = new QLineEdit(frame_5);
        lineEdit_Lifespan->setObjectName(QStringLiteral("lineEdit_Lifespan"));

        gridLayout_5->addWidget(lineEdit_Lifespan, 1, 2, 1, 1);

        outer_girdLayout->addWidget(gridLayout_5, 5, 0, 1, 3);

        label_6->raise();
        spin_HistoryQos->raise();
        checkBox_reliable->raise();
        label_7->raise();
        frame_2->raise();
        label_10->raise();
        comboBox_durability->raise();
        label_13->raise();
        frame_3->raise();

        verticalLayout->addWidget(frame);

        button_OkCancel = new QDialogButtonBox(PublishDialog);
        button_OkCancel->setObjectName(QStringLiteral("button_OkCancel"));
        button_OkCancel->setOrientation(Qt::Horizontal);
        button_OkCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(button_OkCancel);

        retranslateUi(PublishDialog);
        QObject::connect(button_OkCancel, SIGNAL(accepted()), PublishDialog, SLOT(accept()));
        QObject::connect(button_OkCancel, SIGNAL(rejected()), PublishDialog, SLOT(reject()));

        comboBox_durability->setCurrentIndex(1);

        QMetaObject::connectSlotsByName(PublishDialog);
    } // setupUi

    void retranslateUi(
            QDialog* PublishDialog)
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
        checkBox_reliable->setText(QApplication::translate("PublishDialog", "Reliable", 0));
        label_6->setText(QApplication::translate("PublishDialog", "History:", 0));
        label_10->setText(QApplication::translate("PublishDialog", "Durability:", 0));
        comboBox_durability->clear();
        comboBox_durability->insertItems(0, QStringList()
         << QApplication::translate("PublishDialog", "VOLATILE", 0)
         << QApplication::translate("PublishDialog", "TRANSIENT_LOCAL", 0)
        );
        label_7->setText(QApplication::translate("PublishDialog", "Liveliness", 0));
        label_9->setText(QApplication::translate("PublishDialog", "Kind:", 0));
        comboBox_liveliness->clear();
        comboBox_liveliness->insertItems(0, QStringList()
         << QApplication::translate("PublishDialog", "AUTOMATIC", 0)
         << QApplication::translate("PublishDialog", "MANUAL_BY_PARTICIPANT", 0)
         << QApplication::translate("PublishDialog", "MANUAL_BY_TOPIC", 0)
        );
        label_8->setText(QApplication::translate("PublishDialog", "Lease Duration (ms):", 0));
        lineEdit_leaseDuration->setText(QApplication::translate("PublishDialog", "INF", 0));
        label_17->setText(QApplication::translate("PublishDialog", "Ownership", 0));
        label_11->setText(QApplication::translate("PublishDialog", "Kind:", 0));
        label_12->setText(QApplication::translate("PublishDialog", "Ownership Strength:", 0));
        comboBox_ownership->clear();
        comboBox_ownership->insertItems(0, QStringList()
         << QApplication::translate("PublishDialog", "SHARED_OWNERSHIP", 0)
         << QApplication::translate("PublishDialog", "EXCLUSIVE_OWNERSHIP", 0)
        );
        label_14->setText(QApplication::translate("PublishDialog", "Deadline", 0));
        label_19->setText(QApplication::translate("PublishDialog", "Duration (ms):", 0));
        lineEdit_Deadline->setText(QApplication::translate("PublishDialog", "INF", 0));
        label_18->setText(QApplication::translate("PublishDialog", "Lifespan", 0));
        label_20->setText(QApplication::translate("PublishDialog", "Duration (ms):", 0));
        lineEdit_Lifespan->setText(QApplication::translate("PublishDialog", "INF", 0));
    } // retranslateUi

};

namespace Ui {
    class PublishDialog: public Ui_PublishDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBLISHDIALOG_H
