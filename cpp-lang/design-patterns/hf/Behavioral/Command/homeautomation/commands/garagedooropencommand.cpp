#include "garagedooropencommand.h"
#include "garagedoor.h"

GarageDoorOpenCommand::GarageDoorOpenCommand(GarageDoor *garageDoor)
    : Command(),
      _garageDoor(garageDoor)
{
}

GarageDoorOpenCommand::~GarageDoorOpenCommand()
{
}

void GarageDoorOpenCommand::execute() const
{
    _garageDoor->up();
}

void GarageDoorOpenCommand::undo() const
{
    _garageDoor->down();
}
