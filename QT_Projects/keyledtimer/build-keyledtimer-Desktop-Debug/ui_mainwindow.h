/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *DOWN;
    QLabel *RIGHT;
    QLabel *LEFT;
    QLabel *UP;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DOWN = new QLabel(centralWidget);
        DOWN->setObjectName(QStringLiteral("DOWN"));
        DOWN->setGeometry(QRect(160, 180, 73, 23));
        RIGHT = new QLabel(centralWidget);
        RIGHT->setObjectName(QStringLiteral("RIGHT"));
        RIGHT->setGeometry(QRect(270, 120, 73, 23));
        LEFT = new QLabel(centralWidget);
        LEFT->setObjectName(QStringLiteral("LEFT"));
        LEFT->setGeometry(QRect(60, 120, 73, 23));
        UP = new QLabel(centralWidget);
        UP->setObjectName(QStringLiteral("UP"));
        UP->setGeometry(QRect(170, 60, 73, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        DOWN->setText(QApplication::translate("MainWindow", "DOWN", nullptr));
        RIGHT->setText(QApplication::translate("MainWindow", "RIGHT", nullptr));
        LEFT->setText(QApplication::translate("MainWindow", "LEFT", nullptr));
        UP->setText(QApplication::translate("MainWindow", "UP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
