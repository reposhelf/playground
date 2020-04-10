#include "digitalclock.h"

#include "subject.h"
#include "clocktimer.h"

#include <QDebug>

Q_LOGGING_CATEGORY(clockDigital, "clock.digital")

DigitalClock::DigitalClock(Subject *subject)
    : Clock(),
      Observer(),
      _subject(subject)
{
    if (_subject)
        _subject->attach(this);
}

DigitalClock::~DigitalClock()
{
    if (_subject)
        _subject->detach(this);
}

void DigitalClock::update(Subject *subject)
{
    if (subject == _subject) {
        if (subject)
            showTime();
    }
}

void DigitalClock::showTime() const
{
    if (!_subject)
        return;

    auto subject = dynamic_cast<ClockTimer *>(_subject);
    if (!subject)
        return;

    qCDebug(clockDigital) << subject->hour() << ':'
                          << subject->minute() << ':'
                          << subject->second();
}
