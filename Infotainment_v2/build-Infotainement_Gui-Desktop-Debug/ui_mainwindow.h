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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *Pages_stack;
    QWidget *Home_widget;
    QPushButton *HomeW_MusicBtn;
    QPushButton *HomeW_VideoBtn;
    QPushButton *HomeW_SettingsBtn;
    QPushButton *HomeW_CameraBtn;
    QWidget *Settings_widget;
    QPushButton *SettingsW_EscBtn;
    QComboBox *Minutes_ComboBox;
    QComboBox *DayComboBox;
    QComboBox *HoursComboBox;
    QComboBox *DayNight;
    QPushButton *Date_OK;
    QLineEdit *ErrorMsg;
    QComboBox *MonthComboBox;
    QComboBox *YearComboBox;
    QLabel *Date_2;
    QLabel *Time_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *Music_widget;
    QPushButton *PauseButton;
    QLabel *VolumeUp;
    QLabel *VolumeDown;
    QPushButton *NextButton;
    QScrollArea *scrollArea;
    QWidget *ScrollSong;
    QPushButton *PrevButton;
    QSlider *verticalSlider;
    QPushButton *StartButton;
    QRadioButton *MuteRadioButton;
    QPushButton *MusicW_EscBtn;
    QLabel *CurrentSong_Label;
    QWidget *Video_widget;
    QPushButton *VideoW_EscBtn;
    QPushButton *VideoPlay;
    QRadioButton *MuteRadioButtom;
    QSlider *VideoHorizontalSlider;
    QPushButton *VideoPrevious;
    QPushButton *NextVideo;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Layout;
    QPushButton *VideoStop;
    QPushButton *VideoPause;
    QSlider *VerticalVolumeSlider;
    QWidget *Camera_Widget;
    QPushButton *CameraW_EscBtn;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaCamera;
    QLabel *Date;
    QLabel *Time;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1026, 582);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Pages_stack = new QStackedWidget(centralWidget);
        Pages_stack->setObjectName(QStringLiteral("Pages_stack"));
        Pages_stack->setGeometry(QRect(30, 80, 741, 361));
        Pages_stack->setAutoFillBackground(false);
        Pages_stack->setStyleSheet(QLatin1String("color: rgb(255, 170, 0);\n"
"font: 75 italic 48pt \"PibotoLt\";\n"
"\n"
""));
        Home_widget = new QWidget();
        Home_widget->setObjectName(QStringLiteral("Home_widget"));
        HomeW_MusicBtn = new QPushButton(Home_widget);
        HomeW_MusicBtn->setObjectName(QStringLiteral("HomeW_MusicBtn"));
        HomeW_MusicBtn->setGeometry(QRect(60, 10, 151, 91));
        HomeW_VideoBtn = new QPushButton(Home_widget);
        HomeW_VideoBtn->setObjectName(QStringLiteral("HomeW_VideoBtn"));
        HomeW_VideoBtn->setGeometry(QRect(440, 10, 151, 91));
        HomeW_SettingsBtn = new QPushButton(Home_widget);
        HomeW_SettingsBtn->setObjectName(QStringLiteral("HomeW_SettingsBtn"));
        HomeW_SettingsBtn->setGeometry(QRect(430, 250, 161, 91));
        HomeW_CameraBtn = new QPushButton(Home_widget);
        HomeW_CameraBtn->setObjectName(QStringLiteral("HomeW_CameraBtn"));
        HomeW_CameraBtn->setGeometry(QRect(70, 240, 151, 91));
        Pages_stack->addWidget(Home_widget);
        Settings_widget = new QWidget();
        Settings_widget->setObjectName(QStringLiteral("Settings_widget"));
        SettingsW_EscBtn = new QPushButton(Settings_widget);
        SettingsW_EscBtn->setObjectName(QStringLiteral("SettingsW_EscBtn"));
        SettingsW_EscBtn->setGeometry(QRect(310, 310, 51, 51));
        Minutes_ComboBox = new QComboBox(Settings_widget);
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->addItem(QString());
        Minutes_ComboBox->setObjectName(QStringLiteral("Minutes_ComboBox"));
        Minutes_ComboBox->setGeometry(QRect(240, 130, 121, 31));
        QFont font;
        font.setFamily(QStringLiteral("Century Schoolbook L"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(9);
        Minutes_ComboBox->setFont(font);
        Minutes_ComboBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(233, 185, 110);\n"
"font: 75 italic 18pt \"Century Schoolbook L\";\n"
""));
        DayComboBox = new QComboBox(Settings_widget);
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->addItem(QString());
        DayComboBox->setObjectName(QStringLiteral("DayComboBox"));
        DayComboBox->setGeometry(QRect(240, 30, 121, 31));
        DayComboBox->setFont(font);
        DayComboBox->setAutoFillBackground(false);
        DayComboBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(233, 185, 110);\n"
