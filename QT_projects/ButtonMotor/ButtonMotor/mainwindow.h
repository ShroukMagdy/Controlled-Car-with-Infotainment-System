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
    void Move_Forward();
    void Move_Backward();
    void Move_Stop();
    void Timer_CbkFn();
};

#endif // MAINWINDOW_H
