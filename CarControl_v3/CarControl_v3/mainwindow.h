#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

#include <QTimer>
#include <QKeyEvent>
#include <wiringPi.h>
#include <softPwm.h>

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include <QDebug>
/*************************************PINS*********************************/
#define MOTOR_ID0_PWM                   1           //PWM
#define MOTOR_ID0_DIR                   4           //DIR
#define MOTOR_ID1_PWM                   26          //PWM
#define MOTOR_ID1_DIR                   5           //DIR

#define MOTOR_ID2_PWM                   2           //PWM
#define MOTOR_ID2_DIR                   3           //DIR

//camera
#define CAMERANOFICATIONPIN             0           //output for the other pi

#define SPEED_FACTOR                    20
#define TIMER_TIMEOUT                   150
#define PWM_FRONT                       60          //fixed - done for optimization of rotation
/*******************************SELFDRIVINGMODE****************************/
//indicies for functions call
#define MOVEFORWARD_INDEX           0
#define MOVEBACKWARD_INDEX          1
#define MOVERIGHT_INDEX             2
#define MOVELEFT_INDEX              3
#define STOPFRONT_INDEX             4
#define STOPREAR_INDEX              5

#define PATHS_NO                    2
#define HOME_PATH_SIZE              4
#define WORK_PATH_SIZE              4

#define HOME_PATH_ID                0
#define MARKET_PATH_ID              1
#define WORK_PATH_ID                2

#define CARSPEED                    2       //sec/m

#define ROADS_NO                    3
#define INTERSECTIONS_NO            2
#define LOCATIONS_NO                3

#define ORIENTATION_VERTICAL        0
#define ORIENTATION_HORIZENTAL      1

#define MOVING_FORWARD              0
#define MOVING_REVERSE              1

#define MAPOFFSET_X                 0
#define MAPOFFSET_Y                 10

#define MAPLIMIT_X                  390
#define MAPLIMIT_Y                  260

#define MAPFACTOR_X                 39
#define MAPFACTOR_Y                 26

typedef struct
{
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    int orientation;
} Road;

typedef struct
{
    int x_intersection;
    int y_intersection;
    int road1_index;
    int road2_index;
} Intersection;

typedef struct
{
    int Forward_Horizental;
    int Reverse_Horizental;
    int Forward_Vertical;
    int Reverse_Vertical;
} AvailableDirections;
typedef struct{
    int x;
    int y;
}LocationInfo;
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
    int **path_array_ptr[10];

    QPainterPath Path;
    QPainterPath FixedMap;
    QPainter Painter;
    QPen Pen;

    QBrush Brush;
    QGraphicsScene *scene;
    int DrawFlag=0;
    Road MapRoads[ROADS_NO] = {
        {0,0,0,5,ORIENTATION_VERTICAL},
        {0,5,10,5,ORIENTATION_HORIZENTAL},
        {10,5,10,10,ORIENTATION_VERTICAL}
    };

    Intersection MapIntersections[INTERSECTIONS_NO] = {
        {0,5,0,1},
        {10,5,1,2}
    };

    LocationInfo MapLocations[LOCATIONS_NO]={
        {0,0},
        {5,5},
        {10,10}
    };
    LocationInfo StartLocation;
    LocationInfo DestLocation={-1,-1};
    /*************************************************************************/

public:
    void PathPlan (int current_x, int current_y, int dest_x, int dest_y);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);

    void paintEvent(QPaintEvent *event);

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

    void MapDest_Select();
    void MapStart_Select();
    void GoPath();
};



#endif // MAINWINDOW_H
