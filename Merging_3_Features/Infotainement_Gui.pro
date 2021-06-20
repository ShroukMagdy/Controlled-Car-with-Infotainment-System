#-------------------------------------------------
#
# Project created by QtCreator 2021-06-16T21:01:45
#
#-------------------------------------------------

QT       += core gui
QT      +=multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Infotainement_Gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        mainwindow.cpp \
    main.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    files.qrc

DISTFILES += \
    Resources/2Pac_EyesOnMe.mp3 \
    Resources/Coldplay_Adv.mp3 \
    Resources/Coldplay_ASkyFullOfStars.mp3 \
    Resources/EdSheeran_Galway Girl.mp3 \
    Resources/EdSheeran_ShapeofYou.mp3 \
    Resources/EdSheeran_Thinking_Out_Loud.mp3 \
    Resources/mzmar_el3sfor.mp3 \
    Resources/Taylor_Swift_Lover.mp3 \
    Resources/ImagineDragons_WhateverItTakes.mp4 \
    Resources/RagnBone_ManHumanOfficial.mp4 \
    Resources/Taylor_Swift_Lover.mp3

SUBDIRS += \
    Infotainement_Gui.pro
