#include "mainwindow.h"
#include <QApplication>
#include <qsplashscreen.h>
#include <QDesktopWidget>





int main(int argc, char *argv[])
{
    int screenWidth;
    int screenHeight;
    int x,y;

    QApplication a(argc, argv);

    /*Object creation*/
    QSplashScreen *splash=new QSplashScreen();

    /*Splash image path*/
    splash->setPixmap(QPixmap ("/home/banna/Qt/Splash/tesla2.jpg"));
    // "border-image: url(../Media/stars_2.jpg)"

    /*Show splash img*/
    splash->show();


    /*Object creation for mainwindow without show*/
    MainWindow w;
     w.setWindowFlags(Qt::FramelessWindowHint);

    /*Mainwindow centralized*/
    QDesktopWidget *desktop = QApplication::desktop();
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth - LCD_WIDTH) / 2;
    y = (screenHeight - LCD_HEIGHT) / 2;
    w.resize(LCD_WIDTH, LCD_HEIGHT);
    w.move( x, y );
    w.setWindowTitle("Infotainment");

    /*Timer*/
    QTimer::singleShot(2000, splash, &QWidget::close); // keep displayed for 5 seconds
    QTimer::singleShot(2000, &w, &QWidget::show); // keep displayed for 5 seconds

    return a.exec();
}
