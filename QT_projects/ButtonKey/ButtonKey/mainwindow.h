#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent * e);
    void keyReleaseEvent(QKeyEvent * e);
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    bool flag;
public  slots :
    void Move_Forward();
    void Move_Backward();
    void Move_Right();
    void Move_Left();
    void Move_Stop();
    void Timer_CbkFn();
};

#endif // MAINWINDOW_H
