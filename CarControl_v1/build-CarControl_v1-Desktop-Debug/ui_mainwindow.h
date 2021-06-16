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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *UP_B;
    QPushButton *RIGHT_B;
    QPushButton *DOWN_B;
    QPushButton *LEFT_B;
    QSlider *SpeedSlider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(381, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        UP_B = new QPushButton(centralWidget);
        UP_B->setObjectName(QStringLiteral("UP_B"));
        UP_B->setGeometry(QRect(130, 0, 71, 61));
        UP_B->setAutoFillBackground(false);
        UP_B->setCheckable(true);
        RIGHT_B = new QPushButton(centralWidget);
        RIGHT_B->setObjectName(QStringLiteral("RIGHT_B"));
        RIGHT_B->setGeometry(QRect(240, 70, 71, 61));
        RIGHT_B->setCheckable(true);
        RIGHT_B->setAutoDefault(false);
        DOWN_B = new QPushButton(centralWidget);
        DOWN_B->setObjectName(QStringLiteral("DOWN_B"));
        DOWN_B->setGeometry(QRect(130, 170, 71, 61));
        DOWN_B->setCheckable(true);
        LEFT_B = new QPushButton(centralWidget);
        LEFT_B->setObjectName(QStringLiteral("LEFT_B"));
        LEFT_B->setGeometry(QRect(20, 70, 71, 61));
        LEFT_B->setCheckable(true);
        SpeedSlider = new QSlider(centralWidget);
        SpeedSlider->setObjectName(QStringLiteral("SpeedSlider"));
        SpeedSlider->setGeometry(QRect(350, 30, 26, 160));
        SpeedSlider->setFocusPolicy(Qt::StrongFocus);
        SpeedSlider->setMaximum(3);
        SpeedSlider->setSingleStep(1);
        SpeedSlider->setPageStep(1);
        SpeedSlider->setSliderPosition(0);
        SpeedSlider->setTracking(true);
        SpeedSlider->setOrientation(Qt::Vertical);
        SpeedSlider->setTickPosition(QSlider::NoTicks);
        SpeedSlider->setTickInterval(0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 381, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        RIGHT_B->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        UP_B->setText(QString());
        RIGHT_B->setText(QString());
        DOWN_B->setText(QString());
        LEFT_B->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
