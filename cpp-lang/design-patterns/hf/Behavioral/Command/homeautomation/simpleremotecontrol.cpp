#include "simpleremotecontrol.h"
#include "command.h"

SimpleRemoteControl::SimpleRemoteControl()
    : _slot(nullptr)
{
}

void SimpleRemoteControl::setCommand(Command *command)
{
    _slot = command;
}

void SimpleRemoteControl::buttonPressed() const
{
    if (_slot)
        _slot->execute();
}
