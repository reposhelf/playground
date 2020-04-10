#ifndef CLOCKTIMER_H
#define CLOCKTIMER_H

#include "subject.h"

#include <QTimer>

class ClockTimer final : public Subject
{
public:
    ClockTimer();
    ~ClockTimer() = default;

    int hour() const;
    int minute() const;
    int second() const;

private:
    QTimer _timer;
};

#endif // CLOCKTIMER_H
