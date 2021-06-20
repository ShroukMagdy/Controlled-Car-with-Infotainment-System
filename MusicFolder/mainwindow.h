#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QTimer>
#include <QString>
#include <QSlider>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>

#define NUMBER_OF_SONGS     8



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

     /*object of pointer of Mp3 player*/
     QMediaPlayer *MyPLayer=new QMediaPlayer() ;

    /*Object of pointer of Playlist*/
     QMediaPlaylist *Myplaylist = new QMediaPlaylist();


    /*Slider Object*/
    QAbstractSlider *VolumeSlider = new  QAbstractSlider();

    /*List of strings contains songs names*/
    QString Songs[8] =
    {
        "EdSheeran_ShapeofYou.mp3",
        "mzmar_el3sfor.mp3",
        "2Pac_EyesOnMe.mp3",
        "Coldplay_ASkyFullOfStars.mp3",
        "Coldplay_Adventure_Of_A_Lifetime.mp3",
        "EdSheeran_Galway Girl.mp3",
        "EdSheeran_Thinking_Out_Loud.mp3",
        "Taylor_Swift_Lover.mp3"
    };




    /*object to cacluate time*/
    QTimer *Timer = new QTimer();

    /*Pointer used to make the layout of AreaScroll*/
    QVBoxLayout *Lay = new QVBoxLayout();





    /*Array of avialable songs to create buttons for them when the user click on them*/
    QPushButton *SongButtons[NUMBER_OF_SONGS];


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_StartButton_clicked();
    void on_PauseButton_clicked();
    void on_NextButton_clicked();
    void on_PrevButton_clicked();
    void on_radioButton_clicked();
    void on_verticalSlider_valueChanged(int value);

    void Handle_Button0( );
    void Handle_Button1( );
    void Handle_Button2( );
    void Handle_Button3( );
    void Handle_Button4( );
    void Handle_Button5( );
    void Handle_Button6( );
    void Handle_Button7( );


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
