#include "cellingfanoncommand.h"
#include "cellingfan.h"

CellingFanOnCommand::CellingFanOnCommand(CellingFan *cellingFan)
    : Command(),
      _cellingFan(cellingFan)
{
}

CellingFanOnCommand::~CellingFanOnCommand()
{
}

void CellingFanOnCommand::execute() const
{
    _cellingFan->high();
}

void CellingFanOnCommand::undo() const
{
    _cellingFan->off();
}
