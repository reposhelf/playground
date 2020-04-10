#include "analogclock.h"

#include "subject.h"
#include "clocktimer.h"

#include <QDebug>

Q_LOGGING_CATEGORY(clockAnalog, "clock.analog")

AnalogClock::AnalogClock(Subject *subject)
    : Clock(),
      Observer(),
      _subject(subject)
{
    if (_subject)
        _subject->attach(this);
}

AnalogClock::~AnalogClock()
{
    if (_subject)
        _subject->detach(this);
}

void AnalogClock::update(Subject *subject)
{
    if (subject == _subject) {
        if (subject)
            showTime();
    }
}

void AnalogClock::showTime() const
{
    if (!_subject)
        return;

    auto subject = dynamic_cast<ClockTimer *>(_subject);
    if (!subject)
        return;

    qCDebug(clockAnalog) << subject->hour() << ':'
                          << subject->minute() << ':'
                          << subject->second();
}
