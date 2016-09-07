/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "eprosimashapesdemo/qt/ContentFilterSelector.h"
#include "eprosimashapesdemo/qt/DrawArea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPreferences;
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionExit;
    QAction *actionDelete_Enpoint;
    QAction *actionAbout;
    QAction *actionUser_Manual;
    QAction *actionInteroperability_Troubleshooting;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bt_subscribe;
    QSpacerItem *verticalSpacer_2;
    QFrame *frameDraw;
    QHBoxLayout *horizontalLayout;
    QFrame *frameDraw2;
    QVBoxLayout *verticalLayout_5;
    DrawArea *areaDraw;
    ContentFilterSelector *widget_contentFilter;
    QPushButton *bt_publish;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab_endpoints;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableEndpoint;
    QWidget *tabOutput;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *text_Output;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QMenu *menuControl;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(465, 650);
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionDelete_Enpoint = new QAction(MainWindow);
        actionDelete_Enpoint->setObjectName(QStringLiteral("actionDelete_Enpoint"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionUser_Manual = new QAction(MainWindow);
        actionUser_Manual->setObjectName(QStringLiteral("actionUser_Manual"));
        actionInteroperability_Troubleshooting = new QAction(MainWindow);
        actionInteroperability_Troubleshooting->setObjectName(QStringLiteral("actionInteroperability_Troubleshooting"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(4);
        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 6, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 1, 6, 1);

        bt_subscribe = new QPushButton(centralWidget);
        bt_subscribe->setObjectName(QStringLiteral("bt_subscribe"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bt_subscribe->sizePolicy().hasHeightForWidth());
        bt_subscribe->setSizePolicy(sizePolicy);

        gridLayout->addWidget(bt_subscribe, 3, 0, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

        frameDraw = new QFrame(centralWidget);
        frameDraw->setObjectName(QStringLiteral("frameDraw"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frameDraw->sizePolicy().hasHeightForWidth());
        frameDraw->setSizePolicy(sizePolicy1);
        frameDraw->setMinimumSize(QSize(265, 287));
        frameDraw->setLayoutDirection(Qt::LeftToRight);
        frameDraw->setStyleSheet(QStringLiteral(""));
        frameDraw->setFrameShape(QFrame::StyledPanel);
        frameDraw->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frameDraw);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frameDraw2 = new QFrame(frameDraw);
        frameDraw2->setObjectName(QStringLiteral("frameDraw2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frameDraw2->sizePolicy().hasHeightForWidth());
        frameDraw2->setSizePolicy(sizePolicy2);
        frameDraw2->setMinimumSize(QSize(237, 267));
        frameDraw2->setMaximumSize(QSize(237, 267));
        frameDraw2->setStyleSheet(QStringLiteral("QFrame#frameDraw2{border: 1px inset black;}"));
        frameDraw2->setFrameShape(QFrame::StyledPanel);
        frameDraw2->setFrameShadow(QFrame::Plain);
        frameDraw2->setLineWidth(1);
        verticalLayout_5 = new QVBoxLayout(frameDraw2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        areaDraw = new DrawArea(frameDraw2);
        areaDraw->setObjectName(QStringLiteral("areaDraw"));
        sizePolicy2.setHeightForWidth(areaDraw->sizePolicy().hasHeightForWidth());
        areaDraw->setSizePolicy(sizePolicy2);
        areaDraw->setMinimumSize(QSize(235, 265));
        areaDraw->setMaximumSize(QSize(235, 265));
        areaDraw->setContextMenuPolicy(Qt::NoContextMenu);
        areaDraw->setStyleSheet(QStringLiteral(""));
        widget_contentFilter = new ContentFilterSelector(areaDraw);
        widget_contentFilter->setObjectName(QStringLiteral("widget_contentFilter"));
        widget_contentFilter->setEnabled(false);
        widget_contentFilter->setGeometry(QRect(60, 90, 61, 71));
        widget_contentFilter->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout_5->addWidget(areaDraw);


        horizontalLayout->addWidget(frameDraw2);


        gridLayout->addWidget(frameDraw, 0, 2, 6, 1);

        bt_publish = new QPushButton(centralWidget);
        bt_publish->setObjectName(QStringLiteral("bt_publish"));
        sizePolicy.setHeightForWidth(bt_publish->sizePolicy().hasHeightForWidth());
        bt_publish->setSizePolicy(sizePolicy);

        gridLayout->addWidget(bt_publish, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_endpoints = new QWidget();
        tab_endpoints->setObjectName(QStringLiteral("tab_endpoints"));
        verticalLayout_2 = new QVBoxLayout(tab_endpoints);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableEndpoint = new QTableView(tab_endpoints);
        tableEndpoint->setObjectName(QStringLiteral("tableEndpoint"));
        QFont font;
        font.setPointSize(9);
        tableEndpoint->setFont(font);
        tableEndpoint->setContextMenuPolicy(Qt::CustomContextMenu);
        tableEndpoint->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableEndpoint->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableEndpoint->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableEndpoint->setSelectionMode(QAbstractItemView::SingleSelection);
        tableEndpoint->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(tableEndpoint);

        tabWidget->addTab(tab_endpoints, QString());
        tabOutput = new QWidget();
        tabOutput->setObjectName(QStringLiteral("tabOutput"));
        verticalLayout_3 = new QVBoxLayout(tabOutput);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        text_Output = new QTextBrowser(tabOutput);
        text_Output->setObjectName(QStringLiteral("text_Output"));

        verticalLayout_3->addWidget(text_Output);

        tabWidget->addTab(tabOutput, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::BottomToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 465, 21));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuControl = new QMenu(menuBar);
        menuControl->setObjectName(QStringLiteral("menuControl"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuControl->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuOptions->addAction(actionPreferences);
        menuControl->addAction(actionStart);
        menuControl->addAction(actionStop);
        menuControl->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionUser_Manual);
        menuHelp->addAction(actionInteroperability_Troubleshooting);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Shapes Demo", 0));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0));
        actionStart->setText(QApplication::translate("MainWindow", "Start", 0));
        actionStop->setText(QApplication::translate("MainWindow", "Stop (delete all)", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionDelete_Enpoint->setText(QApplication::translate("MainWindow", "Delete Enpoint", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionUser_Manual->setText(QApplication::translate("MainWindow", "User Manual", 0));
        actionInteroperability_Troubleshooting->setText(QApplication::translate("MainWindow", "Interoperability Troubleshooting", 0));
        bt_subscribe->setText(QApplication::translate("MainWindow", "Subscribe", 0));
        bt_publish->setText(QApplication::translate("MainWindow", "Publish", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_endpoints), QApplication::translate("MainWindow", "Endpoints", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabOutput), QApplication::translate("MainWindow", "Output", 0));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
        menuControl->setTitle(QApplication::translate("MainWindow", "Control", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
