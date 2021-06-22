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

    connect(ui->Go_B,SIGNAL(pressed()),this,SLOT(GoPath()));

    //set ids for paths
    ui->Paths_RBs->setId(ui->Home_RB,HOME_PATH_ID);
    ui->Paths_RBs->setId(ui->Work_RB,WORK_PATH_ID);
    ui->Paths_RBs->setId(ui->Market_RB,MARKET_PATH_ID);
    //initialize array of movement functions
    Move_Functions[0]= &MainWindow::Move_Forward;
    Move_Functions[1]= &MainWindow::Move_Backward;
    Move_Functions[2]= &MainWindow::Move_Right;
    Move_Functions[3]= &MainWindow::Move_Left;
    Move_Functions[4]= &MainWindow::StopFront;
    Move_Functions[5]= &MainWindow::StopRear;


    Pen.setWidth(5);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    //draw borders
    Pen.setColor(QColor(0,0,0));
    Pen.setStyle(Qt::SolidLine);
    FixedMap.moveTo(0,0);
    FixedMap.lineTo(0,260);
    FixedMap.lineTo(390,260);
    FixedMap.lineTo(390,0);
    FixedMap.lineTo(0,0);
    Path.closeSubpath();
    scene->addPath(FixedMap,Pen,Brush);
    FixedMap=QPainterPath();
    //change color pin
    Pen.setColor(QColor(0,0,255));
    Pen.setStyle(Qt::DashDotLine);

    for(int mapcounter=0;mapcounter<ROADS_NO;mapcounter++){
        FixedMap.moveTo(((MapRoads[mapcounter].x_start+MAPOFFSET_X)*MAPFACTOR_X),((MAPOFFSET_Y-MapRoads[mapcounter].y_start)*MAPFACTOR_Y));
        FixedMap.lineTo(((MapRoads[mapcounter].x_end+MAPOFFSET_X)*MAPFACTOR_X),((MAPOFFSET_Y-MapRoads[mapcounter].y_end)*MAPFACTOR_Y));
    }

    Path.closeSubpath();
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

    Path.closeSubpath();
    scene->addPath(FixedMap,Pen,Brush);


    /**********************************PATHS*************************************/
    QFile file("/home/pi/Desktop/Paths.txt");
    file.open(QIODevice::ReadWrite);
    if (!file.isOpen()){
        return;
    }
    QTextStream stream(&file);
    // read number of paths
    num_paths=(stream.readLine()).toInt();
    for (int path_count = 0; path_count < num_paths; path_count++){
        // read number of commands of the path
        num_path_command=(stream.readLine()).toInt();
        path_array_ptr[path_count] = new int*[num_path_command];
        for (int command_counter = 0; command_counter < num_path_command; command_counter++){
            path_array_ptr[path_count][command_counter] = new int[2];
            QString line = stream.readLine();
            for (int counter = 0; counter < 2; counter++){
                //read line of command
                path_array_ptr[path_count][command_counter][counter] = (line.split(" ")[counter]).toInt();
            }
        }
    }
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
//self driving mode
void MainWindow::CheckPath(){
    int counter;
    int RB_CheckedId=ui->Paths_RBs->checkedId();
    speed=SelfDriving_speed;
    switch(RB_CheckedId){
    case HOME_PATH_ID:
        for(counter=0;counter<HOME_PATH_SIZE;counter++){
            (this->*Move_Functions[path_array_ptr[HOME_PATH_ID][counter][0]])();
            delay(1000*path_array_ptr[HOME_PATH_ID][counter][1]*CARSPEED);
        }
        break;
    case WORK_PATH_ID:
        for(counter=0;counter<WORK_PATH_SIZE;counter++){
            (this->*Move_Functions[path_array_ptr[WORK_PATH_ID][counter][0]])();
            delay(1000*path_array_ptr[WORK_PATH_ID][counter][1]*CARSPEED);
        }
        break;
    default:
        break;
    }
    speed=ui->SpeedSlider->value();
    speed*=SPEED_FACTOR;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    /*
    if(DrawFlag==1){
        Painter.begin(this); //Specify the current window as a drawing device;
        Painter.setPen(Pen);


        Path.moveTo(x_start,y_start);
        Path.lineTo(x_end,y_end);

        Path.closeSubpath();
        scene->addPath(Path,Pen,Brush);

        Painter.end();
        qDebug()<<"Before";
        qDebug()<<"x_start="<<x_start;
        qDebug()<<"y_start="<<y_start;
        qDebug()<<"x_end="<<x_end;
        qDebug()<<"y_end="<<y_end;
        x_start=x_end;
        y_start=y_end;
    }
    DrawFlag=0;
*/
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

        //enable go button
        ui->Go_B->setEnabled(TRUE);

    }
}
void MainWindow::MapStart_Select(){
    int RB_CheckedId=ui->Paths_RBs->checkedId();
    if(RB_CheckedId!=-1){
        //deactivate dest selection
        ui->MapStart_B->setEnabled(FALSE);
        //activate start selection
        ui->MapDest_B->setEnabled(TRUE);
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
void MainWindow::GoPath(){
    //update destination
    MapStart_Select();

    if(DestLocation.x!=-1){
        //update speed
        speed=SelfDriving_speed;

        //deactivate manual mode
        ui->Manual_T->setEnabled(FALSE);
        PathPlan(StartLocation.x,StartLocation.y,DestLocation.x,DestLocation.y);

        /************************after finishing the path***********************/
        //activate manual mode
        ui->Manual_T->setEnabled(TRUE);

        //disable go button
        ui->Go_B->setEnabled(FALSE);

        //clear labels
        ui->DestinationMap_L->setText("Choose from map");
        ui->StartingPointMap_L->setText("Choose from map");

        //update for start position
       // StartLocation=DestLocation;
        //update for new destination
        DestLocation={-1,-1};

        //return speed to old value
        speed=ui->SpeedSlider->value();
        speed*=SPEED_FACTOR;
    }
}

