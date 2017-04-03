#include <QApplication>
#include "controller/maincontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainController mc( &a );

    // Maintain in loop
    return a.exec();
}
