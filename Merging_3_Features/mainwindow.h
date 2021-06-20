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
#include <QComboBox>
#include <QVideoWidget>


#define HOME_PAGE_INDEX            0
#define SETTINGS_PAGE_INDEX        1
#define MUSIC_PAGE_INDEX           2
#define VIDEO_PAGE_INDEX           3
#define SPEEDOMETER_PAGE_INDEX     4


#define NUMBER_OF_SONGS     8

#define AM  0
#define PM  1


#define INITIAL_SECONDS     0
#define INITIAL_MINUTES     2
#define INITIAL_HOURS       9
#define INITIAL_MONTH       6
#define INITIAL_DAY         18
#define INITIAL_YEAR_INDEX  1
#define INITIAL_MODE_TIME   AM




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    /********************************************************* Object creation for Audio Part*********************************************/

    /*object of pointer of Mp3 player*/
    QMediaPlayer *MyPLayer=new QMediaPlayer() ;

   /*Object of pointer of Playlist*/
    QMediaPlaylist *Myplaylist = new QMediaPlaylist();


   /*Slider Object*/
   QAbstractSlider *VolumeSlider = new  QAbstractSlider();

   /*List of strings contains songs names*/
   QString Songs[NUMBER_OF_SONGS] =
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





   /****************************************************************************Object creation for Setting Part**********************************/

   unsigned char sec           =     INITIAL_SECONDS;
   unsigned char DayIndex      =     INITIAL_DAY;
   unsigned char MonthIndex    =     INITIAL_MONTH;
   unsigned char YearIndex     =     INITIAL_YEAR_INDEX;
   unsigned char HoursIndex    =     INITIAL_HOURS;
   unsigned char MinutesIndex  =     INITIAL_MINUTES;
   unsigned char DayNightMode=INITIAL_MODE_TIME;


   QString Month_MapTable[12]={"Jan","Feb","March" ,"Apr","May","Jun" ,"Jul","Aug" ,"Sept","Oct","Nov","Dec"};
   QString DayNight_MapTable[2]={"AM","PM"};
   unsigned short int Year_MapTable[2]={2021,2022};


    /************************************** Object creation for Video Part  ****************************************************************/
   /*Object - pointer of Playlist*/
    QMediaPlaylist *VideoMyplaylist = new QMediaPlaylist();

   /*Object - pointer VideoPlayer*/
   QMediaPlayer *VideoPlayer = new QMediaPlayer();

   /*Object - pointer VideoWidget*/
   QVideoWidget *VideoWidget = new QVideoWidget();




    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

   void on_StartButton_clicked();
   void on_PauseButton_clicked();
   void on_NextButton_clicked();
   void on_PrevButton_clicked();
   void on_MuteRadioButton_clicked();
   void on_verticalSlider_valueChanged(int value);


   void Handle_Button0( );
   void Handle_Button1( );
   void Handle_Button2( );
   void Handle_Button3( );
   void Handle_Button4( );
   void Handle_Button5( );
   void Handle_Button6( );
   void Handle_Button7( );


   void on_MonthComboBox_currentIndexChanged(int index);
   void ClockUpdate();
   void on_Date_OK_clicked();

   void on_VideoPlay_clicked();
   void on_NextVideo_clicked();
   void on_VideoPause_clicked();
   void on_VideoStop_clicked();
   void on_VideoPrevious_clicked();
   void on_MuteRadioButtom_clicked();
   void on_VerticalVolumeSlider_valueChanged(int value);


    void HomeW_MusicBtn_clicked();
    void HomeW_SettingsBtn_clicked();
    void HomeW_SpeedometerBtn_clicked();
    void HomeW_VideoBtn_clicked();
    void Esc(void);




private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
