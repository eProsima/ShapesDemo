/********************************************************************************
** Form generated from reading UI file 'subscribedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBSCRIBEDIALOG_H
#define UI_SUBSCRIBEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SubscribeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *combo_Shape;
    QComboBox *combo_Color;
    QSpinBox *spin_Size;
    QCheckBox *checkBox_A;
    QCheckBox *checkBox_B;
    QCheckBox *checkBox_C;
    QCheckBox *checkBox_D;
    QCheckBox *checkBox_Asterisk;
    QSpacerItem *verticalSpacer;
    QLabel *label_9;
    QGridLayout *gridLayout_5;
    QLabel *label_11;
    QCheckBox *checkBox_reliable;
    QSpinBox *spin_HistoryQos;
    QComboBox *comboBox_durability;
    QSpinBox *spin_ownershipStrength;
    QLabel *label_18;
    QLabel *label_17;
    QLabel *label_12;
    QLabel *label_16;
    QCheckBox *checkBox_contentBasedFilter;
    QLabel *label_10;
    QLineEdit *lineEdit_TimeBasedFilter;
    QComboBox *comboBox_ownership;
    QCheckBox *checkBox_timeBasedFilter;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SubscribeDialog)
    {
        if (SubscribeDialog->objectName().isEmpty())
            SubscribeDialog->setObjectName(QStringLiteral("SubscribeDialog"));
        SubscribeDialog->resize(449, 403);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SubscribeDialog->sizePolicy().hasHeightForWidth());
        SubscribeDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(SubscribeDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        label_3 = new QLabel(SubscribeDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(13);
        label_3->setFont(font);
        label_3->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(SubscribeDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        label_7 = new QLabel(SubscribeDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(label_7, 0, 2, 1, 1);

        label_8 = new QLabel(SubscribeDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(label_8, 0, 3, 1, 2);

        combo_Shape = new QComboBox(SubscribeDialog);
        combo_Shape->setObjectName(QStringLiteral("combo_Shape"));

        gridLayout_2->addWidget(combo_Shape, 1, 0, 1, 1);

        combo_Color = new QComboBox(SubscribeDialog);
        combo_Color->setObjectName(QStringLiteral("combo_Color"));
        combo_Color->setEnabled(false);

        gridLayout_2->addWidget(combo_Color, 1, 1, 1, 1);

        spin_Size = new QSpinBox(SubscribeDialog);
        spin_Size->setObjectName(QStringLiteral("spin_Size"));
        spin_Size->setEnabled(false);
        spin_Size->setMinimum(1);
        spin_Size->setValue(30);

        gridLayout_2->addWidget(spin_Size, 1, 2, 1, 1);

        checkBox_A = new QCheckBox(SubscribeDialog);
        checkBox_A->setObjectName(QStringLiteral("checkBox_A"));

        gridLayout_2->addWidget(checkBox_A, 1, 3, 1, 1);

        checkBox_B = new QCheckBox(SubscribeDialog);
        checkBox_B->setObjectName(QStringLiteral("checkBox_B"));

        gridLayout_2->addWidget(checkBox_B, 1, 4, 1, 1);

        checkBox_C = new QCheckBox(SubscribeDialog);
        checkBox_C->setObjectName(QStringLiteral("checkBox_C"));

        gridLayout_2->addWidget(checkBox_C, 1, 5, 1, 1);

        checkBox_D = new QCheckBox(SubscribeDialog);
        checkBox_D->setObjectName(QStringLiteral("checkBox_D"));

        gridLayout_2->addWidget(checkBox_D, 1, 6, 1, 1);

        checkBox_Asterisk = new QCheckBox(SubscribeDialog);
        checkBox_Asterisk->setObjectName(QStringLiteral("checkBox_Asterisk"));

        gridLayout_2->addWidget(checkBox_Asterisk, 0, 5, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label_9 = new QLabel(SubscribeDialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        label_9->setFont(font1);
        label_9->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(label_9);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_11 = new QLabel(SubscribeDialog);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);
        label_11->setTextFormat(Qt::AutoText);

        gridLayout_5->addWidget(label_11, 3, 1, 1, 1);

        checkBox_reliable = new QCheckBox(SubscribeDialog);
        checkBox_reliable->setObjectName(QStringLiteral("checkBox_reliable"));
        checkBox_reliable->setFont(font);
        checkBox_reliable->setChecked(false);

        gridLayout_5->addWidget(checkBox_reliable, 0, 3, 1, 1);

        spin_HistoryQos = new QSpinBox(SubscribeDialog);
        spin_HistoryQos->setObjectName(QStringLiteral("spin_HistoryQos"));
        spin_HistoryQos->setMinimum(1);
        spin_HistoryQos->setMaximum(200);
        spin_HistoryQos->setValue(6);

        gridLayout_5->addWidget(spin_HistoryQos, 0, 2, 1, 1);

        comboBox_durability = new QComboBox(SubscribeDialog);
        comboBox_durability->setObjectName(QStringLiteral("comboBox_durability"));

        gridLayout_5->addWidget(comboBox_durability, 1, 2, 1, 2);

        spin_ownershipStrength = new QSpinBox(SubscribeDialog);
        spin_ownershipStrength->setObjectName(QStringLiteral("spin_ownershipStrength"));
        spin_ownershipStrength->setEnabled(false);
        spin_ownershipStrength->setMinimum(0);
        spin_ownershipStrength->setMaximum(50);
        spin_ownershipStrength->setValue(0);

        gridLayout_5->addWidget(spin_ownershipStrength, 4, 2, 1, 1);

        label_18 = new QLabel(SubscribeDialog);
        label_18->setObjectName(QStringLiteral("label_18"));
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);
        label_18->setFont(font1);
        label_18->setTextFormat(Qt::AutoText);

        gridLayout_5->addWidget(label_18, 5, 1, 1, 1);

        label_17 = new QLabel(SubscribeDialog);
        label_17->setObjectName(QStringLiteral("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);
        label_17->setFont(font1);
        label_17->setTextFormat(Qt::AutoText);

        gridLayout_5->addWidget(label_17, 2, 1, 1, 1);

        label_12 = new QLabel(SubscribeDialog);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);
        label_12->setTextFormat(Qt::AutoText);

        gridLayout_5->addWidget(label_12, 4, 1, 1, 1);

        label_16 = new QLabel(SubscribeDialog);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);
        label_16->setTextFormat(Qt::AutoText);

        gridLayout_5->addWidget(label_16, 1, 1, 1, 1);

        checkBox_contentBasedFilter = new QCheckBox(SubscribeDialog);
        checkBox_contentBasedFilter->setObjectName(QStringLiteral("checkBox_contentBasedFilter"));
        checkBox_contentBasedFilter->setFont(font);
        checkBox_contentBasedFilter->setChecked(false);

        gridLayout_5->addWidget(checkBox_contentBasedFilter, 7, 1, 1, 1);

        label_10 = new QLabel(SubscribeDialog);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setTextFormat(Qt::AutoText);

        gridLayout_5->addWidget(label_10, 0, 1, 1, 1);

        lineEdit_TimeBasedFilter = new QLineEdit(SubscribeDialog);
        lineEdit_TimeBasedFilter->setObjectName(QStringLiteral("lineEdit_TimeBasedFilter"));
        lineEdit_TimeBasedFilter->setEnabled(false);

        gridLayout_5->addWidget(lineEdit_TimeBasedFilter, 6, 2, 1, 1);

        comboBox_ownership = new QComboBox(SubscribeDialog);
        comboBox_ownership->setObjectName(QStringLiteral("comboBox_ownership"));

        gridLayout_5->addWidget(comboBox_ownership, 3, 2, 1, 2);

        checkBox_timeBasedFilter = new QCheckBox(SubscribeDialog);
        checkBox_timeBasedFilter->setObjectName(QStringLiteral("checkBox_timeBasedFilter"));
        checkBox_timeBasedFilter->setFont(font);

        gridLayout_5->addWidget(checkBox_timeBasedFilter, 6, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        buttonBox = new QDialogButtonBox(SubscribeDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SubscribeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SubscribeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SubscribeDialog, SLOT(reject()));

        comboBox_durability->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SubscribeDialog);
    } // setupUi

    void retranslateUi(QDialog *SubscribeDialog)
    {
        SubscribeDialog->setWindowTitle(QApplication::translate("SubscribeDialog", "Subscribe", 0));
        label_3->setText(QApplication::translate("SubscribeDialog", "Shape", 0));
        label->setText(QApplication::translate("SubscribeDialog", "Color", 0));
        label_7->setText(QApplication::translate("SubscribeDialog", "Size", 0));
        label_8->setText(QApplication::translate("SubscribeDialog", "Partition", 0));
        combo_Shape->clear();
        combo_Shape->insertItems(0, QStringList()
         << QApplication::translate("SubscribeDialog", "Square", 0)
         << QApplication::translate("SubscribeDialog", "Triangle", 0)
         << QApplication::translate("SubscribeDialog", "Circle", 0)
        );
        combo_Color->clear();
        combo_Color->insertItems(0, QStringList()
         << QApplication::translate("SubscribeDialog", "PURPLE", 0)
         << QApplication::translate("SubscribeDialog", "RED", 0)
         << QApplication::translate("SubscribeDialog", "BLUE", 0)
         << QApplication::translate("SubscribeDialog", "YELLOW", 0)
         << QApplication::translate("SubscribeDialog", "GREEN", 0)
         << QApplication::translate("SubscribeDialog", "ORANGE", 0)
         << QApplication::translate("SubscribeDialog", "MAGENTA", 0)
        );
        checkBox_A->setText(QApplication::translate("SubscribeDialog", "A", 0));
        checkBox_B->setText(QApplication::translate("SubscribeDialog", "B", 0));
        checkBox_C->setText(QApplication::translate("SubscribeDialog", "C", 0));
        checkBox_D->setText(QApplication::translate("SubscribeDialog", "D", 0));
        checkBox_Asterisk->setText(QApplication::translate("SubscribeDialog", "*", 0));
        label_9->setText(QApplication::translate("SubscribeDialog", "QoS Settings", 0));
        label_11->setText(QApplication::translate("SubscribeDialog", "Kind:", 0));
        checkBox_reliable->setText(QApplication::translate("SubscribeDialog", "Reliable", 0));
        comboBox_durability->clear();
        comboBox_durability->insertItems(0, QStringList()
         << QApplication::translate("SubscribeDialog", "VOLATILE", 0)
         << QApplication::translate("SubscribeDialog", "TRANSIENT_LOCAL", 0)
        );
        label_18->setText(QApplication::translate("SubscribeDialog", "Filters", 0));
        label_17->setText(QApplication::translate("SubscribeDialog", "Ownership", 0));
        label_12->setText(QApplication::translate("SubscribeDialog", "Ownership Strength:", 0));
        label_16->setText(QApplication::translate("SubscribeDialog", "Durability:", 0));
        checkBox_contentBasedFilter->setText(QApplication::translate("SubscribeDialog", "Content Based", 0));
        label_10->setText(QApplication::translate("SubscribeDialog", "History:", 0));
        lineEdit_TimeBasedFilter->setText(QApplication::translate("SubscribeDialog", "0", 0));
        comboBox_ownership->clear();
        comboBox_ownership->insertItems(0, QStringList()
         << QApplication::translate("SubscribeDialog", "SHARED_OWNERSHIP", 0)
         << QApplication::translate("SubscribeDialog", "EXCLUSIVE_OWNERSHIP", 0)
        );
        checkBox_timeBasedFilter->setText(QApplication::translate("SubscribeDialog", "Time Based (ms):", 0));
    } // retranslateUi

};

namespace Ui {
    class SubscribeDialog: public Ui_SubscribeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSCRIBEDIALOG_H
