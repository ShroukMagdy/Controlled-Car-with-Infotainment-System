#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Qt Version %s\n", QT_VERSION_STR);
 
    QApplication app(argc, argv);
    QLabel *label = new QLabel("Hello Qt5");
    label->show();
    return app.exec();
}
