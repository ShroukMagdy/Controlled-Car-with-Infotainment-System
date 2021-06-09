#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <wiringPi.h>

#define LED_PIM  4

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer(this);
    //initialize wiringpi setup
    wiringPiSetup();
    pinMode(LED_PIM,OUTPUT);
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT ( Increment() ) ) ;
    connect(ui->pushButton,SIGNAL(released()),this,SLOT ( Stop () ) ) ;


    connect(timer,SIGNAL(timeout()),this,SLOT ( timer_Increment() ));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow:: Increment (){
    timer->start(100);
    digitalWrite(LED_PIM,HIGH);
}
void MainWindow:: Stop (){
    timer->stop();
    digitalWrite(LED_PIM,LOW);

}
void MainWindow::timer_Increment(){
    ui->label->setText((QString::number(counter)));
    counter++;
}
