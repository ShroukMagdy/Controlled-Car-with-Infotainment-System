#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPlainTextEdit *Pte ;
    QTextEdit *te ;

public  slots :
    void hiii(){
             te->insertPlainText ( "hiiiii" ) ;
             Pte->setPlainText( "bla-bla" ) ;
        }
};

#endif // MAINWINDOW_H
