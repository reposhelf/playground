#include "lightoncommand.h"
#include "light.h"

LightOnCommand::LightOnCommand(Light *light)
    : Command(),
      _light(light)
{
}

LightOnCommand::~LightOnCommand()
{
}

void LightOnCommand::execute() const
{
    _light->on();
}

void LightOnCommand::undo() const
{
    _light->off();
}
