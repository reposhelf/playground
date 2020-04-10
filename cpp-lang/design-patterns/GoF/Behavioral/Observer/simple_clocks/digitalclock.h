#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include "clock.h"
#include "observer.h"

#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(clockDigital)

class Subject;
class DigitalClock final : public Clock, public Observer
{
public:
    DigitalClock(Subject *subject);
    ~DigitalClock();

    void update(Subject *subject);
    void showTime() const;

private:
    Subject *_subject;
};

#endif // DIGITALCLOCK_H
