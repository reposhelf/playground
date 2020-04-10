#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include "clock.h"
#include "observer.h"

#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(clockAnalog)

class Subject;
class AnalogClock final : public Clock, public Observer
{
public:
    AnalogClock(Subject *subject);
    ~AnalogClock();

    void update(Subject *subject);
    void showTime() const;

private:
    Subject *_subject;
};

#endif // ANALOGCLOCK_H
