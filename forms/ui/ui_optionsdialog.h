/********************************************************************************
** Form generated from reading UI file 'optionsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
    QLabel *label;
    QSpinBox *spin_domainId;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QLabel *label_4;
    QSpinBox *spin_updateInterval;
    QSlider *horizontalSlider_speed;
    QLabel *label_2;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QStringLiteral("OptionsDialog"));
        OptionsDialog->resize(400, 196);
        verticalLayout = new QVBoxLayout(OptionsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(OptionsDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spin_domainId = new QSpinBox(OptionsDialog);
        spin_domainId->setObjectName(QStringLiteral("spin_domainId"));
        spin_domainId->setValue(80);

        gridLayout->addWidget(spin_domainId, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 3);

        pushButton_start = new QPushButton(OptionsDialog);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_start, 0, 3, 1, 1);

        pushButton_stop = new QPushButton(OptionsDialog);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(pushButton_stop, 0, 4, 1, 1);

        label_4 = new QLabel(OptionsDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 2, 0, 1, 3);

        spin_updateInterval = new QSpinBox(OptionsDialog);
        spin_updateInterval->setObjectName(QStringLiteral("spin_updateInterval"));
        spin_updateInterval->setMinimum(50);
        spin_updateInterval->setMaximum(10000);
        spin_updateInterval->setValue(75);

        gridLayout->addWidget(spin_updateInterval, 3, 3, 1, 2);

        horizontalSlider_speed = new QSlider(OptionsDialog);
        horizontalSlider_speed->setObjectName(QStringLiteral("horizontalSlider_speed"));
        horizontalSlider_speed->setMinimum(0);
        horizontalSlider_speed->setMaximum(25);
        horizontalSlider_speed->setValue(5);
        horizontalSlider_speed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_speed, 4, 3, 1, 2);

        label_2 = new QLabel(OptionsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 3);

        label_3 = new QLabel(OptionsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(OptionsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(spin_domainId, pushButton_start);
        QWidget::setTabOrder(pushButton_start, pushButton_stop);
        QWidget::setTabOrder(pushButton_stop, spin_updateInterval);
        QWidget::setTabOrder(spin_updateInterval, horizontalSlider_speed);
        QWidget::setTabOrder(horizontalSlider_speed, buttonBox);

        retranslateUi(OptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "Options", 0));
        label->setText(QApplication::translate("OptionsDialog", "Domain ID:", 0));
        spin_domainId->setSpecialValueText(QString());
        spin_domainId->setSuffix(QString());
        pushButton_start->setText(QApplication::translate("OptionsDialog", "Start", 0));
        pushButton_stop->setText(QApplication::translate("OptionsDialog", "Stop", 0));
        label_4->setText(QApplication::translate("OptionsDialog", "Shape Movements:", 0));
        spin_updateInterval->setSpecialValueText(QString());
        spin_updateInterval->setSuffix(QString());
        label_2->setText(QApplication::translate("OptionsDialog", "Update interval (ms):", 0));
        label_3->setText(QApplication::translate("OptionsDialog", "Length:", 0));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
