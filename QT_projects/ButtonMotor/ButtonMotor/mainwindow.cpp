#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <wiringPi.h>

#define MOTOR_ID0_PIN0  2
#define MOTOR_ID0_PIN1  3
#define MOTOR_ID1_PIN0  4
#define MOTOR_ID1_PIN1  5

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer= new QTimer(this);
    //initialize wiringpi setup
    wiringPiSetup();
    pinMode(MOTOR_ID0_PIN0,OUTPUT);
    pinMode(MOTOR_ID0_PIN1,OUTPUT);
    pinMode(MOTOR_ID1_PIN0,OUTPUT);
    pinMode(MOTOR_ID1_PIN1,OUTPUT);

    connect(ui->pushButton_Forward,SIGNAL(pressed()),this,SLOT ( Move_Forward() ) ) ;
    connect(ui->pushButton_Forward,SIGNAL(released()),this,SLOT ( Move_Stop () ) ) ;
    connect(ui->pushButton_Backward,SIGNAL(pressed()),this,SLOT ( Move_Backward () ) ) ;
    connect(ui->pushButton_Backward,SIGNAL(released()),this,SLOT ( Move_Stop () ) ) ;


    connect(timer,SIGNAL(timeout()),this,SLOT ( Timer_CbkFn() ));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow:: Move_Forward (){
    timer->start(100);
    digitalWrite(MOTOR_ID0_PIN0,HIGH);
    digitalWrite(MOTOR_ID0_PIN1,LOW);
    digitalWrite(MOTOR_ID1_PIN0,HIGH);
    digitalWrite(MOTOR_ID1_PIN1,LOW);
}
void MainWindow:: Move_Backward (){
    timer->start(100);
    digitalWrite(MOTOR_ID0_PIN0,LOW);
    digitalWrite(MOTOR_ID0_PIN1,HIGH);
    digitalWrite(MOTOR_ID1_PIN0,LOW);
    digitalWrite(MOTOR_ID1_PIN1,HIGH);
}
void MainWindow:: Move_Stop (){
    timer->stop();
    digitalWrite(MOTOR_ID0_PIN0,LOW);
    digitalWrite(MOTOR_ID0_PIN1,LOW);
    digitalWrite(MOTOR_ID1_PIN0,LOW);
    digitalWrite(MOTOR_ID1_PIN1,LOW);

}
void MainWindow::Timer_CbkFn(){
    ui->label_State->setText((QString::number(counter)));
    counter++;
}
