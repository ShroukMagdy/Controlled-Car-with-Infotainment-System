#include "mainwindow.h"
#include "ui_mainwindow.h"







MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*put title for the window*/
    setWindowTitle("Infotainment System ");

    /**********************************************************************     NIHAL *************************************************************/

    /* Setting HomePage as the default page */
    ui->Pages_stack->setCurrentIndex(HOME_PAGE_INDEX);

    /* Connecting Esc button in each widget to go to homePage */
    connect(ui->SettingsW_EscBtn,SIGNAL(clicked()),SLOT(Esc()));
    connect(ui->MusicW_EscBtn,SIGNAL(clicked()),SLOT(Esc()));
    connect(ui->VideoW_EscBtn,SIGNAL(clicked()),SLOT(Esc()));
    connect(ui->CameraW_EscBtn,SIGNAL(clicked()),SLOT(Esc()));


    /* Connecting Home_Widget buttons to their clicked_functions */
    connect(ui->HomeW_SettingsBtn,SIGNAL(clicked()),SLOT(HomeW_SettingsBtn_clicked()));
    connect(ui->HomeW_MusicBtn,SIGNAL(clicked()),SLOT(HomeW_MusicBtn_clicked()));
    connect(ui->HomeW_VideoBtn,SIGNAL(clicked()),SLOT(HomeW_VideoBtn_clicked()));


    ui->Pages_stack->setFixedSize(LCD_WIDTH,LCD_HEIGHT);

    /*Icons*/
    MainWindow::setStyleSheet("border-image:   url(:/images/Media/Icons/stars_2.jpg)");
    ui->HomeW_MusicBtn->setStyleSheet("QPushButton { border-image:   url(:/images/Media/Icons/music_icon.png)}");
    ui->HomeW_SettingsBtn->setStyleSheet("QPushButton { border-image:  url(:/images/Media/Icons/settings_icon.png)}");
    ui->HomeW_VideoBtn->setStyleSheet("QPushButton { border-image:  url(:/images/Media/Icons/video_icon.png)}");
    ui->HomeW_CameraBtn->setStyleSheet("QPushButton { border-image:  url(:/images/Media/Icons/camera2.png)}");

    ui->SettingsW_EscBtn->setStyleSheet("QPushButton { border-image:  url(:/images/Media/Icons/home_icon.png)}");
    ui->MusicW_EscBtn->setStyleSheet("QPushButton { border-image:  url(:/images/Media/Icons/home_icon.png)}");
    ui->CameraW_EscBtn->setStyleSheet("QPushButton { border-image:  url(:/images/Media/Icons/home_icon.png)}");
    ui->VideoW_EscBtn->setStyleSheet("QPushButton { border-image:  url(:/images/Media/Icons/home_icon.png)}");

    ui->StartButton->setStyleSheet("QPushButton { border-image:  url(:/images/Media/Icons/play_icon.png)}");
    ui->PauseButton->setStyleSheet("QPushButton { border-image:  url(:/images/Media/Icons/pause_icon.png)}");
    ui->PrevButton->setStyleSheet("QPushButton { border-image:  url(:/images/Media/Icons/prevMusic.png)}");
    ui->NextButton->setStyleSheet("QPushButton { border-image:  url(:/images/Media/Icons/nextMusic.png)}");
    ui->VolumeDown->setStyleSheet("QLabel { border-image:  url(:/images/Media/Icons/volumeDown_icon.png)}");
    ui->VolumeUp->setStyleSheet("QLabel{ border-image:  url(:/images/Media/Icons/volumeUp_icon.png)}");
    ui->MuteRadioButton->setStyleSheet("QRadioButton{ border-image:  url(:/images/Media/Icons/mute_icon.png)}");


    ui->VideoPlay->setStyleSheet("QPushButton{ border-image:  url(:/images/Media/Icons/play_icon.png)}");
    ui->VideoPause->setStyleSheet("QPushButton{ border-image:  url(:/images/Media/Icons/pause_icon.png)}");
    ui->VideoStop->setStyleSheet("QPushButton{ border-image:  url(:/images/Media/Icons/stop_icon.png)}");
    ui->NextVideo->setStyleSheet("QPushButton{ border-image:  url(:/images/Media/Icons/nextMusic.png)}");
    ui->VideoPrevious->setStyleSheet("QPushButton{ border-image:  url(:/images/Media/Icons/prevMusic.png)}");
    ui->MuteRadioButtom->setStyleSheet("QRadioButton{ border-image:  url(:/images/Media/Icons/mute_icon.png)}");


    /**************************************************************   BANNA  ****************************************************************/


    /************************************************************Music Part ********************************************************/

    /*Adding Songs to the PLaylist*/
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/EdSheeran_ShapeofYou.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/Stromae_AlorsOnDanse.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/ShawnMendes_Señorita.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/DanceMonkey.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/MaherZain_NasTeshbehlena.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/2Pac_EyesOnMe.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/Coldplay_ASkyFullOfStars.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/Coldplay_Adv.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/EdSheeran_Galway Girl.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/EdSheeran_Thinking_Out_Loud.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/Taylor_Swift_Lover.mp3"));




    /*configure the playlist to work in loops*/
    Myplaylist->setPlaybackMode(QMediaPlaylist::Loop);

    /*Set the playlist in the AudioPlayer*/
    MyPLayer->setPlaylist(Myplaylist);

    /*set the volume with low at the first*/
    MyPLayer->setVolume(0);

    /*Object created to use its methods to convert number to string*/
    QString::number(10);

    /*Start timer*/
    connect(Timer,SIGNAL(timeout()),this , SLOT(ClockUpdate()) );
    Timer->start(1000);

    /*Array of avialable songs*/
    QPushButton *SongButtons[NUMBER_OF_SONGS];


    /*Create Number of buttom equivilant to number of songs*/
    for( unsigned char itr=0 ; itr<NUMBER_OF_SONGS ; itr++){
        SongButtons[itr]=new QPushButton(Songs[itr]);
        SongButtons[itr]->show();
        SongButtons[itr]->setFlat(true);
        Lay->addWidget(SongButtons[itr]);
    }

    /*Put the buttoms layout of scroll area into the GUI*/
    ui->ScrollSong->setLayout(Lay);

    /*Connect the buttom signals with its slots to change the songs*/
    connect(SongButtons[0], SIGNAL (clicked()), this, SLOT (Handle_Button0()  )  );
    connect(SongButtons[1], SIGNAL (clicked()), this, SLOT (Handle_Button1()  )  );
    connect(SongButtons[2], SIGNAL (clicked()), this, SLOT (Handle_Button2()  )  );
    connect(SongButtons[3], SIGNAL (clicked()), this, SLOT (Handle_Button3()  )  );
    connect(SongButtons[4], SIGNAL (clicked()), this, SLOT (Handle_Button4()  )  );
    connect(SongButtons[5], SIGNAL (clicked()), this, SLOT (Handle_Button5()  )  );
    connect(SongButtons[6], SIGNAL (clicked()), this, SLOT (Handle_Button6()  )  );
    connect(SongButtons[7], SIGNAL (clicked()), this, SLOT (Handle_Button7()  )  );
    connect(SongButtons[8], SIGNAL (clicked()), this, SLOT (Handle_Button8()  )  );
    connect(SongButtons[9], SIGNAL (clicked()), this, SLOT (Handle_Button9()  )  );
    connect(SongButtons[10], SIGNAL (clicked()), this, SLOT (Handle_Button10()  )  );

    /***************************************************Video Part *******************************************************/

    /*add videos to media*/

     VideoMyplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/yt1s.com - WASTED LOVE  FRENCH VERSION  OFENBACH feat LAGIQUE  SARAH COVER .mp4"));
     VideoMyplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/RagnBone_ManHumanOfficial.mp4"));
     VideoMyplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/Avicii_WakeMeUp.mp4"));
     VideoMyplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/ZAYN_DuskTillDawn .mp4"));
     VideoMyplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/SaadLamjarred_ADDAELKALAM.mp4"));
     VideoMyplaylist->addMedia(QUrl::fromLocalFile("/home/pi/Infotainment_Camera_V1/Merging_3_Features/Media/Music/HamzaNamira_FadyShewaya.mp4"));


     /*

*/

    /*configure the playlist to work in loops*/
    VideoMyplaylist->setPlaybackMode(QMediaPlaylist::Loop);

    /*set the video*/
    VideoPlayer->setVideoOutput(VideoWidget);

    /*Set the playlist in the AudioPlayer*/
    VideoPlayer->setPlaylist(VideoMyplaylist);


    /*Put the video widget in layout*/
    ui->Layout->addWidget(VideoWidget);

    /*Set the volume the lowest at first*/
    VideoPlayer->setVolume(0);

    /*show the video widget*/
    VideoWidget->show();

    /*connect signals with slots for slider and and video duration*/
    connect(VideoPlayer,&QMediaPlayer::durationChanged,ui->VideoHorizontalSlider,&QSlider::setMaximum);
    connect(VideoPlayer,&QMediaPlayer::positionChanged,ui->VideoHorizontalSlider,&QSlider::setValue);
    connect(ui->VideoHorizontalSlider,&QSlider::sliderMoved,VideoPlayer,&QMediaPlayer::setPosition);
    /*******************************************************Camera Part*****************************************************************************/

    /*Init Camera*/
    connect(ui->HomeW_CameraBtn,SIGNAL(clicked()),SLOT(on_HomeW_CameraBtn_clicked()));
    mCamera= new QCamera(this);
    mCameraViewfinder=new QCameraViewfinder(this);
    mLayout=new QVBoxLayout;

    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollAreaCamera->setLayout(mLayout);
    /*Camera Update:: when signal trigger rpi when the car moves backward */
    connect(CameraTimer,SIGNAL(timeout()),this , SLOT(CameraUpdate()) );
    CameraTimer->start(500);
    /*Wiring Pi setup*/
    wiringPiSetup();
    pinMode(0,INPUT);


}

