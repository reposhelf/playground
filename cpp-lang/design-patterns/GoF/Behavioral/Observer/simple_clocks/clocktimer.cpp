#include "clocktimer.h"

#include <QObject>
#include <QTime>

ClockTimer::ClockTimer()
    : Subject()
{
    QObject::connect(&_timer, &QTimer::timeout, [this] {
        notify();
    });

    _timer.start(1000);
}

int ClockTimer::hour() const
{
    return QTime::currentTime().hour();
}

int ClockTimer::minute() const
{
    return QTime::currentTime().minute();
}

int ClockTimer::second() const
{
    return QTime::currentTime().second();
}
