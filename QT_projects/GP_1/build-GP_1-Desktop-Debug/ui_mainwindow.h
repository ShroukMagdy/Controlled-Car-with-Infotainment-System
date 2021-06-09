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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_Forward;
    QPushButton *pushButton_Backward;
    QLabel *label_State;
    QPushButton *pushButton_Right;
    QPushButton *pushButton_Left;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 307);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_Forward = new QPushButton(centralWidget);
        pushButton_Forward->setObjectName(QStringLiteral("pushButton_Forward"));
        pushButton_Forward->setGeometry(QRect(130, 0, 105, 61));
        pushButton_Forward->setCheckable(true);
        pushButton_Backward = new QPushButton(centralWidget);
        pushButton_Backward->setObjectName(QStringLiteral("pushButton_Backward"));
        pushButton_Backward->setGeometry(QRect(130, 140, 105, 61));
        pushButton_Backward->setCheckable(true);
        label_State = new QLabel(centralWidget);
        label_State->setObjectName(QStringLiteral("label_State"));
        label_State->setGeometry(QRect(170, 110, 73, 23));
        pushButton_Right = new QPushButton(centralWidget);
        pushButton_Right->setObjectName(QStringLiteral("pushButton_Right"));
        pushButton_Right->setGeometry(QRect(240, 70, 105, 61));
        pushButton_Right->setCheckable(true);
        pushButton_Left = new QPushButton(centralWidget);
        pushButton_Left->setObjectName(QStringLiteral("pushButton_Left"));
        pushButton_Left->setGeometry(QRect(20, 70, 105, 61));
        pushButton_Left->setCheckable(true);
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
        pushButton_Forward->setText(QApplication::translate("MainWindow", "Forward", nullptr));
        pushButton_Backward->setText(QApplication::translate("MainWindow", "Backward", nullptr));
        label_State->setText(QString());
        pushButton_Right->setText(QApplication::translate("MainWindow", "Right", nullptr));
        pushButton_Left->setText(QApplication::translate("MainWindow", "Left", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
