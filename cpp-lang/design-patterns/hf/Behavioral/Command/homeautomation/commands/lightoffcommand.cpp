#include "lightoffcommand.h"
#include "light.h"

LightOffCommand::LightOffCommand(Light *light)
    : Command(),
      _light(light)
{
}

LightOffCommand::~LightOffCommand()
{
}

void LightOffCommand::execute() const
{
    _light->off();
}

void LightOffCommand::undo() const
{
    _light->on();
}
