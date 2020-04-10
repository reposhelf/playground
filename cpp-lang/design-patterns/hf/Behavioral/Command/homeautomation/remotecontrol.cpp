#include "remotecontrol.h"
#include "nocommand.h"

#include <typeinfo>

RemoteControl::RemoteControl()
{
    for (int i = 0; i < SlotCount; ++i) {
        _onCommands[i] = new NoCommand;
        _offCommands[i] = new NoCommand;
    }
    _undoCommand = new NoCommand;
}

RemoteControl::~RemoteControl()
{
    for (int i = 0; i < SlotCount; ++i) {
        delete _onCommands[i];
        delete _offCommands[i];
    }
    delete _undoCommand;
}

void RemoteControl::setCommand(int slot, Command *onCommand, Command *offCommand)
{
    if ((slot < 0) || (slot >= SlotCount))
        return;
    if (_onCommands[slot])
        delete _onCommands[slot];
    if (_offCommands[slot])
        delete _offCommands[slot];

    _onCommands[slot] = onCommand;
    _offCommands[slot] = offCommand;
}

void RemoteControl::buttonOnPressed(int slot)
{
    if ((slot < 0) || (slot >= SlotCount))
        return;
    if (_onCommands[slot]) {
        _onCommands[slot]->execute();
        _undoCommand = _onCommands[slot];
    }
}

void RemoteControl::buttonOffPressed(int slot)
{
    if ((slot < 0) || (slot >= SlotCount))
        return;
    if (_offCommands[slot]) {
        _offCommands[slot]->execute();
        _undoCommand = _offCommands[slot];
    }
}

void RemoteControl::buttonUndoPressed() const
{
    _undoCommand->undo();
}

std::string RemoteControl::info() const
{
    std::string result = "-------- Remote Control --------\n";
    for (int i = 0; i < SlotCount; ++i) {
        result += "[slot " + std::to_string(i) + "] "
                + typeid(*_onCommands[i]).name() + "\t"
                + typeid(*_offCommands[i]).name() + "\n";
    }
    return result;
}
