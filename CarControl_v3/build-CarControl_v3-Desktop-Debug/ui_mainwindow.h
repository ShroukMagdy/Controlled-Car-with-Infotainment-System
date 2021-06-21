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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Manual_T;
    QPushButton *DOWN_B;
    QPushButton *LEFT_B;
    QPushButton *RIGHT_B;
    QPushButton *UP_B;
    QSlider *SpeedSlider;
    QWidget *SelfDriving_T;
    QGraphicsView *graphicsView;
    QPushButton *Go_B;
    QLabel *StartingPoint_L;
    QLabel *Destination_L;
    QRadioButton *Work_RB;
    QRadioButton *Home_RB;
    QLabel *StartingPointMap_L;
    QLabel *DestinationMap_L;
    QRadioButton *Market_RB;
    QPushButton *MapStart_B;
    QPushButton *MapDest_B;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *Paths_RBs;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(459, 530);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 441, 451));
        tabWidget->setTabShape(QTabWidget::Rounded);
        Manual_T = new QWidget();
        Manual_T->setObjectName(QStringLiteral("Manual_T"));
        DOWN_B = new QPushButton(Manual_T);
        DOWN_B->setObjectName(QStringLiteral("DOWN_B"));
        DOWN_B->setGeometry(QRect(180, 260, 71, 61));
        QIcon icon;
        icon.addFile(QStringLiteral(":/arrows/images/downimg.png"), QSize(), QIcon::Normal, QIcon::Off);
        DOWN_B->setIcon(icon);
        DOWN_B->setIconSize(QSize(65, 65));
        DOWN_B->setCheckable(true);
        LEFT_B = new QPushButton(Manual_T);
        LEFT_B->setObjectName(QStringLiteral("LEFT_B"));
        LEFT_B->setGeometry(QRect(60, 150, 71, 61));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/arrows/images/leftimg.png"), QSize(), QIcon::Normal, QIcon::Off);
        LEFT_B->setIcon(icon1);
        LEFT_B->setIconSize(QSize(65, 65));
        LEFT_B->setCheckable(true);
        RIGHT_B = new QPushButton(Manual_T);
        RIGHT_B->setObjectName(QStringLiteral("RIGHT_B"));
        RIGHT_B->setGeometry(QRect(300, 150, 71, 61));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/arrows/images/rightimg.png"), QSize(), QIcon::Normal, QIcon::Off);
        RIGHT_B->setIcon(icon2);
        RIGHT_B->setIconSize(QSize(65, 65));
        RIGHT_B->setCheckable(true);
        RIGHT_B->setAutoDefault(false);
        UP_B = new QPushButton(Manual_T);
        UP_B->setObjectName(QStringLiteral("UP_B"));
        UP_B->setGeometry(QRect(180, 40, 71, 61));
        UP_B->setAutoFillBackground(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/arrows/images/upimg.png"), QSize(), QIcon::Normal, QIcon::Off);
        UP_B->setIcon(icon3);
        UP_B->setIconSize(QSize(65, 65));
        UP_B->setCheckable(true);
        SpeedSlider = new QSlider(Manual_T);
        SpeedSlider->setObjectName(QStringLiteral("SpeedSlider"));
        SpeedSlider->setGeometry(QRect(130, 360, 160, 26));
        SpeedSlider->setMaximum(2);
        SpeedSlider->setPageStep(1);
        SpeedSlider->setOrientation(Qt::Horizontal);
        tabWidget->addTab(Manual_T, QString());
        SelfDriving_T = new QWidget();
        SelfDriving_T->setObjectName(QStringLiteral("SelfDriving_T"));
        graphicsView = new QGraphicsView(SelfDriving_T);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 130, 420, 280));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setLayoutDirection(Qt::LeftToRight);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        Go_B = new QPushButton(SelfDriving_T);
        Go_B->setObjectName(QStringLiteral("Go_B"));
        Go_B->setGeometry(QRect(150, 100, 105, 31));
        StartingPoint_L = new QLabel(SelfDriving_T);
        StartingPoint_L->setObjectName(QStringLiteral("StartingPoint_L"));
        StartingPoint_L->setGeometry(QRect(20, 10, 141, 23));
        Destination_L = new QLabel(SelfDriving_T);
        Destination_L->setObjectName(QStringLiteral("Destination_L"));
        Destination_L->setGeometry(QRect(260, 10, 141, 23));
        Work_RB = new QRadioButton(SelfDriving_T);
        Paths_RBs = new QButtonGroup(MainWindow);
        Paths_RBs->setObjectName(QStringLiteral("Paths_RBs"));
        Paths_RBs->addButton(Work_RB);
        Work_RB->setObjectName(QStringLiteral("Work_RB"));
        Work_RB->setGeometry(QRect(330, 140, 81, 28));
        Home_RB = new QRadioButton(SelfDriving_T);
        Paths_RBs->addButton(Home_RB);
        Home_RB->setObjectName(QStringLiteral("Home_RB"));
        Home_RB->setGeometry(QRect(30, 370, 81, 28));
        StartingPointMap_L = new QLabel(SelfDriving_T);
        StartingPointMap_L->setObjectName(QStringLiteral("StartingPointMap_L"));
        StartingPointMap_L->setGeometry(QRect(20, 40, 151, 23));
        StartingPointMap_L->setAlignment(Qt::AlignCenter);
        DestinationMap_L = new QLabel(SelfDriving_T);
        DestinationMap_L->setObjectName(QStringLiteral("DestinationMap_L"));
        DestinationMap_L->setGeometry(QRect(260, 40, 151, 23));
        DestinationMap_L->setAlignment(Qt::AlignCenter);
        Market_RB = new QRadioButton(SelfDriving_T);
        Market_RB->setObjectName(QStringLiteral("Market_RB"));
        Market_RB->setGeometry(QRect(190, 240, 125, 28));
        MapStart_B = new QPushButton(SelfDriving_T);
        MapStart_B->setObjectName(QStringLiteral("MapStart_B"));
        MapStart_B->setGeometry(QRect(200, 40, 41, 21));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/arrows/images/smallarrow_start.png"), QSize(), QIcon::Normal, QIcon::Off);
        MapStart_B->setIcon(icon4);
        MapStart_B->setIconSize(QSize(30, 35));
        MapDest_B = new QPushButton(SelfDriving_T);
        MapDest_B->setObjectName(QStringLiteral("MapDest_B"));
        MapDest_B->setGeometry(QRect(200, 10, 41, 21));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/arrows/images/smallarrow_dest.png"), QSize(), QIcon::Normal, QIcon::Off);
        MapDest_B->setIcon(icon5);
        MapDest_B->setIconSize(QSize(30, 35));
        tabWidget->addTab(SelfDriving_T, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 459, 29));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        RIGHT_B->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        DOWN_B->setText(QString());
        LEFT_B->setText(QString());
        RIGHT_B->setText(QString());
        UP_B->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Manual_T), QApplication::translate("MainWindow", "Manual", nullptr));
        Go_B->setText(QApplication::translate("MainWindow", "GO", nullptr));
        StartingPoint_L->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Starting Point</p></body></html>", nullptr));
        Destination_L->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Destination</p></body></html>", nullptr));
        Work_RB->setText(QApplication::translate("MainWindow", "WORK", nullptr));
        Home_RB->setText(QApplication::translate("MainWindow", "HOME", nullptr));
        StartingPointMap_L->setText(QApplication::translate("MainWindow", "Choose from map", nullptr));
        DestinationMap_L->setText(QApplication::translate("MainWindow", "Choose from map", nullptr));
        Market_RB->setText(QApplication::translate("MainWindow", "MARKET", nullptr));
        MapStart_B->setText(QString());
        MapDest_B->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(SelfDriving_T), QApplication::translate("MainWindow", "SelfDriving", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