MainWindow::~MainWindow()
{
    delete ui;

}


/*********************************************************************    NIHAL PART **********************************************************/
void MainWindow::HomeW_MusicBtn_clicked()
{
    ui->Pages_stack->setCurrentIndex(MUSIC_PAGE_INDEX);
}

void MainWindow::HomeW_SettingsBtn_clicked()
{
    ui->Pages_stack->setCurrentIndex(SETTINGS_PAGE_INDEX);
}

void MainWindow::HomeW_VideoBtn_clicked()
{
    ui->Pages_stack->setCurrentIndex(VIDEO_PAGE_INDEX);

    /*close the songs if a video will be opened*/
    MyPLayer->stop();
}

void MainWindow::Esc (void)
{
    ui->Pages_stack->setCurrentIndex(HOME_PAGE_INDEX);

    /*Close the videos when exc is pressed*/
    VideoPlayer->stop();

}





/*************************************************************  BANNA  ********************************************************************/


/*Signal responsible for start songs*/
void MainWindow::on_StartButton_clicked()
{
    /*Play songs*/
    MyPLayer->play();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);



}

/*Signal responsible for pause songs*/
void MainWindow::on_PauseButton_clicked()
{
    /*Pause songs*/
    MyPLayer->pause();
}

/*Signal responsible for Next songs*/
void MainWindow::on_NextButton_clicked()
{
    /*Play the next*/
    Myplaylist->next();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);

}

