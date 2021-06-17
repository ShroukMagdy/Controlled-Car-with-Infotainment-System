#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QKeyEvent>
#include <wiringPi.h>
#include <softPwm.h>
#include <QDebug>

/*************************************PINS*********************************/
#define MOTOR_ID0_PWM                   1           //PWM
#define MOTOR_ID0_DIR                   4           //DIR
#define MOTOR_ID1_PWM                   26          //PWM
#define MOTOR_ID1_DIR                   5           //DIR

#define MOTOR_ID2_PWM                   2           //PWM
#define MOTOR_ID2_DIR                   3           //DIR

#define SPEED_FACTOR                    20
#define TIMER_TIMEOUT                   150
#define PWM_FRONT                       60          //fixed - done for optimization of rotation
/**************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initialize wiring pi and pins
    wiringPiSetup();
    //rear motors
    softPwmCreate(MOTOR_ID0_PWM,0,100);
    pinMode(MOTOR_ID0_DIR, OUTPUT);
    softPwmCreate(MOTOR_ID1_PWM,0,100);
    pinMode(MOTOR_ID1_DIR, OUTPUT);
    //front motor
    softPwmCreate(MOTOR_ID2_PWM,0,100);
    pinMode(MOTOR_ID2_DIR, OUTPUT);

    //initialize pins
    //rear motors
    softPwmWrite(MOTOR_ID0_PWM,0);
    digitalWrite(MOTOR_ID0_DIR,LOW);
    softPwmWrite(MOTOR_ID1_PWM,0);
    digitalWrite(MOTOR_ID1_DIR,LOW);
    //front motor
    softPwmWrite(MOTOR_ID2_PWM,0);
    digitalWrite(MOTOR_ID2_DIR,LOW);

    //timer instance
    timer = new QTimer;

    //timer function
    connect(timer,SIGNAL(timeout()),this,SLOT(Stop()));

    //mouse press
    connect(ui->UP_B,SIGNAL(pressed()),this,SLOT(Move_Forward()));
    connect(ui->UP_B,SIGNAL(released()),this,SLOT(StopRear()));

    connect(ui->DOWN_B,SIGNAL(pressed()),this,SLOT(Move_Backward()));
    connect(ui->DOWN_B,SIGNAL(released()),this,SLOT(StopRear()));

    connect(ui->RIGHT_B,SIGNAL(pressed()),this,SLOT(Move_Right()));
    connect(ui->RIGHT_B,SIGNAL(released()),this,SLOT(StopFront()));

    connect(ui->LEFT_B,SIGNAL(pressed()),this,SLOT(Move_Left()));
    connect(ui->LEFT_B,SIGNAL(released()),this,SLOT(StopFront()));
    //slider speed
    connect(ui->SpeedSlider,SIGNAL(valueChanged(int)),this,SLOT(CalculateSpeed(int)));

    //self driving mode
    //set ids for paths
    ui->Paths_RBs->setId(ui->Home_RB,HOME_PATH_ID);
    ui->Paths_RBs->setId(ui->Work_RB,WORK_PATH_ID);
    //initialize array of movement functions
    Move_Functions[0]= &MainWindow::Move_Forward;
    Move_Functions[1]= &MainWindow::Move_Backward;
    Move_Functions[2]= &MainWindow::Move_Right;
    Move_Functions[3]= &MainWindow::Move_Left;
    Move_Functions[4]= &MainWindow::StopFront;
    Move_Functions[5]= &MainWindow::StopRear;
    connect(ui->Go_B,SIGNAL(pressed()),this,SLOT(CheckPath()));
    /**********************************PATHS*************************************/
    QFile file("/home/pi/Programms/ITI_GP/CarControl_v2/Paths.txt");
    file.open(QIODevice::ReadWrite);
    if (!file.isOpen()){
        return;
    }
    QTextStream stream(&file);
    // read number of paths
    num_paths=(stream.readLine()).toInt();
    for (int path_count = 0; path_count < num_paths; path_count++){
        // read number of commands of the path
        num_path_command=(stream.readLine()).toInt();
        path_array_ptr[path_count] = new int*[num_path_command];
        for (int command_counter = 0; command_counter < num_path_command; command_counter++){
            path_array_ptr[path_count][command_counter] = new int[2];
            QString line = stream.readLine();
            for (int counter = 0; counter < 2; counter++){
                //read line of command
                path_array_ptr[path_count][command_counter][counter] = (line.split(" ")[counter]).toInt();
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *e){
    //forward
    if(e->key()==Qt::Key_W){
        timer->start(TIMER_TIMEOUT);
        Move_Forward();
        ui->UP_B->setChecked(true);
        ui->UP_B->setFocus();
    }
    //backward
    else if(e->key()==Qt::Key_S){
        timer->start(TIMER_TIMEOUT);
        Move_Backward();
        ui->DOWN_B->setChecked(true);
        ui->DOWN_B->setFocus();
    }
    //left
    else  if(e->key()==Qt::Key_A){
        timer->start(TIMER_TIMEOUT);
        Move_Left();
        ui->LEFT_B->setChecked(true);
        ui->LEFT_B->setFocus();
    }
    //right
    else  if(e->key()==Qt::Key_D){
        timer->start(TIMER_TIMEOUT);
        Move_Right();
        ui->RIGHT_B->setChecked(true);
        ui->RIGHT_B->setFocus();
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *e){
    if((e->key()==Qt::Key_W)||(e->key()==Qt::Key_S)){
        if(another_press==1){
            Stop();
            another_press=0;
        }
        if(FinalPress_RearMove==1){
            FinalPress_RearMove=0;
            StartPress_RearMove=0;
            StopRear();
        }
    }
    else if((e->key()==Qt::Key_A)||(e->key()==Qt::Key_D)){
        if(another_press==1){
            Stop();
            another_press=0;
        }
        if(FinalPress_FrontMove==1){
            FinalPress_FrontMove=0;
            StartPress_FrontMove=0;
            StopFront();
        }

    }
    else{
        timer->stop();
        another_press=1;
    }
}
void MainWindow::Move_Forward(){
    //update flags , 1 means current move , other flag just +2
    if((StartPress_RearMove==0)||(StartPress_FrontMove==1)){
        StartPress_RearMove=1;
        StartPress_FrontMove+=2;
        qDebug()<<"Forward";
        qDebug() << "RearMove="<<StartPress_RearMove;
        qDebug() << "FrontMove="<<StartPress_FrontMove;
    }

    //rear motors
    softPwmWrite(MOTOR_ID0_PWM,speed);
    digitalWrite(MOTOR_ID0_DIR,LOW);

    softPwmWrite(MOTOR_ID1_PWM,speed);
    digitalWrite(MOTOR_ID1_DIR,LOW);
}
void MainWindow::Move_Backward(){
    //update flags , 1 means current move , other flag just +2
    if((StartPress_RearMove==0)||(StartPress_FrontMove==1)){
        StartPress_RearMove=1;
        StartPress_FrontMove+=2;
        qDebug()<<"Backward";
        qDebug() << "RearMove="<<StartPress_RearMove;
        qDebug() << "FrontMove="<<StartPress_FrontMove;
    }

    //rear motors
    softPwmWrite(MOTOR_ID0_PWM,speed);
    digitalWrite(MOTOR_ID0_DIR,HIGH);

    softPwmWrite(MOTOR_ID1_PWM,speed);
    digitalWrite(MOTOR_ID1_DIR,HIGH);
}
void MainWindow:: Move_Right(){
    //update flags , 1 means current move , other flag just +2
    if((StartPress_FrontMove==0)||(StartPress_RearMove==1)){
        StartPress_FrontMove=1;
        StartPress_RearMove+=2;
        qDebug()<<"Right";
        qDebug() << "RearMove="<<StartPress_RearMove;
        qDebug() << "FrontMove="<<StartPress_FrontMove;
    }

    //front motor
    softPwmWrite(MOTOR_ID2_PWM,PWM_FRONT);
    digitalWrite(MOTOR_ID2_DIR,LOW);
}
void MainWindow:: Move_Left(){
    //update flags , 1 means current move , other flag just +2
    if((StartPress_FrontMove==0)||(StartPress_RearMove==1)){
        StartPress_FrontMove=1;
        StartPress_RearMove+=2;
        qDebug()<<"Left";
        qDebug() << "RearMove="<<StartPress_RearMove;
        qDebug() << "FrontMove="<<StartPress_FrontMove;
    }

    //front motor
    softPwmWrite(MOTOR_ID2_PWM,PWM_FRONT);
    digitalWrite(MOTOR_ID2_DIR,HIGH);
}
void MainWindow::Stop(){
    timer->stop();
    if(StartPress_FrontMove==1){
        //update flags , 1 means current move so make it 0, other flag just -2
        StartPress_FrontMove=0;
        if(StartPress_RearMove>0){
            FinalPress_RearMove=1;
            StartPress_RearMove-=2;
        }
        StopFront();
    }
    else if(StartPress_RearMove==1){
        //update flags , 1 means current move so make it 0, other flag just -2
        StartPress_RearMove=0;
        if(StartPress_FrontMove>0){
            FinalPress_FrontMove=1;
            StartPress_FrontMove-=2;
        }
        StopRear();
    }
    qDebug() << "STOOOOOOOOOOOOOOOOOOOP";
    qDebug() << "RearMove="<<StartPress_RearMove;
    qDebug() << "FrontMove="<<StartPress_FrontMove;
}
void MainWindow::StopFront(){
    softPwmWrite(MOTOR_ID2_PWM,0);
    digitalWrite(MOTOR_ID2_DIR,LOW);

    ui->RIGHT_B->setChecked(false);
    ui->LEFT_B->setChecked(false);
}
void MainWindow::StopRear(){
    softPwmWrite(MOTOR_ID0_PWM,0);
    digitalWrite(MOTOR_ID0_DIR,LOW);

    softPwmWrite(MOTOR_ID1_PWM,0);
    digitalWrite(MOTOR_ID1_DIR,LOW);

    ui->UP_B->setChecked(false);
    ui->DOWN_B->setChecked(false);
}
void MainWindow::CalculateSpeed(int x){
    speed=SPEED_FACTOR*x;
}
//self driving mode
void MainWindow::CheckPath(){
    int counter;
    int RB_CheckedId=ui->Paths_RBs->checkedId();
    speed=SelfDriving_speed;
    switch(RB_CheckedId){
    case HOME_PATH_ID:
        for(counter=0;counter<HOME_PATH_SIZE;counter++){
            (this->*Move_Functions[path_array_ptr[HOME_PATH_ID][counter][0]])();
            delay(1000*path_array_ptr[HOME_PATH_ID][counter][1]*CARSPEED);
        }
        break;
    case WORK_PATH_ID:
        for(counter=0;counter<WORK_PATH_SIZE;counter++){
            (this->*Move_Functions[path_array_ptr[WORK_PATH_ID][counter][0]])();
            delay(1000*path_array_ptr[WORK_PATH_ID][counter][1]*CARSPEED);
        }
        break;
    default:
        break;
    }
    speed=ui->SpeedSlider->value();
    speed*=SPEED_FACTOR;
}
