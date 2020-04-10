#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include <string>

class Command;
class RemoteControl
{
public:
    RemoteControl();
    ~RemoteControl();

    void setCommand(int slot, Command *onCommand, Command *offCommand);
    void buttonOnPressed(int slot);
    void buttonOffPressed(int slot);
    void buttonUndoPressed() const;

    std::string info() const;

private:
    enum { SlotCount = 7 };
    Command *_onCommands[SlotCount];
    Command *_offCommands[SlotCount];
    Command *_undoCommand;
};

#endif // REMOTECONTROL_H
