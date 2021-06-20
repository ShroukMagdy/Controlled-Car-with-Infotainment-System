#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QProgressBar>
#include <QVideoWidget>
#include <QAbstractVideoSurface>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_VideoPlay_clicked();
    void on_NextVideo_clicked();
    void on_VideoPause_clicked();
    void on_VideoStop_clicked();
    void on_VideoPrevious_clicked();
    void on_MuteRadioButtom_clicked();
    void on_verticalSlider_valueChanged(int value);

private:

    /*Object - pointer of Playlist*/
     QMediaPlaylist *VideoMyplaylist = new QMediaPlaylist();

    /*Object - pointer VideoPlayer*/
    QMediaPlayer *VideoPlayer = new QMediaPlayer();

    /*Object - pointer VideoWidget*/
    QVideoWidget *VideoWidget = new QVideoWidget();

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
