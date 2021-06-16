#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *timer;
    int another_press=0;
    int StartPress_FrontMove=0;
    int StartPress_RearMove=0;
    int FinalPress_FrontMove=0;
    int FinalPress_RearMove=0;
    //speed=factor*slider_value
    int speed=0;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;
private slots:
    void Move_Forward();
    void Move_Backward();
    void Move_Right();
    void Move_Left();

    void Stop();
    void StopFront();
    void StopRear();
    void CalculateSpeed(int x);
};

#endif // MAINWINDOW_H
