#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/*******************************SELFDRIVINGMODE****************************/
//indicies for functions call
#define MOVEFORWARD_INDEX       0
#define MOVEBACKWARD_INDEX      1
#define MOVERIGHT_INDEX         2
#define MOVELEFT_INDEX          3
#define STOPFRONT_INDEX         4
#define STOPREAR_INDEX          5

#define PATHS_NO                2
#define HOME_PATH_SIZE          4
#define WORK_PATH_SIZE          4

#define HOME_PATH_ID            0
#define WORK_PATH_ID            1

#define CARSPEED                2       //sec/m
/*************************************************************************/
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
    /*******************************SELFDRIVINGMODE****************************/

    int SelfDriving_speed=20;
    //array of pointers to functions for movement
    void (MainWindow::*Move_Functions[6])();
    /*
    //paths
    unsigned int Home_Path[HOME_PATH_SIZE][2]={{MOVEFORWARD_INDEX,1},
                                               {STOPREAR_INDEX,0},
                                               {MOVEBACKWARD_INDEX,1},
                                               {STOPREAR_INDEX,0}
                                              };

    unsigned int Work_Path[WORK_PATH_SIZE][2]={{MOVEBACKWARD_INDEX,1},
                                               {STOPREAR_INDEX,0},
                                               {MOVEFORWARD_INDEX,1},
                                               {STOPREAR_INDEX,0}
                                              };
                                              */
    int **path_array_ptr[10];
    /*************************************************************************/

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

private:
    Ui::MainWindow *ui;
    int num_paths;
    int num_path_command;
private slots:
    void Move_Forward();
    void Move_Backward();
    void Move_Right();
    void Move_Left();

    void Stop();
    void StopFront();
    void StopRear();
    void CalculateSpeed(int x);

    void CheckPath();
};



#endif // MAINWINDOW_H
