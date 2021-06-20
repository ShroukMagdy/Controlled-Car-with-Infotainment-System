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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *Modes;
    QWidget *ManualDriving_T;
    QWidget *SelfDriving_T;
    QGroupBox *groupBox;
    QRadioButton *Path1_RB;
    QRadioButton *Path2_RB;
    QRadioButton *Path3_RB;
    QRadioButton *Path4_RB;
    QPushButton *Go_B;
    QPushButton *NewPath_B;
    QFrame *line;
    QSpinBox *NoofMoves_SB;
    QLabel *NoofMoves_L;
    QLabel *Distance_L;
    QSpinBox *Distance_SB;
    QPushButton *Next_B;
    QPushButton *Finish_B;
    QComboBox *Direction_CB;
    QLabel *Direction_L;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(384, 474);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Modes = new QTabWidget(centralWidget);
        Modes->setObjectName(QStringLiteral("Modes"));
        Modes->setGeometry(QRect(14, 0, 351, 401));
        ManualDriving_T = new QWidget();
        ManualDriving_T->setObjectName(QStringLiteral("ManualDriving_T"));
        Modes->addTab(ManualDriving_T, QString());
        SelfDriving_T = new QWidget();
        SelfDriving_T->setObjectName(QStringLiteral("SelfDriving_T"));
        groupBox = new QGroupBox(SelfDriving_T);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 0, 151, 181));
        Path1_RB = new QRadioButton(groupBox);
        Path1_RB->setObjectName(QStringLiteral("Path1_RB"));
        Path1_RB->setGeometry(QRect(0, 30, 125, 28));
        Path2_RB = new QRadioButton(groupBox);
        Path2_RB->setObjectName(QStringLiteral("Path2_RB"));
        Path2_RB->setGeometry(QRect(0, 70, 125, 28));
        Path3_RB = new QRadioButton(groupBox);
        Path3_RB->setObjectName(QStringLiteral("Path3_RB"));
        Path3_RB->setGeometry(QRect(0, 110, 125, 28));
        Path4_RB = new QRadioButton(groupBox);
        Path4_RB->setObjectName(QStringLiteral("Path4_RB"));
        Path4_RB->setGeometry(QRect(0, 150, 125, 28));
        Go_B = new QPushButton(SelfDriving_T);
        Go_B->setObjectName(QStringLiteral("Go_B"));
        Go_B->setGeometry(QRect(220, 50, 105, 31));
        NewPath_B = new QPushButton(SelfDriving_T);
        NewPath_B->setObjectName(QStringLiteral("NewPath_B"));
        NewPath_B->setGeometry(QRect(220, 130, 105, 31));
        line = new QFrame(SelfDriving_T);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 180, 331, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        NoofMoves_SB = new QSpinBox(SelfDriving_T);
        NoofMoves_SB->setObjectName(QStringLiteral("NoofMoves_SB"));
        NoofMoves_SB->setGeometry(QRect(220, 200, 105, 31));
        NoofMoves_L = new QLabel(SelfDriving_T);
        NoofMoves_L->setObjectName(QStringLiteral("NoofMoves_L"));
        NoofMoves_L->setGeometry(QRect(30, 200, 111, 23));
        Distance_L = new QLabel(SelfDriving_T);
        Distance_L->setObjectName(QStringLiteral("Distance_L"));
        Distance_L->setGeometry(QRect(30, 280, 73, 23));
        Distance_SB = new QSpinBox(SelfDriving_T);
        Distance_SB->setObjectName(QStringLiteral("Distance_SB"));
        Distance_SB->setGeometry(QRect(220, 280, 105, 31));
        Next_B = new QPushButton(SelfDriving_T);
        Next_B->setObjectName(QStringLiteral("Next_B"));
        Next_B->setGeometry(QRect(20, 320, 105, 31));
        Finish_B = new QPushButton(SelfDriving_T);
        Finish_B->setObjectName(QStringLiteral("Finish_B"));
        Finish_B->setGeometry(QRect(220, 320, 105, 31));
        Direction_CB = new QComboBox(SelfDriving_T);
        Direction_CB->setObjectName(QStringLiteral("Direction_CB"));
        Direction_CB->setGeometry(QRect(220, 240, 105, 31));
        Direction_L = new QLabel(SelfDriving_T);
        Direction_L->setObjectName(QStringLiteral("Direction_L"));
        Direction_L->setGeometry(QRect(30, 240, 73, 23));
        Modes->addTab(SelfDriving_T, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 384, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        Modes->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Modes->setTabText(Modes->indexOf(ManualDriving_T), QApplication::translate("MainWindow", "ManualDriving", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Saved Paths", nullptr));
        Path1_RB->setText(QApplication::translate("MainWindow", "RadioButton", nullptr));
        Path2_RB->setText(QApplication::translate("MainWindow", "RadioButton", nullptr));
        Path3_RB->setText(QApplication::translate("MainWindow", "RadioButton", nullptr));
        Path4_RB->setText(QApplication::translate("MainWindow", "RadioButton", nullptr));
        Go_B->setText(QApplication::translate("MainWindow", "GO", nullptr));
        NewPath_B->setText(QApplication::translate("MainWindow", "New Path", nullptr));
        NoofMoves_L->setText(QApplication::translate("MainWindow", "No. of Moves", nullptr));
        Distance_L->setText(QApplication::translate("MainWindow", "Distance", nullptr));
        Next_B->setText(QApplication::translate("MainWindow", "Next", nullptr));
        Finish_B->setText(QApplication::translate("MainWindow", "Finish", nullptr));
        Direction_L->setText(QApplication::translate("MainWindow", "Direction", nullptr));
        Modes->setTabText(Modes->indexOf(SelfDriving_T), QApplication::translate("MainWindow", "SelfDriving", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
