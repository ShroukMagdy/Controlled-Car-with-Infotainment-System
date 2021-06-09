#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

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
void MainWindow::keyPressEvent(QKeyEvent *e) {
    /*QString textto = ui->label->text();
    textto += char(e->key());
    ui->label->setText(textto);
    */
    if (e->key()==Qt::Key_Up){
        ui->label->setText("up");

    }
    else if (e->key()==Qt::Key_Down){
        ui->label->setText("down");
    }
    else if (e->key()==Qt::Key_Right){
        ui->label->setText("right");
    }
    else if (e->key()==Qt::Key_Left){
        ui->label->setText("left");
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *e) {
    if(e->isAutoRepeat()){
            e->ignore();
     }
    else if (e->key()==Qt::Key_Up){
        ui->label->setText("after up");
    }
    else if (e->key()==Qt::Key_Down){
        ui->label->setText("after down");
    }
    else if (e->key()==Qt::Key_Right){
        ui->label->setText("after right");
    }
    else if (e->key()==Qt::Key_Left){
        ui->label->setText("after left");
    }
}