/*Signal responsible for Prev songs*/
void MainWindow::on_PrevButton_clicked()
{
    /*Play the previous*/
    Myplaylist->previous();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);

}


/*Signal responsible for Mute */
void MainWindow::on_MuteRadioButton_clicked()
{
    static int state=0;
    state^=1;
    MyPLayer->setMuted(state);
}



void MainWindow::on_verticalSlider_valueChanged(int value)
{
    /*Set the Volume according to slider value*/
    MyPLayer->setVolume(value);

    /*Callibration this conditiion is used for mapping the value displaed as it reach only 99/100 so we add 1*/
    if(value>90)
    {
        value+=1;
    }

    /*Convert the number to string*/
    QString VolumeValueinStr = QString::number(value);
}



/*Signal responsible for select specific song*/
void MainWindow::Handle_Button0( )
{
    /*Play the selected song from the GUI*/
    Myplaylist->setCurrentIndex(0);
    MyPLayer->play();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);

}

/*Signal responsible for select specific song*/
void MainWindow::Handle_Button1( )
{
    Myplaylist->setCurrentIndex(1);
    MyPLayer->play();
    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}

/*Signal responsible for select specific song*/
void MainWindow::Handle_Button2( )
{
    /*Play the selected song from the GUI*/
    Myplaylist->setCurrentIndex(2);
    MyPLayer->play();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}


