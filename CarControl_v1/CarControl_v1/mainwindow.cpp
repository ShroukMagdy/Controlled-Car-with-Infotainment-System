#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QKeyEvent>
#include <wiringPi.h>
#include <QDebug>

/*************************************PINS*********************************/
#define MOTOR_ID0_PIN0  2
#define MOTOR_ID0_PIN1  3
#define MOTOR_ID1_PIN0  4
#define MOTOR_ID1_PIN1  5
/**************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initialize wiring pi and pins
    wiringPiSetup();
    pinMode(MOTOR_ID0_PIN0, OUTPUT);
    pinMode(MOTOR_ID0_PIN1, OUTPUT);
    pinMode(MOTOR_ID1_PIN0, OUTPUT);
    pinMode(MOTOR_ID1_PIN1, OUTPUT);
    //timer instance
    timer = new QTimer;
    //buttons images
    ui->UP_B->setIcon(QIcon("../images/upimg.png"));
    ui->UP_B->setIconSize(QSize(65,65));
    ui->DOWN_B->setIcon(QIcon("../images/downimg.png"));
    ui->DOWN_B->setIconSize(QSize(65,65));
    ui->RIGHT_B->setIcon(QIcon("../images/rightimg.png"));
    ui->RIGHT_B->setIconSize(QSize(65,65));
    ui->LEFT_B->setIcon(QIcon("../images/leftimg.png"));
    ui->LEFT_B->setIconSize(QSize(65,65));

    //timer function
    connect(timer,SIGNAL(timeout()),this,SLOT(Stop()));

    //mouse press
    connect(ui->UP_B,SIGNAL(pressed()),this,SLOT(Move_Forward()));
    connect(ui->UP_B,SIGNAL(released()),this,SLOT(Stop()));

    connect(ui->DOWN_B,SIGNAL(pressed()),this,SLOT(Move_Backward()));
    connect(ui->DOWN_B,SIGNAL(released()),this,SLOT(Stop()));

    connect(ui->RIGHT_B,SIGNAL(pressed()),this,SLOT(Move_Right()));
    connect(ui->RIGHT_B,SIGNAL(released()),this,SLOT(Stop()));

    connect(ui->LEFT_B,SIGNAL(pressed()),this,SLOT(Move_Left()));
    connect(ui->LEFT_B,SIGNAL(released()),this,SLOT(Stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *e){
    //forward
    if(e->key()==Qt::Key_W){
        timer->start(150);
        Move_Forward();
        ui->UP_B->setChecked(true);
        ui->UP_B->setFocus();
    }
    //backward
    else if(e->key()==Qt::Key_S){
        timer->start(150);
        Move_Backward();
        ui->DOWN_B->setChecked(true);
        ui->DOWN_B->setFocus();
    }
    //left
    else  if(e->key()==Qt::Key_A){
        timer->start(150);
        Move_Left();
        ui->LEFT_B->setChecked(true);
        ui->LEFT_B->setFocus();
    }
    //right
    else  if(e->key()==Qt::Key_D){
        timer->start(150);
        Move_Right();
        ui->RIGHT_B->setChecked(true);
        ui->RIGHT_B->setFocus();
    }


}
void MainWindow::keyReleaseEvent(QKeyEvent *e){
    if((e->key()==Qt::Key_W)||
            (e->key()==Qt::Key_S)||
            (e->key()==Qt::Key_A)||
            (e->key()==Qt::Key_D)){
        if(another_press==1){
            Stop();
            another_press=0;
        }

    }
    else{
        timer->stop();
        another_press=1;
    }
}
void MainWindow::Move_Forward(){
    digitalWrite(MOTOR_ID0_PIN0,HIGH);
    digitalWrite(MOTOR_ID0_PIN1,LOW);
    digitalWrite(MOTOR_ID1_PIN0,HIGH);
    digitalWrite(MOTOR_ID1_PIN1,LOW);
}
void MainWindow::Move_Backward(){
    digitalWrite(MOTOR_ID0_PIN0,HIGH);
    digitalWrite(MOTOR_ID0_PIN1,HIGH);
    digitalWrite(MOTOR_ID1_PIN0,HIGH);
    digitalWrite(MOTOR_ID1_PIN1,HIGH);
}
void MainWindow:: Move_Right(){
    digitalWrite(MOTOR_ID0_PIN0,LOW);
    digitalWrite(MOTOR_ID0_PIN1,LOW);
    digitalWrite(MOTOR_ID1_PIN0,LOW);
    digitalWrite(MOTOR_ID1_PIN1,LOW);
}
void MainWindow:: Move_Left(){
    digitalWrite(MOTOR_ID0_PIN0,LOW);
    digitalWrite(MOTOR_ID0_PIN1,LOW);
    digitalWrite(MOTOR_ID1_PIN0,LOW);
    digitalWrite(MOTOR_ID1_PIN1,LOW);
}
void MainWindow::Stop(){
    digitalWrite(MOTOR_ID0_PIN0,LOW);
    digitalWrite(MOTOR_ID0_PIN1,LOW);
    digitalWrite(MOTOR_ID1_PIN0,LOW);
    digitalWrite(MOTOR_ID1_PIN1,LOW);
    ui->UP_B->setChecked(false);
    ui->DOWN_B->setChecked(false);
    ui->RIGHT_B->setChecked(false);
    ui->LEFT_B->setChecked(false);
}
