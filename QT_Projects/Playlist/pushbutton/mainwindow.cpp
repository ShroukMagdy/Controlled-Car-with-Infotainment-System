#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(click_increment()));

    connect(ui->pushButton,SIGNAL(released()),this,SLOT(click_stop()));
connect(timer,SIGNAL(timeout()),this,SLOT(timer_increment()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click_increment(){
    timer->start(100);
    QString text;
text="PRESSED";

ui->label_2->setText((text));
}
void MainWindow::click_stop(){
    timer->stop();
    digitalWrite(4,LOW);
    QString text;
text="NTH";

ui->label_2->setText((text));
}
void MainWindow::timer_increment(){

    static int counter=0;
    ui->label->setText(QString::number(counter));
    digitalWrite(4,HIGH);
    counter++;


}
