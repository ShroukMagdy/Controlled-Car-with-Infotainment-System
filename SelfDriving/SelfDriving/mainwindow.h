#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //fixed speed for self driving
    int speed=20;
    //array of pointers to functions for movement
    void (MainWindow::*Move_Functions[6])();
    typedef struct{
        int* Direction;
        int* Distance;
    }PathInfo_t;
     int **array = new int*[4]; // allocate an array of 10 int pointers — these are our rows
int **array2 = new int*[5];
     int **array_ptr[10];
    //paths
    unsigned int Home_Path[HOME_PATH_SIZE][2]={{MOVEFORWARD_INDEX,2},
                                               {STOPREAR_INDEX,0},
                                               {MOVEBACKWARD_INDEX,2},
                                               {STOPREAR_INDEX,0}
                                              };

    unsigned int Work_Path[WORK_PATH_SIZE][2]={{MOVEBACKWARD_INDEX,2},
                                               {STOPREAR_INDEX,0},
                                               {MOVEFORWARD_INDEX,2},
                                               {STOPREAR_INDEX,0}
                                              };

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void Move_Forward();
    void Move_Backward();
    void Move_Right();
    void Move_Left();
    void StopFront();
    void StopRear();
private slots:
    void CheckPath();

};

#endif // MAINWINDOW_H
