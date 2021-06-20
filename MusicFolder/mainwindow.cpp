#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    /*put title for the window*/
    setWindowTitle("Infotainment System");


    /*Adding Songs to the PLaylist*/
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/banna/Qt/Main_Setting_Audio/Songs/EdSheeran_ShapeofYou.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/banna/Qt/Main_Setting_Audio/Songs/mzmar_el3sfor.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/banna/Qt/Main_Setting_Audio/Songs/2Pac_EyesOnMe.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/banna/Qt/Main_Setting_Audio/Songs/Coldplay_ASkyFullOfStars.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/banna/Qt/Main_Setting_Audio/Songs/Coldplay_Adv.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/banna/Qt/Main_Setting_Audio/Songs/EdSheeran_Galway Girl.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/banna/Qt/Main_Setting_Audio/Songs/EdSheeran_Thinking_Out_Loud.mp3"));
    Myplaylist->addMedia(QUrl::fromLocalFile("/home/banna/Qt/Main_Setting_Audio/Songs/Taylor_Swift_Lover.mp3"));


    /*configure the playlist to work in loops*/
    Myplaylist->setPlaybackMode(QMediaPlaylist::Loop);

    /*Set the playlist in the AudioPlayer*/
    MyPLayer->setPlaylist(Myplaylist);

    /*set the volume with low at the first*/
    MyPLayer->setVolume(VOLUME_0);

    /*Object created to use its methods to convert number to string - 10 for decimals format*/
    QString::number(STRING_DECIMALFORMAT);


    /*Loop used to create the button for avaialble songs*/
    for( unsigned char itr=0 ; itr<NUMBER_OF_SONGS ; itr++){

        SongButtons[itr]=new QPushButton(Songs[itr]);
        SongButtons[itr]->show();
        SongButtons[itr]->setFlat(true);
        Lay->addWidget(SongButtons[itr]);

    }

    /*create a layout that contains all buttons inside scrollarea*/
    ui->ScrollSong->setLayout(Lay);

    /*Connect the signal of buttons to slots*/
    connect(SongButtons[0], SIGNAL (clicked()), this, SLOT (Handle_Button0()  )  );
    connect(SongButtons[1], SIGNAL (clicked()), this, SLOT (Handle_Button1()  )  );
    connect(SongButtons[2], SIGNAL (clicked()), this, SLOT (Handle_Button2()  )  );
    connect(SongButtons[3], SIGNAL (clicked()), this, SLOT (Handle_Button3()  )  );
    connect(SongButtons[4], SIGNAL (clicked()), this, SLOT (Handle_Button4()  )  );
    connect(SongButtons[5], SIGNAL (clicked()), this, SLOT (Handle_Button5()  )  );
    connect(SongButtons[6], SIGNAL (clicked()), this, SLOT (Handle_Button6()  )  );
    connect(SongButtons[7], SIGNAL (clicked()), this, SLOT (Handle_Button7()  )  );


}

MainWindow::~MainWindow()
{

    /*Another ptr created from mainwinodw to show the window when the audio window is closed*/
    MainWindow *MainWindowPtr = new MainWindow();
    MainWindowPtr->setVisible(true) ;

    /*Stop the song before closing the audio window*/
    MyPLayer->stop();

    delete ui;
}

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





void MainWindow::on_radioButton_clicked()
{
    static int state=0;
    state^=1;
    MyPLayer->setMuted(state);
}



void MainWindow::on_verticalSlider_valueChanged(int value)
{
    /*Set the Volume according to slider value*/
    MyPLayer->setVolume(value);

    /*this conditiion is used for mapping the value displaed as it reach only 99/100 so we add 1*/
    if(value>90)
    {
        value+=1;
    }

    /*Convert the number to string*/
    QString VolumeValueinStr = QString::number(value);

    /*Show the slider value on label*/
    ui->label_2->setText(VolumeValueinStr + "%");
}




/*Signal responsible for pause songs*/
void MainWindow::Handle_Button0( )
{
    Myplaylist->setCurrentIndex(0);
    MyPLayer->play();
    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);

}

/*Signal responsible for pause songs*/
void MainWindow::Handle_Button1( )
{
    Myplaylist->setCurrentIndex(1);
    MyPLayer->play();
    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}

/*Signal responsible for pause songs*/
void MainWindow::Handle_Button2( )
{
    Myplaylist->setCurrentIndex(2);
    MyPLayer->play();
    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}


/*Signal responsible for pause songs*/
void MainWindow::Handle_Button3( )
{
    Myplaylist->setCurrentIndex(3);
    MyPLayer->play();
    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}



/*Signal responsible for pause songs*/
void MainWindow::Handle_Button4( )
{
    Myplaylist->setCurrentIndex(4);
    MyPLayer->play();
    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}



/*Signal responsible for pause songs*/
void MainWindow::Handle_Button5( )
{
    Myplaylist->setCurrentIndex(5);
    MyPLayer->play();
    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}



/*Signal responsible for pause songs*/
void MainWindow::Handle_Button6( )
{
    Myplaylist->setCurrentIndex(6);
    MyPLayer->play();
    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}

/*Signal responsible for pause songs*/
void MainWindow::Handle_Button7( )
{
    Myplaylist->setCurrentIndex(7);
    MyPLayer->play();
    /*Show the name of the song on the label*/
    ui->CurrentSong_Label->setText( Songs[ Myplaylist->currentIndex() ]);
}




