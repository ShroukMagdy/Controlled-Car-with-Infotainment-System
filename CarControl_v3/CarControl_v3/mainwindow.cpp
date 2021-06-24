#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initialize wiring pi and pins
    wiringPiSetup();
    //rear motors
    softPwmCreate(MOTOR_ID0_PWM,0,100);
    pinMode(MOTOR_ID0_DIR, OUTPUT);
    softPwmCreate(MOTOR_ID1_PWM,0,100);
    pinMode(MOTOR_ID1_DIR, OUTPUT);
    //front motor
    softPwmCreate(MOTOR_ID2_PWM,0,100);
    pinMode(MOTOR_ID2_DIR, OUTPUT);

    //camera notification pin
    pinMode(CAMERANOFICATIONPIN, OUTPUT);
    /***************************************************************************/
    //initialize pins
    //rear motors
    softPwmWrite(MOTOR_ID0_PWM,0);
    digitalWrite(MOTOR_ID0_DIR,LOW);
    softPwmWrite(MOTOR_ID1_PWM,0);
    digitalWrite(MOTOR_ID1_DIR,LOW);
    //front motor
    softPwmWrite(MOTOR_ID2_PWM,0);
    digitalWrite(MOTOR_ID2_DIR,LOW);

    //camera notification pin
    digitalWrite(CAMERANOFICATIONPIN,LOW);
    /***************************************************************************/
    //timer instance
    timer = new QTimer;

    //timer function
    connect(timer,SIGNAL(timeout()),this,SLOT(Stop()));

    //mouse press
    connect(ui->UP_B,SIGNAL(pressed()),this,SLOT(Move_Forward()));
    connect(ui->UP_B,SIGNAL(released()),this,SLOT(StopRear()));

    connect(ui->DOWN_B,SIGNAL(pressed()),this,SLOT(Move_Backward()));
    connect(ui->DOWN_B,SIGNAL(released()),this,SLOT(StopRear()));

    connect(ui->RIGHT_B,SIGNAL(pressed()),this,SLOT(Move_Right()));
    connect(ui->RIGHT_B,SIGNAL(released()),this,SLOT(StopFront()));

    connect(ui->LEFT_B,SIGNAL(pressed()),this,SLOT(Move_Left()));
    connect(ui->LEFT_B,SIGNAL(released()),this,SLOT(StopFront()));
    //slider speed
    connect(ui->SpeedSlider,SIGNAL(valueChanged(int)),this,SLOT(CalculateSpeed(int)));
    /***************************************************************************/
    //self driving mode
    connect(ui->MapDest_B,SIGNAL(pressed()),this,SLOT(MapDest_Select()));
    connect(ui->MapStart_B,SIGNAL(pressed()),this,SLOT(MapStart_Select()));
    connect(ui->DestConfirm_B,SIGNAL(pressed()),this,SLOT(MapConfirmLocations()));

    connect(ui->Go_B,SIGNAL(pressed()),this,SLOT(GoPath()));

    //set ids for paths
    ui->Paths_RBs->setId(ui->Home_RB,HOME_PATH_ID);
    ui->Paths_RBs->setId(ui->Work_RB,WORK_PATH_ID);
    ui->Paths_RBs->setId(ui->Market_RB,MARKET_PATH_ID);


    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    MapFixedPath_Draw();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent *e){
    //forward
    if(e->key()==Qt::Key_W){
        timer->start(TIMER_TIMEOUT);
        Move_Forward();
        ui->UP_B->setChecked(true);
        ui->UP_B->setFocus();
    }
    //backward
    else if(e->key()==Qt::Key_S){
        timer->start(TIMER_TIMEOUT);
        Move_Backward();
        ui->DOWN_B->setChecked(true);
        ui->DOWN_B->setFocus();
    }
    //left
    else  if(e->key()==Qt::Key_A){
        timer->start(TIMER_TIMEOUT);
        Move_Left();
        ui->LEFT_B->setChecked(true);
        ui->LEFT_B->setFocus();
    }
    //right
    else  if(e->key()==Qt::Key_D){
        timer->start(TIMER_TIMEOUT);
        Move_Right();
        ui->RIGHT_B->setChecked(true);
        ui->RIGHT_B->setFocus();
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *e){
    if((e->key()==Qt::Key_W)||(e->key()==Qt::Key_S)){
        if(another_press==1){
            Stop();
            another_press=0;
        }
        if(FinalPress_RearMove==1){
            FinalPress_RearMove=0;
            StartPress_RearMove=0;
            StopRear();
        }
    }
    else if((e->key()==Qt::Key_A)||(e->key()==Qt::Key_D)){
        if(another_press==1){
            Stop();
            another_press=0;
        }
        if(FinalPress_FrontMove==1){
            FinalPress_FrontMove=0;
            StartPress_FrontMove=0;
            StopFront();
        }

    }
    else{
        timer->stop();
        another_press=1;
    }
}

void MainWindow::CalculateSpeed(int x){
    speed=SPEED_FACTOR*x;
}

void MainWindow::MapDest_Select(){
    int RB_CheckedId=ui->Paths_RBs->checkedId();
    if(RB_CheckedId!=-1){
        //activate dest selection
        ui->MapStart_B->setEnabled(TRUE);
        //deactivate start selection
        ui->MapDest_B->setEnabled(FALSE);
        //update location coordinates
        StartLocation=MapLocations[RB_CheckedId];

        //change label text
        ui->StartingPointMap_L->setText(ui->Paths_RBs->checkedButton()->text());

        //unselect selected radiobutton
        ui->Paths_RBs->setExclusive(FALSE);
        ui->Paths_RBs->checkedButton()->setChecked(FALSE);
        ui->Paths_RBs->setExclusive(TRUE);

        //enable confirm button
        ui->DestConfirm_B->setEnabled(TRUE);

    }
    else if(StartLocation.x!=-1){
        //activate dest selection
        ui->MapStart_B->setEnabled(TRUE);
        //deactivate start selection
        ui->MapDest_B->setEnabled(FALSE);

        //enable confirm button
        ui->DestConfirm_B->setEnabled(TRUE);
    }
}
void MainWindow::MapStart_Select(){
    int RB_CheckedId=ui->Paths_RBs->checkedId();
    //deactivate dest selection
    ui->MapStart_B->setEnabled(FALSE);
    //activate start selection
    ui->MapDest_B->setEnabled(TRUE);
    //disable go and confirm buttons
    ui->Go_B->setEnabled(FALSE);
    ui->DestConfirm_B->setEnabled(FALSE);

    if(RB_CheckedId!=-1){

        //update location coordinates
        DestLocation=MapLocations[RB_CheckedId];

        //change label text
        ui->DestinationMap_L->setText(ui->Paths_RBs->checkedButton()->text());

        //unselect selected radiobutton
        ui->Paths_RBs->setExclusive(FALSE);
        ui->Paths_RBs->checkedButton()->setChecked(FALSE);
        ui->Paths_RBs->setExclusive(TRUE);

    }

}
void MainWindow::MapConfirmLocations(){
    //update desination
    int RB_CheckedId=ui->Paths_RBs->checkedId();
    if(RB_CheckedId!=-1){
        //update location coordinates
        DestLocation=MapLocations[RB_CheckedId];

        //change label text
        ui->DestinationMap_L->setText(ui->Paths_RBs->checkedButton()->text());

        //unselect selected radiobutton
        ui->Paths_RBs->setExclusive(FALSE);
        ui->Paths_RBs->checkedButton()->setChecked(FALSE);
        ui->Paths_RBs->setExclusive(TRUE);

        //enable go and confirm buttons
        ui->Go_B->setEnabled(TRUE);

        //show path
        MapFixedPath_Draw();
        MapMovePath=0;
        PathPlan(StartLocation.x,StartLocation.y,DestLocation.x,DestLocation.y);
    }
    else if(DestLocation.x!=-1){
        //enable go and confirm buttons
        ui->Go_B->setEnabled(TRUE);
        //show path
        MapFixedPath_Draw();
        MapMovePath=0;
        PathPlan(StartLocation.x,StartLocation.y,DestLocation.x,DestLocation.y);
    }
}
void MainWindow::GoPath(){
    //disable dest confirm
    ui->DestConfirm_B->setEnabled(FALSE);
    if(DestLocation.x!=-1){
        //update speed
        speed=SelfDriving_speed;

        //deactivate manual mode
        ui->Manual_T->setEnabled(FALSE);

        //move the car
        MapMovePath=1;
        PathPlan(StartLocation.x,StartLocation.y,DestLocation.x,DestLocation.y);

        /************************after finishing the path***********************/
        //activate manual mode
        ui->Manual_T->setEnabled(TRUE);

        //disable go button
        ui->Go_B->setEnabled(FALSE);

        //activate dest button
        ui->MapDest_B->setEnabled(TRUE);
        //deactivate start button
        ui->MapStart_B->setEnabled(FALSE);

        //update start label
        ui->StartingPointMap_L->setText(ui->DestinationMap_L->text());
        //clear dest label
        ui->DestinationMap_L->setText("Choose from map");

        //update for start position
        StartLocation=DestLocation;
        //update for new destination
        DestLocation={-1,-1};

        //return speed to old value
        speed=ui->SpeedSlider->value();
        speed*=SPEED_FACTOR;

        //draw old scene
        delay(1000);

        MapFixedPath_Draw();
    }
}
void MainWindow::MapFixedPath_Draw(){
    scene->clear();

    //draw borders
    Pen.setWidth(5);
    Pen.setColor(QColor(0,0,0));
    Pen.setStyle(Qt::SolidLine);
    FixedMap.moveTo(0,0);
    FixedMap.lineTo(0,260);
    FixedMap.lineTo(390,260);
    FixedMap.lineTo(390,0);
    FixedMap.lineTo(0,0);
    scene->addPath(FixedMap,Pen,Brush);
    FixedMap=QPainterPath();
    //change color pin
    Pen.setColor(QColor(0,0,255));
    Pen.setStyle(Qt::DashDotLine);

    for(int mapcounter=0;mapcounter<ROADS_NO;mapcounter++){
        FixedMap.moveTo(((MapRoads[mapcounter].x_start+MAPOFFSET_X)*MAPFACTOR_X),((MAPOFFSET_Y-MapRoads[mapcounter].y_start)*MAPFACTOR_Y));
        FixedMap.lineTo(((MapRoads[mapcounter].x_end+MAPOFFSET_X)*MAPFACTOR_X),((MAPOFFSET_Y-MapRoads[mapcounter].y_end)*MAPFACTOR_Y));
    }

    scene->addPath(FixedMap,Pen,Brush);
    FixedMap=QPainterPath();
    Pen.setColor(QColor(255,0,0));
    Pen.setWidth(8);
    //point home
    FixedMap.moveTo(0,260);
    FixedMap.lineTo(2,258);
    FixedMap.moveTo(2,260);
    FixedMap.lineTo(0,258);
    //point maret
    FixedMap.moveTo(195,132);
    FixedMap.lineTo(197,130);
    FixedMap.moveTo(197,132);
    FixedMap.lineTo(195,130);
    //point work
    FixedMap.moveTo(390,0);
    FixedMap.lineTo(388,2);
    FixedMap.moveTo(388,0);
    FixedMap.lineTo(390,2);

    scene->addPath(FixedMap,Pen,Brush);
}

