#include "garagedoorclosecommand.h"
#include "garagedoor.h"

GarageDoorCloseCommand::GarageDoorCloseCommand(GarageDoor *garageDoor)
    : Command(),
      _garageDoor(garageDoor)
{
}

GarageDoorCloseCommand::~GarageDoorCloseCommand()
{
}

void GarageDoorCloseCommand::execute() const
{
    _garageDoor->down();
}

void GarageDoorCloseCommand::undo() const
{
    _garageDoor->up();
}
