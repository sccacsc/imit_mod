//#include <QCoreApplication>
#include <QApplication>
#include "lab8_1.h"
#include "lab8_2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    lab8_1* randomEvent = new lab8_1(&a);
    lab8_2* randomEvents = new lab8_2(&a);

    return a.exec();
}
