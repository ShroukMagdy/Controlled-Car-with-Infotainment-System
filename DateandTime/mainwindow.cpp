#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    /*Start timer*/
    /*the timer used to update the clock every 1 Sec*/
    connect(Timer,SIGNAL(timeout()),this , SLOT(ClockUpdate()) );
    Timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_MonthComboBox_currentIndexChanged(int index)
{
    /*Note : the time is calculated manually by coding due to some requirments but you can use QDateTime class to allow the Qt to access the hardware of your machine to get the time*/
    /*variable decleration*/

    /*Flags used to know the number of days of the previous month to either take 2 actions either remove or add item inside combobox*/
    /*Note : as Months not the same in number of days i use these flags to show inside the combobox the correct nuber of days 29 , 30 ,31*/

    /*Example : if the last selected month was 29 and the current selected month 30 so i will add one more item*/
    static unsigned char Flag_31=0;
    static unsigned char Flag_30=0;
    static unsigned char Flag_29=0;


    /*check on input index to know the selected month (the month which consist of 31 days)*/
    if(index == 1 || index == 3 || index == 5 || index == 7 || index == 8 || index == 10 || index == 12)
    {

        /*Check on the previous month selected either 30 or 29 and then add or remove items*/
        if(Flag_30==1 && Flag_31==0 && Flag_29==0)
        {
            ui->DayComboBox->addItem("31");
        }
        else if(Flag_30==0 && Flag_31==0 && Flag_29==1)
        {
            ui->DayComboBox->addItem("30");
            ui->DayComboBox->addItem("31");
        }
        Flag_31=1;
        Flag_30=0;
        Flag_29=0;
    }

    else if(index == 4 || index == 6 || index == 9|| index == 11)
    {
        if(Flag_30==0 && Flag_31==0 && Flag_29==1)
        {
            ui->DayComboBox->addItem("30");
        }
        else if(Flag_30==0 && Flag_31==1 && Flag_29==0)
        {
            ui->DayComboBox->removeItem(31);
        }
        Flag_31=0;
        Flag_30=1;
        Flag_29=0;
    }

    else if(index==2)
    {
        if(Flag_30==1 && Flag_31==0 && Flag_29==0)
        {
            ui->DayComboBox->removeItem(30);
        }
        else if(Flag_30==0 && Flag_31==1 && Flag_29==0)
        {
            ui->DayComboBox->removeItem(31);
            ui->DayComboBox->removeItem(30);
        }
        Flag_31=0;
        Flag_30=0;
        Flag_29=1;
    }

}





void MainWindow::on_Date_OK_clicked()
{

    /*these local variables are used to read the data inserted by the user and check on it first before changing the global
     * main variables to avoid wrong entrance*/
    unsigned char Day       ;
    unsigned char Month      ;
    unsigned char Year     ;
    unsigned char Hours      ;
    unsigned char Minutes    ;
    unsigned char DayNight ;


    /*reading the index from the combobox*/
    Day = ui->DayComboBox->currentIndex();
    Month = ui->MonthComboBox->currentIndex();
    Year = ui->YearComboBox->currentIndex();
    Hours =ui->HoursComboBox->currentIndex();
    Minutes =ui->Minutes_ComboBox->currentIndex();
    DayNight=ui->DayNight->currentIndex();


    /*check on the data then assign it if its true*/
    if(Day !=0 && Month!=0 && Year!=0 &&Minutes!=0 && Hours!=0)
    {

        DayIndex=Day;
        MonthIndex=Month;
        YearIndex=Year;
        HoursIndex=Hours;
        MinutesIndex=Minutes;
        DayNightMode=DayNight;

        /*Convert the values inside the Maptable to string to can be displayed on Lables inside the GUI*/
        QString Day = QString::number(DayIndex);
        QString Year = QString::number(Year_MapTable[YearIndex-1]);
        ui->Date->setText(Day+" "+Month_MapTable[MonthIndex-1]+" "+Year);

        QString Hours = QString::number(HoursIndex);
        QString Minutes = QString::number(MinutesIndex);
        QString seconds = QString::number(sec);

        /*Set the Data on the GUI label*/
        ui->Time->setText(Hours+":"+Minutes+":"+seconds+DayNight_MapTable[DayNightMode]);
        /*clear any old error msg*/
        ui->ErrorMsg->clear();

    }
    else
    {
        /*show error msg if there is no data entered*/
        ui->ErrorMsg->setText("Data you entered is not correct");
    }


}







/*Simple LOgic for calculating the time */
void MainWindow::ClockUpdate()
{

    sec++;
    if(sec==59 )
    {
        MinutesIndex++;
        sec=0;
    }

    if(MinutesIndex==59)
    {
        HoursIndex++;
        MinutesIndex=0;
    }

    if(HoursIndex==12)
    {
        HoursIndex=1;
        DayIndex++;
    }

    if(DayIndex==30)
    {
        DayIndex=0;
        MonthIndex++;
    }

    if(MonthIndex==12)
    {
        MonthIndex=1;
        YearIndex++;
    }

    /*Convert the values to string then show it on the time label*/
    QString Day = QString::number(DayIndex);
    QString Year = QString::number(Year_MapTable[YearIndex-1]);
    ui->Date->setText(Day+" "+Month_MapTable[MonthIndex]+" "+Year);

    QString Hours = QString::number(HoursIndex);
    QString Minutes = QString::number(MinutesIndex);
    QString seconds = QString::number(sec);

    ui->Time->setText(Hours+":"+Minutes+":"+seconds+" "+DayNight_MapTable[DayNightMode]);



}
















