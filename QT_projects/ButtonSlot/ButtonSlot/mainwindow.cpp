#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"

MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //const QString str="hii";
    Pte=ui->plainTextEdit;
    te=ui->textEdit;
   // connect(ui->pushButton,SIGNAL(clicked()),ui->plainTextEdit ,SLOT(insertPlainText(&str)));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT ( hiii () ) ) ;
}
MainWindow::~MainWindow()
{
    delete ui;
}
