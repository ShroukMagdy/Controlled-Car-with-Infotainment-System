#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *e){
    QString text= ui->label->text();
    if(e->key()==Qt::Key_Up){
        text="UP";
digitalWrite(4,HIGH);
    }
  else if(e->key()==Qt::Key_Down){
        text="DOWN";
    }
    else  if(e->key()==Qt::Key_Right){
            text="RIGHT";
        }
    else  if(e->key()==Qt::Key_Left){
        text="LEFT";
        }

ui->label->setText((text));
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{

    if((e->key()==Qt::Key_Up)||
            (e->key()==Qt::Key_Down)||
            (e->key()==Qt::Key_Right)||
            (e->key()==Qt::Key_Left)){

QString text= ui->label->text();
text="NTH";
digitalWrite(4,LOW);
ui->label->setText((text));
   }

}


