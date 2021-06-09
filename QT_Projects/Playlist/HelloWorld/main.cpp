#include <QCoreApplication>
//lbrary for debugging ,input and output
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
qDebug() << "Helloooooo";
    return a.exec();
}
