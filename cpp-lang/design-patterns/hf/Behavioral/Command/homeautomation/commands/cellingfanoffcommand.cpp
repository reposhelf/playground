#include "cellingfanoffcommand.h"
#include "cellingfan.h"

CellingFanOffCommand::CellingFanOffCommand(CellingFan *cellingFan)
    : Command(),
      _cellingFan(cellingFan),
    _lastSpeed(static_cast<int>(CellingFan::Off))
{
}

CellingFanOffCommand::~CellingFanOffCommand()
{
}

void CellingFanOffCommand::execute() const
{
    _lastSpeed = _cellingFan->speed();
    _cellingFan->off();
}

void CellingFanOffCommand::undo() const
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
