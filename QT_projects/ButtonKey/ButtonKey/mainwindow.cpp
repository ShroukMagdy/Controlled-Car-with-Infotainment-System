#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <qtimer.h>
#include <QDebug>
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
    connect(ui->pushButton_Right,SIGNAL(pressed()),this,SLOT ( Move_Right () ) ) ;
    connect(ui->pushButton_Right,SIGNAL(released()),this,SLOT ( Move_Stop () ) ) ;
    connect(ui->pushButton_Left,SIGNAL(pressed()),this,SLOT ( Move_Left () ) ) ;
    connect(ui->pushButton_Left,SIGNAL(released()),this,SLOT ( Move_Stop () ) ) ;

    connect(timer,SIGNAL(timeout()),this,SLOT ( Timer_CbkFn() ));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow:: Move_Forward (){
    digitalWrite(MOTOR_ID0_PIN0,HIGH);
    digitalWrite(MOTOR_ID0_PIN1,LOW);
    digitalWrite(MOTOR_ID1_PIN0,HIGH);
    digitalWrite(MOTOR_ID1_PIN1,LOW);
}
void MainWindow:: Move_Backward (){
    digitalWrite(MOTOR_ID0_PIN0,LOW);
    digitalWrite(MOTOR_ID0_PIN1,HIGH);
    digitalWrite(MOTOR_ID1_PIN0,LOW);
    digitalWrite(MOTOR_ID1_PIN1,HIGH);
}
void MainWindow:: Move_Stop (){
    digitalWrite(MOTOR_ID0_PIN0,LOW);
    digitalWrite(MOTOR_ID0_PIN1,LOW);
    digitalWrite(MOTOR_ID1_PIN0,LOW);
    digitalWrite(MOTOR_ID1_PIN1,LOW);

}
void MainWindow:: Move_Right(){
    digitalWrite(MOTOR_ID0_PIN0,HIGH);
    digitalWrite(MOTOR_ID0_PIN1,LOW);
    digitalWrite(MOTOR_ID1_PIN0,LOW);
    digitalWrite(MOTOR_ID1_PIN1,LOW);
}
void MainWindow:: Move_Left(){
    digitalWrite(MOTOR_ID0_PIN0,LOW);
    digitalWrite(MOTOR_ID0_PIN1,LOW);
    digitalWrite(MOTOR_ID1_PIN0,HIGH);
    digitalWrite(MOTOR_ID1_PIN1,LOW);
}
void MainWindow::Timer_CbkFn(){
        Move_Stop ();
        timer->stop();
}
void MainWindow::keyPressEvent(QKeyEvent *e) {

    if (e->key()==Qt::Key_W){
        timer->start(150);
        Move_Forward ();
    }
    else if (e->key()==Qt::Key_S){
        timer->start(150);
        Move_Backward ();
    }
    else if (e->key()==Qt::Key_D){
        timer->start(150);
        Move_Right ();
    }
    else if (e->key()==Qt::Key_A){
        timer->start(150);
        Move_Left ();
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *e) {
   if(e->isAutoRepeat()){
            e->ignore();
    }
    else if ((e->key()==Qt::Key_W) || (e->key()==Qt::Key_S) ||
             (e->key()==Qt::Key_D) || (e->key()==Qt::Key_A)){
        if(flag==true){
            Move_Stop ();
            flag=false;
        }
    }
    else {
       flag=true;
       timer->stop();
    }
}
