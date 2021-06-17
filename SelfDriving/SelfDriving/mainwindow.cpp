#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QTimer>
#include <QKeyEvent>
#include <wiringPi.h>
#include <softPwm.h>

/*************************************PINS*********************************/
#define MOTOR_ID0_PWM                   1           //PWM
#define MOTOR_ID0_DIR                   4           //DIR
#define MOTOR_ID1_PWM                   26          //PWM
#define MOTOR_ID1_DIR                   5           //DIR

#define MOTOR_ID2_PWM                   2           //PWM
#define MOTOR_ID2_DIR                   3           //DIR

#define PWM_FRONT                       60          //fixed - done for optimization of rotation
/**************************************************************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int count = 0; count < 4; ++count){
        array[count] = new int[2];
    }
    array[0][0]=MOVEFORWARD_INDEX;
array=(int**)Home_Path;
array_ptr[0]=array;
array_ptr[1]=array2;
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


    connect(ui->Go_B,SIGNAL(pressed()),this,SLOT(CheckPath()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Move_Forward(){
    //rear motors
    softPwmWrite(MOTOR_ID0_PWM,speed);
    digitalWrite(MOTOR_ID0_DIR,LOW);

    softPwmWrite(MOTOR_ID1_PWM,speed);
    digitalWrite(MOTOR_ID1_DIR,LOW);
}
void MainWindow::Move_Backward(){
    //rear motors
    softPwmWrite(MOTOR_ID0_PWM,speed);
    digitalWrite(MOTOR_ID0_DIR,HIGH);

    softPwmWrite(MOTOR_ID1_PWM,speed);
    digitalWrite(MOTOR_ID1_DIR,HIGH);
}
void MainWindow:: Move_Right(){
    //front motor
    softPwmWrite(MOTOR_ID2_PWM,PWM_FRONT);
    digitalWrite(MOTOR_ID2_DIR,LOW);
}
void MainWindow:: Move_Left(){
    //front motor
    softPwmWrite(MOTOR_ID2_PWM,PWM_FRONT);
    digitalWrite(MOTOR_ID2_DIR,HIGH);
}

void MainWindow::StopFront(){
    softPwmWrite(MOTOR_ID2_PWM,0);
    digitalWrite(MOTOR_ID2_DIR,LOW);
}
void MainWindow::StopRear(){
    softPwmWrite(MOTOR_ID0_PWM,0);
    digitalWrite(MOTOR_ID0_DIR,LOW);

    softPwmWrite(MOTOR_ID1_PWM,0);
    digitalWrite(MOTOR_ID1_DIR,LOW);
}
void MainWindow::CheckPath(){
    int counter;
    int RB_CheckedId=ui->Paths_RBs->checkedId();
    switch(RB_CheckedId){
    case HOME_PATH_ID:
        for(counter=0;counter<HOME_PATH_SIZE;counter++){
            (this->*Move_Functions[Home_Path[counter][0]])();
            delay(1000*Home_Path[counter][1]);
        }
        break;
    case WORK_PATH_ID:
        for(counter=0;counter<WORK_PATH_SIZE;counter++){
            (this->*Move_Functions[Work_Path[counter][0]])();
            delay(1000*Work_Path[counter][1]);
        }
        break;
    default:
        break;
    }
}
