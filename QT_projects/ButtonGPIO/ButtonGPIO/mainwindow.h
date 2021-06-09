#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtimer.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int counter=0;
public  slots :
    void Increment();
    void Stop();
    void timer_Increment();
};

#endif // MAINWINDOW_H