"font: 75 italic 18pt \"Century Schoolbook L\";\n"
""));
        HoursComboBox = new QComboBox(Settings_widget);
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->addItem(QString());
        HoursComboBox->setObjectName(QStringLiteral("HoursComboBox"));
        HoursComboBox->setGeometry(QRect(95, 130, 111, 31));
        HoursComboBox->setFont(font);
        HoursComboBox->setAutoFillBackground(false);
        HoursComboBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(233, 185, 110);\n"
"font: 75 italic 18pt \"Century Schoolbook L\";\n"
""));
        DayNight = new QComboBox(Settings_widget);
        DayNight->addItem(QString());
        DayNight->addItem(QString());
        DayNight->setObjectName(QStringLiteral("DayNight"));
        DayNight->setGeometry(QRect(400, 130, 91, 31));
        DayNight->setFont(font);
        DayNight->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(233, 185, 110);\n"
"font: 75 italic 18pt \"Century Schoolbook L\";\n"
""));
        Date_OK = new QPushButton(Settings_widget);
        Date_OK->setObjectName(QStringLiteral("Date_OK"));
        Date_OK->setGeometry(QRect(550, 80, 89, 31));
        Date_OK->setFont(font);
        Date_OK->setStyleSheet(QLatin1String("font: 75 italic 18pt \"Century Schoolbook L\";\n"
"color: rgb(0, 0, 0);"));
        Date_OK->setAutoDefault(false);
        Date_OK->setFlat(false);
        ErrorMsg = new QLineEdit(Settings_widget);
        ErrorMsg->setObjectName(QStringLiteral("ErrorMsg"));
        ErrorMsg->setGeometry(QRect(100, 220, 291, 25));
        ErrorMsg->setStyleSheet(QLatin1String("font: 75 italic 12pt \"Century Schoolbook L\";\n"
"color: rgb(0, 0, 0);"));
        MonthComboBox = new QComboBox(Settings_widget);
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->addItem(QString());
        MonthComboBox->setObjectName(QStringLiteral("MonthComboBox"));
        MonthComboBox->setGeometry(QRect(95, 30, 111, 31));
        MonthComboBox->setFont(font);
        MonthComboBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(233, 185, 110);\n"
"font: 75 italic 18pt \"Century Schoolbook L\";\n"
""));
        MonthComboBox->setEditable(false);
        MonthComboBox->setMaxVisibleItems(200);
        MonthComboBox->setMaxCount(5555);
        YearComboBox = new QComboBox(Settings_widget);
        YearComboBox->addItem(QString());
        YearComboBox->addItem(QString());
        YearComboBox->addItem(QString());
        YearComboBox->setObjectName(QStringLiteral("YearComboBox"));
        YearComboBox->setGeometry(QRect(400, 30, 91, 31));
        YearComboBox->setFont(font);
        YearComboBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(233, 185, 110);\n"
