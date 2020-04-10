#include "cellingfanhighcommand.h"
#include "cellingfan.h"

CellingFanHighCommand::CellingFanHighCommand(CellingFan *cellingFan)
    : _cellingFan(cellingFan),
      _lastSpeed(static_cast<int>(CellingFan::Off))
{
}

CellingFanHighCommand::~CellingFanHighCommand()
{
}

void CellingFanHighCommand::execute() const
{
    _lastSpeed = _cellingFan->speed();
    _cellingFan->high();
}

void CellingFanHighCommand::undo() const
{
    switch (static_cast<CellingFan::Speed>(_lastSpeed)) {
    case CellingFan::Off:
        _cellingFan->off();
        break;
    case CellingFan::High:
        _cellingFan->high();
        break;
    case CellingFan::Medium:
        _cellingFan->medium();
        break;
    case CellingFan::Low:
        _cellingFan->low();
        break;
    default:
        break;
    }
}
