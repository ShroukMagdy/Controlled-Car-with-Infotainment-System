#include "mainwindow.h"

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

    //camera notificatiion pin
    digitalWrite(CAMERANOFICATIONPIN,HIGH);
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

    //camera notificatiion pin
    digitalWrite(CAMERANOFICATIONPIN,LOW);
}