"font: 75 italic 18pt \"Century Schoolbook L\";\n"
""));
        Date_2 = new QLabel(Settings_widget);
        Date_2->setObjectName(QStringLiteral("Date_2"));
        Date_2->setGeometry(QRect(1240, 170, 141, 21));
        Time_2 = new QLabel(Settings_widget);
        Time_2->setObjectName(QStringLiteral("Time_2"));
        Time_2->setGeometry(QRect(1370, 170, 111, 21));
        label = new QLabel(Settings_widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 0, 91, 22));
        label->setStyleSheet(QStringLiteral("font: 75 italic 18pt \"Century Schoolbook L\";"));
        label_2 = new QLabel(Settings_widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 0, 91, 22));
        label_2->setStyleSheet(QStringLiteral("font: 75 italic 18pt \"Century Schoolbook L\";"));
        label_3 = new QLabel(Settings_widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(410, 0, 91, 22));
        label_3->setStyleSheet(QStringLiteral("font: 75 italic 18pt \"Century Schoolbook L\";"));
        label_4 = new QLabel(Settings_widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 100, 91, 22));
        label_4->setStyleSheet(QStringLiteral("font: 75 italic 18pt \"Century Schoolbook L\";"));
        label_5 = new QLabel(Settings_widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(250, 100, 91, 22));
        label_5->setStyleSheet(QLatin1String("font: 75 italic 18pt \"Century Schoolbook L\";\n"
""));
        label_6 = new QLabel(Settings_widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(410, 100, 101, 22));
        label_6->setStyleSheet(QStringLiteral("font: 75 italic 18pt \"Century Schoolbook L\";"));
        Pages_stack->addWidget(Settings_widget);
        SettingsW_EscBtn->raise();
        Minutes_ComboBox->raise();
        DayComboBox->raise();
        HoursComboBox->raise();
        DayNight->raise();
        Date_OK->raise();
        ErrorMsg->raise();
        YearComboBox->raise();
        MonthComboBox->raise();
        Date_2->raise();
        Time_2->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        Music_widget = new QWidget();
        Music_widget->setObjectName(QStringLiteral("Music_widget"));
        PauseButton = new QPushButton(Music_widget);
        PauseButton->setObjectName(QStringLiteral("PauseButton"));
        PauseButton->setGeometry(QRect(210, 230, 61, 51));
        VolumeUp = new QLabel(Music_widget);
        VolumeUp->setObjectName(QStringLiteral("VolumeUp"));
        VolumeUp->setGeometry(QRect(700, 40, 16, 16));
        VolumeDown = new QLabel(Music_widget);
        VolumeDown->setObjectName(QStringLiteral("VolumeDown"));
        VolumeDown->setGeometry(QRect(700, 211, 16, 20));
        NextButton = new QPushButton(Music_widget);
        NextButton->setObjectName(QStringLiteral("NextButton"));
        NextButton->setGeometry(QRect(550, 230, 61, 51));
        scrollArea = new QScrollArea(Music_widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 40, 651, 181));
        scrollArea->setStyleSheet(QStringLiteral("font: 75 italic 18pt \"Century Schoolbook L\";"));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        ScrollSong = new QWidget();
        ScrollSong->setObjectName(QStringLiteral("ScrollSong"));
        ScrollSong->setGeometry(QRect(0, 0, 634, 177));
        ScrollSong->setStyleSheet(QStringLiteral("color: rgb(238, 238, 236);"));
        scrollArea->setWidget(ScrollSong);
        PrevButton = new QPushButton(Music_widget);
        PrevButton->setObjectName(QStringLiteral("PrevButton"));
        PrevButton->setGeometry(QRect(50, 230, 61, 51));
        verticalSlider = new QSlider(Music_widget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(680, 40, 21, 191));
        verticalSlider->setOrientation(Qt::Vertical);
        StartButton = new QPushButton(Music_widget);
        StartButton->setObjectName(QStringLiteral("StartButton"));
        StartButton->setGeometry(QRect(400, 230, 61, 51));
        MuteRadioButton = new QRadioButton(Music_widget);
        MuteRadioButton->setObjectName(QStringLiteral("MuteRadioButton"));
        MuteRadioButton->setGeometry(QRect(670, 250, 41, 51));
        MusicW_EscBtn = new QPushButton(Music_widget);
        MusicW_EscBtn->setObjectName(QStringLiteral("MusicW_EscBtn"));
        MusicW_EscBtn->setGeometry(QRect(310, 310, 51, 51));
        CurrentSong_Label = new QLabel(Music_widget);
        CurrentSong_Label->setObjectName(QStringLiteral("CurrentSong_Label"));
        CurrentSong_Label->setGeometry(QRect(20, 0, 511, 31));
        CurrentSong_Label->setStyleSheet(QLatin1String("font: 75 italic 16pt \"Century Schoolbook L\";\n"
"color: rgb(255, 170, 0);"));
        Pages_stack->addWidget(Music_widget);
        Video_widget = new QWidget();
        Video_widget->setObjectName(QStringLiteral("Video_widget"));
        VideoW_EscBtn = new QPushButton(Video_widget);
        VideoW_EscBtn->setObjectName(QStringLiteral("VideoW_EscBtn"));
        VideoW_EscBtn->setGeometry(QRect(310, 310, 51, 51));
        VideoPlay = new QPushButton(Video_widget);
        VideoPlay->setObjectName(QStringLiteral("VideoPlay"));
        VideoPlay->setGeometry(QRect(420, 220, 61, 51));
        MuteRadioButtom = new QRadioButton(Video_widget);
        MuteRadioButtom->setObjectName(QStringLiteral("MuteRadioButtom"));
        MuteRadioButtom->setGeometry(QRect(620, 240, 61, 51));
        VideoHorizontalSlider = new QSlider(Video_widget);
        VideoHorizontalSlider->setObjectName(QStringLiteral("VideoHorizontalSlider"));
        VideoHorizontalSlider->setGeometry(QRect(20, 200, 581, 16));
        VideoHorizontalSlider->setMaximum(1000);
        VideoHorizontalSlider->setOrientation(Qt::Horizontal);
        VideoPrevious = new QPushButton(Video_widget);
        VideoPrevious->setObjectName(QStringLiteral("VideoPrevious"));
        VideoPrevious->setGeometry(QRect(60, 220, 61, 51));
        NextVideo = new QPushButton(Video_widget);
        NextVideo->setObjectName(QStringLiteral("NextVideo"));
        NextVideo->setGeometry(QRect(540, 220, 61, 51));
        verticalLayoutWidget = new QWidget(Video_widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 601, 191));
        Layout = new QVBoxLayout(verticalLayoutWidget);
        Layout->setSpacing(6);
        Layout->setContentsMargins(11, 11, 11, 11);
        Layout->setObjectName(QStringLiteral("Layout"));
        Layout->setContentsMargins(0, 0, 0, 0);
        VideoStop = new QPushButton(Video_widget);
        VideoStop->setObjectName(QStringLiteral("VideoStop"));
        VideoStop->setGeometry(QRect(180, 220, 61, 51));
        VideoPause = new QPushButton(Video_widget);
        VideoPause->setObjectName(QStringLiteral("VideoPause"));
        VideoPause->setGeometry(QRect(300, 220, 61, 51));
        VerticalVolumeSlider = new QSlider(Video_widget);
        VerticalVolumeSlider->setObjectName(QStringLiteral("VerticalVolumeSlider"));
        VerticalVolumeSlider->setGeometry(QRect(630, 20, 41, 211));
        VerticalVolumeSlider->setOrientation(Qt::Vertical);
        Pages_stack->addWidget(Video_widget);
        Camera_Widget = new QWidget();
        Camera_Widget->setObjectName(QStringLiteral("Camera_Widget"));
        CameraW_EscBtn = new QPushButton(Camera_Widget);
        CameraW_EscBtn->setObjectName(QStringLiteral("CameraW_EscBtn"));
        CameraW_EscBtn->setGeometry(QRect(310, 310, 51, 51));
        scrollArea_2 = new QScrollArea(Camera_Widget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(30, 0, 681, 281));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaCamera = new QWidget();
        scrollAreaCamera->setObjectName(QStringLiteral("scrollAreaCamera"));
        scrollAreaCamera->setGeometry(QRect(0, 0, 679, 279));
        scrollArea_2->setWidget(scrollAreaCamera);
        Pages_stack->addWidget(Camera_Widget);
        Date = new QLabel(centralWidget);
        Date->setObjectName(QStringLiteral("Date"));
        Date->setGeometry(QRect(670, 0, 161, 21));
        Date->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        Time = new QLabel(centralWidget);
        Time->setObjectName(QStringLiteral("Time"));
        Time->setGeometry(QRect(570, 0, 101, 21));
        Time->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1026, 28));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        Pages_stack->setCurrentIndex(0);
        Date_OK->setDefault(false);
        MonthComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        HomeW_MusicBtn->setText(QString());
        HomeW_VideoBtn->setText(QString());
        HomeW_SettingsBtn->setText(QString());
        HomeW_CameraBtn->setText(QString());
        SettingsW_EscBtn->setText(QString());
        Minutes_ComboBox->setItemText(0, QApplication::translate("MainWindow", "Minutes", nullptr));
        Minutes_ComboBox->setItemText(1, QApplication::translate("MainWindow", "1", nullptr));
        Minutes_ComboBox->setItemText(2, QApplication::translate("MainWindow", "2", nullptr));
        Minutes_ComboBox->setItemText(3, QApplication::translate("MainWindow", "3", nullptr));
        Minutes_ComboBox->setItemText(4, QApplication::translate("MainWindow", "4", nullptr));
        Minutes_ComboBox->setItemText(5, QApplication::translate("MainWindow", "5", nullptr));
        Minutes_ComboBox->setItemText(6, QApplication::translate("MainWindow", "6", nullptr));
        Minutes_ComboBox->setItemText(7, QApplication::translate("MainWindow", "7", nullptr));
        Minutes_ComboBox->setItemText(8, QApplication::translate("MainWindow", "8", nullptr));
        Minutes_ComboBox->setItemText(9, QApplication::translate("MainWindow", "9", nullptr));
        Minutes_ComboBox->setItemText(10, QApplication::translate("MainWindow", "10", nullptr));
        Minutes_ComboBox->setItemText(11, QApplication::translate("MainWindow", "11", nullptr));
        Minutes_ComboBox->setItemText(12, QApplication::translate("MainWindow", "12", nullptr));
        Minutes_ComboBox->setItemText(13, QApplication::translate("MainWindow", "13", nullptr));
        Minutes_ComboBox->setItemText(14, QApplication::translate("MainWindow", "14", nullptr));
        Minutes_ComboBox->setItemText(15, QApplication::translate("MainWindow", "15", nullptr));
        Minutes_ComboBox->setItemText(16, QApplication::translate("MainWindow", "16", nullptr));
        Minutes_ComboBox->setItemText(17, QApplication::translate("MainWindow", "17", nullptr));
        Minutes_ComboBox->setItemText(18, QApplication::translate("MainWindow", "18", nullptr));
        Minutes_ComboBox->setItemText(19, QApplication::translate("MainWindow", "19", nullptr));
        Minutes_ComboBox->setItemText(20, QApplication::translate("MainWindow", "20", nullptr));
        Minutes_ComboBox->setItemText(21, QApplication::translate("MainWindow", "21", nullptr));
        Minutes_ComboBox->setItemText(22, QApplication::translate("MainWindow", "22", nullptr));
        Minutes_ComboBox->setItemText(23, QApplication::translate("MainWindow", "23", nullptr));
        Minutes_ComboBox->setItemText(24, QApplication::translate("MainWindow", "24", nullptr));
        Minutes_ComboBox->setItemText(25, QApplication::translate("MainWindow", "25", nullptr));
        Minutes_ComboBox->setItemText(26, QApplication::translate("MainWindow", "26", nullptr));
        Minutes_ComboBox->setItemText(27, QApplication::translate("MainWindow", "27", nullptr));
        Minutes_ComboBox->setItemText(28, QApplication::translate("MainWindow", "28", nullptr));
        Minutes_ComboBox->setItemText(29, QApplication::translate("MainWindow", "29", nullptr));
        Minutes_ComboBox->setItemText(30, QApplication::translate("MainWindow", "30", nullptr));
        Minutes_ComboBox->setItemText(31, QApplication::translate("MainWindow", "31", nullptr));
        Minutes_ComboBox->setItemText(32, QApplication::translate("MainWindow", "32", nullptr));
        Minutes_ComboBox->setItemText(33, QApplication::translate("MainWindow", "33", nullptr));
        Minutes_ComboBox->setItemText(34, QApplication::translate("MainWindow", "34", nullptr));
        Minutes_ComboBox->setItemText(35, QApplication::translate("MainWindow", "35", nullptr));
        Minutes_ComboBox->setItemText(36, QApplication::translate("MainWindow", "36", nullptr));
        Minutes_ComboBox->setItemText(37, QApplication::translate("MainWindow", "37", nullptr));
        Minutes_ComboBox->setItemText(38, QApplication::translate("MainWindow", "38", nullptr));
        Minutes_ComboBox->setItemText(39, QApplication::translate("MainWindow", "39", nullptr));
        Minutes_ComboBox->setItemText(40, QApplication::translate("MainWindow", "40", nullptr));
        Minutes_ComboBox->setItemText(41, QApplication::translate("MainWindow", "41", nullptr));
        Minutes_ComboBox->setItemText(42, QApplication::translate("MainWindow", "42", nullptr));
        Minutes_ComboBox->setItemText(43, QApplication::translate("MainWindow", "43", nullptr));
        Minutes_ComboBox->setItemText(44, QApplication::translate("MainWindow", "44", nullptr));
        Minutes_ComboBox->setItemText(45, QApplication::translate("MainWindow", "45", nullptr));
        Minutes_ComboBox->setItemText(46, QApplication::translate("MainWindow", "46", nullptr));
        Minutes_ComboBox->setItemText(47, QApplication::translate("MainWindow", "47", nullptr));
        Minutes_ComboBox->setItemText(48, QApplication::translate("MainWindow", "48", nullptr));
        Minutes_ComboBox->setItemText(49, QApplication::translate("MainWindow", "49", nullptr));
        Minutes_ComboBox->setItemText(50, QApplication::translate("MainWindow", "50", nullptr));
        Minutes_ComboBox->setItemText(51, QApplication::translate("MainWindow", "51", nullptr));
        Minutes_ComboBox->setItemText(52, QApplication::translate("MainWindow", "52", nullptr));
        Minutes_ComboBox->setItemText(53, QApplication::translate("MainWindow", "53", nullptr));
        Minutes_ComboBox->setItemText(54, QApplication::translate("MainWindow", "54", nullptr));
        Minutes_ComboBox->setItemText(55, QApplication::translate("MainWindow", "55", nullptr));
        Minutes_ComboBox->setItemText(56, QApplication::translate("MainWindow", "56", nullptr));
        Minutes_ComboBox->setItemText(57, QApplication::translate("MainWindow", "57", nullptr));
        Minutes_ComboBox->setItemText(58, QApplication::translate("MainWindow", "58", nullptr));
        Minutes_ComboBox->setItemText(59, QApplication::translate("MainWindow", "59", nullptr));

        DayComboBox->setItemText(0, QApplication::translate("MainWindow", "Day", nullptr));
        DayComboBox->setItemText(1, QApplication::translate("MainWindow", "1", nullptr));
        DayComboBox->setItemText(2, QApplication::translate("MainWindow", "2", nullptr));
        DayComboBox->setItemText(3, QApplication::translate("MainWindow", "3", nullptr));
        DayComboBox->setItemText(4, QApplication::translate("MainWindow", "4", nullptr));
        DayComboBox->setItemText(5, QApplication::translate("MainWindow", "5", nullptr));
        DayComboBox->setItemText(6, QApplication::translate("MainWindow", "6", nullptr));
        DayComboBox->setItemText(7, QApplication::translate("MainWindow", "7", nullptr));
        DayComboBox->setItemText(8, QApplication::translate("MainWindow", "8", nullptr));
        DayComboBox->setItemText(9, QApplication::translate("MainWindow", "9", nullptr));
        DayComboBox->setItemText(10, QApplication::translate("MainWindow", "10", nullptr));
        DayComboBox->setItemText(11, QApplication::translate("MainWindow", "11", nullptr));
        DayComboBox->setItemText(12, QApplication::translate("MainWindow", "12", nullptr));
        DayComboBox->setItemText(13, QApplication::translate("MainWindow", "13", nullptr));
        DayComboBox->setItemText(14, QApplication::translate("MainWindow", "14", nullptr));
        DayComboBox->setItemText(15, QApplication::translate("MainWindow", "15", nullptr));
        DayComboBox->setItemText(16, QApplication::translate("MainWindow", "16", nullptr));
        DayComboBox->setItemText(17, QApplication::translate("MainWindow", "17", nullptr));
        DayComboBox->setItemText(18, QApplication::translate("MainWindow", "18", nullptr));
        DayComboBox->setItemText(19, QApplication::translate("MainWindow", "19", nullptr));
        DayComboBox->setItemText(20, QApplication::translate("MainWindow", "20", nullptr));
        DayComboBox->setItemText(21, QApplication::translate("MainWindow", "21", nullptr));
        DayComboBox->setItemText(22, QApplication::translate("MainWindow", "22", nullptr));
        DayComboBox->setItemText(23, QApplication::translate("MainWindow", "23", nullptr));
        DayComboBox->setItemText(24, QApplication::translate("MainWindow", "24", nullptr));
        DayComboBox->setItemText(25, QApplication::translate("MainWindow", "25", nullptr));
        DayComboBox->setItemText(26, QApplication::translate("MainWindow", "26", nullptr));
        DayComboBox->setItemText(27, QApplication::translate("MainWindow", "27", nullptr));
        DayComboBox->setItemText(28, QApplication::translate("MainWindow", "28", nullptr));
        DayComboBox->setItemText(29, QApplication::translate("MainWindow", "29", nullptr));
        DayComboBox->setItemText(30, QApplication::translate("MainWindow", "30", nullptr));
        DayComboBox->setItemText(31, QApplication::translate("MainWindow", "31", nullptr));

        HoursComboBox->setItemText(0, QApplication::translate("MainWindow", "Hours", nullptr));
        HoursComboBox->setItemText(1, QApplication::translate("MainWindow", "1", nullptr));
        HoursComboBox->setItemText(2, QApplication::translate("MainWindow", "2", nullptr));
        HoursComboBox->setItemText(3, QApplication::translate("MainWindow", "3", nullptr));
        HoursComboBox->setItemText(4, QApplication::translate("MainWindow", "4", nullptr));
        HoursComboBox->setItemText(5, QApplication::translate("MainWindow", "5", nullptr));
        HoursComboBox->setItemText(6, QApplication::translate("MainWindow", "6", nullptr));
        HoursComboBox->setItemText(7, QApplication::translate("MainWindow", "7", nullptr));
        HoursComboBox->setItemText(8, QApplication::translate("MainWindow", "8", nullptr));
        HoursComboBox->setItemText(9, QApplication::translate("MainWindow", "9", nullptr));
        HoursComboBox->setItemText(10, QApplication::translate("MainWindow", "10", nullptr));
        HoursComboBox->setItemText(11, QApplication::translate("MainWindow", "11", nullptr));
        HoursComboBox->setItemText(12, QApplication::translate("MainWindow", "12", nullptr));

        DayNight->setItemText(0, QApplication::translate("MainWindow", "AM", nullptr));
        DayNight->setItemText(1, QApplication::translate("MainWindow", "PM", nullptr));

        Date_OK->setText(QApplication::translate("MainWindow", "OK", nullptr));
        MonthComboBox->setItemText(0, QApplication::translate("MainWindow", "Months", nullptr));
        MonthComboBox->setItemText(1, QApplication::translate("MainWindow", "Jan", nullptr));
        MonthComboBox->setItemText(2, QApplication::translate("MainWindow", "Feb", nullptr));
        MonthComboBox->setItemText(3, QApplication::translate("MainWindow", "March", nullptr));
        MonthComboBox->setItemText(4, QApplication::translate("MainWindow", "April", nullptr));
        MonthComboBox->setItemText(5, QApplication::translate("MainWindow", "May", nullptr));
        MonthComboBox->setItemText(6, QApplication::translate("MainWindow", "June", nullptr));
        MonthComboBox->setItemText(7, QApplication::translate("MainWindow", "July", nullptr));
        MonthComboBox->setItemText(8, QApplication::translate("MainWindow", "August", nullptr));
        MonthComboBox->setItemText(9, QApplication::translate("MainWindow", "September", nullptr));
        MonthComboBox->setItemText(10, QApplication::translate("MainWindow", "October", nullptr));
        MonthComboBox->setItemText(11, QApplication::translate("MainWindow", "November", nullptr));
        MonthComboBox->setItemText(12, QApplication::translate("MainWindow", "December", nullptr));

        YearComboBox->setItemText(0, QApplication::translate("MainWindow", "Year", nullptr));
        YearComboBox->setItemText(1, QApplication::translate("MainWindow", "2021", nullptr));
        YearComboBox->setItemText(2, QApplication::translate("MainWindow", "2022", nullptr));

        Date_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        Time_2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QApplication::translate("MainWindow", "Months", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Days", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Years", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Hours", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Minutes", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "AM/PM", nullptr));
        PauseButton->setText(QString());
        VolumeUp->setText(QString());
        VolumeDown->setText(QString());
        NextButton->setText(QString());
        PrevButton->setText(QString());
        StartButton->setText(QString());
        MuteRadioButton->setText(QString());
        MusicW_EscBtn->setText(QString());
        CurrentSong_Label->setText(QApplication::translate("MainWindow", "Playing", nullptr));
        VideoW_EscBtn->setText(QString());
        VideoPlay->setText(QString());
        MuteRadioButtom->setText(QString());
        VideoPrevious->setText(QString());
        NextVideo->setText(QString());
        VideoStop->setText(QString());
        VideoPause->setText(QString());
        CameraW_EscBtn->setText(QString());
        Date->setText(QString());
        Time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
