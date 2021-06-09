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
};

#endif // MAINWINDOW_H
