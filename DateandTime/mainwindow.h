#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QString>
#include <QTimer>
#include <QDateTime>


#define AM  0
#define PM  1

#define INITIAL_SECONDS     0
#define INITIAL_MINUTES     20
#define INITIAL_HOURS       9
#define INITIAL_MONTH       6
#define INITIAL_DAY         18
#define INITIAL_YEAR_INDEX  1
#define INITIAL_MODE_TIME   0


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    /*Variable that contain the indces of combobox and will be used to set the values of date and time*/
    /*some of them will be used directly(Days) and others we use the index to enter Maptable to get the equivilant date or time (MOnth , Year , AM&PM)*/
    unsigned char sec           =     INITIAL_SECONDS;
    unsigned char DayIndex      =     INITIAL_DAY;
    unsigned char MonthIndex    =     INITIAL_MONTH;
    unsigned char YearIndex     =     INITIAL_YEAR_INDEX;
    unsigned char HoursIndex    =     INITIAL_HOURS;
    unsigned char MinutesIndex  =     INITIAL_MINUTES;
    unsigned char DayNightMode  =     INITIAL_MODE_TIME;


    /*Maptable to get the equavilant value of index*/
    unsigned short int Year_MapTable[2]={2021,2022};
    QString Month_MapTable[12]={"Jan","Feb","March","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
    QString DayNight_MapTable[2]={"AM","PM"};

    /*object creation of timer class*/
    QTimer *Timer = new QTimer();

    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();

private slots:

    void on_MonthComboBox_currentIndexChanged(int index);
    void ClockUpdate();
    void on_Date_OK_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
