#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->pushButton_2->setText("Close");
connect(ui->verticalSlider,SIGNAL(valueChanged(int)),ui->progressBar_2,SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}
