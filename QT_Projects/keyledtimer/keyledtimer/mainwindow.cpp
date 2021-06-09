#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(click_stop()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *e){

    if(e->key()==Qt::Key_A){
        digitalWrite(4,HIGH);
        ui->UP->setStyleSheet("color: red");
         etimer.start();
         timer->start(150);
    }
  else if(e->key()==Qt::Key_Down){

    }
    else  if(e->key()==Qt::Key_Right){

        }
    else  if(e->key()==Qt::Key_Left){

    }

    qDebug() << e->key();

}
void MainWindow::keyReleaseEvent(QKeyEvent *e){

    if((e->key()==Qt::Key_A)||
    (e->key()==Qt::Key_Down)||
    (e->key()==Qt::Key_Right)||
            (e->key()==Qt::Key_Left)){
        if(finalreleaseflag==1){
            qDebug() <<"released";
            click_stop();
        }

    }
    else{
       timer->stop();
       finalreleaseflag=1;
    }
}

void MainWindow::click_stop(){
    timer->stop();
    digitalWrite(4,LOW);
    ui->UP->setStyleSheet("color: black");
    qDebug() << etimer.elapsed();
    finalreleaseflag=0;
}


