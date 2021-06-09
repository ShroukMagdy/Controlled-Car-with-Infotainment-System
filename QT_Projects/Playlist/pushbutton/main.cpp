#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    wiringPiSetup();
    pinMode(4, OUTPUT);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