/*Signal responsible for select specific song*/
void MainWindow::Handle_Button3( )
{
    /*Play the selected song from the GUI*/
    Myplaylist->setCurrentIndex(3);
    MyPLayer->play();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}



/*Signal responsible for select specific song*/
void MainWindow::Handle_Button4( )
{
    /*Play the selected song from the GUI*/
    Myplaylist->setCurrentIndex(4);
    MyPLayer->play();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}



/*Signal responsible for select specific song*/
void MainWindow::Handle_Button5( )
{

    /*Play the selected song from the GUI*/
    Myplaylist->setCurrentIndex(5);
    MyPLayer->play();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}



/*Signal responsible for select specific song*/
void MainWindow::Handle_Button6( )
{
    Myplaylist->setCurrentIndex(6);
    MyPLayer->play();
    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}

/*Signal responsible for select specific song*/
void MainWindow::Handle_Button7( )
{
    /*Play the selected song from the GUI*/
    Myplaylist->setCurrentIndex(7);
    MyPLayer->play();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}
void MainWindow::Handle_Button8( )
{
    /*Play the selected song from the GUI*/
    Myplaylist->setCurrentIndex(8);
    MyPLayer->play();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}
void MainWindow::Handle_Button9( )
{
    /*Play the selected song from the GUI*/
    Myplaylist->setCurrentIndex(9);
    MyPLayer->play();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}
void MainWindow::Handle_Button10( )
{
    /*Play the selected song from the GUI*/
    Myplaylist->setCurrentIndex(10);
    MyPLayer->play();

    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}













/****************************************************Date and Time Part*******************************************************************/




void MainWindow::on_Date_OK_clicked()
{

    int Day       ;
    int Month      ;
    int  Year     ;
    int Hours      ;
    int Minutes    ;
    int DayNight ;

    Day = ui->DayComboBox->currentIndex();
    Month = ui->MonthComboBox->currentIndex();
    Year = ui->YearComboBox->currentIndex();

    Hours =ui->HoursComboBox->currentIndex();
    Minutes =ui->Minutes_ComboBox->currentIndex();

    DayNight=ui->DayNight->currentIndex();


    if(Day !=0 && Month!=0 && Year!=0 &&Minutes!=0 && Hours!=0)
    {

        DayIndex=Day;
        MonthIndex=Month;
        YearIndex=Year;
        HoursIndex=Hours;
        MinutesIndex=Minutes;
        DayNightMode=DayNight;

        QString Day = QString::number(DayIndex);
        QString Year = QString::number(Year_MapTable[YearIndex-1]);
        ui->Date->setText(Day+" "+Month_MapTable[MonthIndex-1]+" "+Year);

        QString Hours = QString::number(HoursIndex);
        QString Minutes = QString::number(MinutesIndex);
        QString seconds = QString::number(sec);

        ui->Time->setText(Hours+":"+Minutes+":"+seconds+DayNight_MapTable[DayNightMode]);
        ui->ErrorMsg->clear();

    }
    else
    {
        ui->ErrorMsg->setText("Data you entered is not correct");
    }


}


/*Task implementation*/
void MainWindow::ClockUpdate()
{

    sec++;
    if(sec==59 )
    {
        MinutesIndex++;
        sec=0;
    }

    if(MinutesIndex==59)
    {
        HoursIndex++;
        MinutesIndex=0;
    }

    if(HoursIndex==12)
    {
        HoursIndex=1;
        DayIndex++;
    }

    if(DayIndex==30)
    {
        DayIndex=0;
        MonthIndex++;
    }

    if(MonthIndex==12)
    {
        MonthIndex=1;
        YearIndex++;
    }

    QString Day = QString::number(DayIndex);
    QString Year = QString::number(Year_MapTable[YearIndex-1]);
    ui->Date->setText(Day+" "+Month_MapTable[MonthIndex-1]+" "+Year);

    QString Hours = QString::number(HoursIndex);
    QString Minutes = QString::number(MinutesIndex);
    QString seconds = QString::number(sec);
    ui->Time->setText(Hours+":"+Minutes+":"+seconds+" "+DayNight_MapTable[DayNightMode]);



}



