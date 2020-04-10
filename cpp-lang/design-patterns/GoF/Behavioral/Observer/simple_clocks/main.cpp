#include <QCoreApplication>

#include "analogclock.h"
#include "clocktimer.h"
#include "digitalclock.h"

#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ClockTimer clockTimer;
    DigitalClock digitalClock(&clockTimer);
    AnalogClock analogClock(&clockTimer);

    QTimer::singleShot(10000, &a, &QCoreApplication::quit);

    return a.exec();
}
