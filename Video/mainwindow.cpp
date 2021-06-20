#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    /*add videos to media*/
    VideoMyplaylist->addMedia(QUrl::fromLocalFile("/home/banna/Video/ImagineDragons_WhateverItTakes.mp4"));
    VideoMyplaylist->addMedia(QUrl::fromLocalFile("/home/banna/Video/RagnBone_ManHumanOfficial.mp4"));


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


}

MainWindow::~MainWindow()
{
    delete ui;
}


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
void MainWindow::on_verticalSlider_valueChanged(int value)
{
    /*Set the Volume according to slider value*/
    VideoPlayer->setVolume(value);
}