void MainWindow::on_MonthComboBox_currentIndexChanged(int index)
{
    /*variable decleration*/
    static unsigned char Flag_31=0;
    static unsigned char Flag_30=0;
    static unsigned char Flag_29=0;

    qInfo ("%d",index);

    /*check on input index to know the selected month*/
    if(index == 1 || index == 3 || index == 5 || index == 7 || index == 8 || index == 10 || index == 12)
    {

        if(Flag_30==1 && Flag_31==0 && Flag_29==0)
        {
            ui->DayComboBox->addItem("31");
        }
        else if(Flag_30==0 && Flag_31==0 && Flag_29==1)
        {
            ui->DayComboBox->addItem("30");
            ui->DayComboBox->addItem("31");
        }
        Flag_31=1;
        Flag_30=0;
        Flag_29=0;
    }

    else if(index == 4 || index == 6 || index == 9|| index == 11)
    {
        if(Flag_30==0 && Flag_31==0 && Flag_29==1)
        {
            ui->DayComboBox->addItem("30");
        }
        else if(Flag_30==0 && Flag_31==1 && Flag_29==0)
        {
            ui->DayComboBox->removeItem(31);
        }
        Flag_31=0;
        Flag_30=1;
        Flag_29=0;
    }

    else if(index==2)
    {
        if(Flag_30==1 && Flag_31==0 && Flag_29==0)
        {
            ui->DayComboBox->removeItem(30);
        }
        else if(Flag_30==0 && Flag_31==1 && Flag_29==0)
        {
            ui->DayComboBox->removeItem(31);
            ui->DayComboBox->removeItem(30);
        }
        Flag_31=0;
        Flag_30=0;
        Flag_29=1;
    }

}



/**********************************************  Video Part ************************************************/


/*Play when buttom pressed*/
void MainWindow::on_VideoPlay_clicked()
{
    VideoPlayer->play();
}

/*Next when buttom pressed*/
void MainWindow::on_NextVideo_clicked()
{
    VideoMyplaylist->next();

}

/*Pause when buttom pressed*/
void MainWindow::on_VideoPause_clicked()
{
    VideoPlayer->pause();
}



/*Stop when buttom pressed*/
void MainWindow::on_VideoStop_clicked()
{
    VideoPlayer->stop();
}

/*Previos when buttom pressed*/
void MainWindow::on_VideoPrevious_clicked()
{
    VideoMyplaylist->previous();

}

/*Mute when buttom pressed*/
void MainWindow::on_MuteRadioButtom_clicked()
{
    static int state=0;
    state^=1;
    VideoPlayer->setMuted(state);
}


/*change volume when slider value changed*/
void MainWindow::on_VerticalVolumeSlider_valueChanged(int value)
{
    /*Set the Volume according to slider value*/
    VideoPlayer->setVolume(value);
}


/****************************************Camera STart when button is pressed*********************************************************************************************************/

/*Open Camera when buttom is pressed*/

void MainWindow::on_HomeW_CameraBtn_clicked()
{
    ui->Pages_stack->setCurrentIndex(CAMERA_PAGE_INDEX);

    mCamera->start();
}
/*******************************Camera Input Signal Update**************************************************************************************/
void MainWindow::CameraUpdate()
{

    /*Variable definition*/
    static unsigned char CameraLastStateFlag=0;  //0--> mean the camera window is OFF

    if(digitalRead(0)==1 && CameraLastStateFlag==0)
    {
        VideoPlayer->stop();

        //Switch to camera window
        ui->Pages_stack->setCurrentIndex(CAMERA_PAGE_INDEX);

        //enable the camera
        mCamera->start();

        CameraLastStateFlag=1;
        qInfo("camera on");

    }

    else if(digitalRead(0)==0 && CameraLastStateFlag==1)
    {
        //disable the camera
        mCamera->stop();

        //Switch to home window
        ui->Pages_stack->setCurrentIndex(HOME_PAGE_INDEX);

        CameraLastStateFlag=0;
        qInfo("camera off");

    }



}




