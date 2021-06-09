#include <QCoreApplication>
#include <QDebug>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Qt Version %s\n", QT_VERSION_STR);
    QCoreApplication app(argc, argv);
    qDebug() << "Hello Qt5"; 
    return app.exec();
 
}
