#include "cellingfanmediumcommand.h"
#include "cellingfan.h"

CellingFanMediumCommand::CellingFanMediumCommand(CellingFan *cellingFan)
    : _cellingFan(cellingFan),
      _lastSpeed(static_cast<int>(CellingFan::Off))
{
}

CellingFanMediumCommand::~CellingFanMediumCommand()
{
}

void CellingFanMediumCommand::execute() const
{
    _lastSpeed = _cellingFan->speed();
    _cellingFan->medium();
}

void CellingFanMediumCommand::undo() const
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
