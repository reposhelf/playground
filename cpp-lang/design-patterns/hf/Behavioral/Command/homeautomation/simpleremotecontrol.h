#ifndef SIMPLEREMOTECONTROL_H
#define SIMPLEREMOTECONTROL_H

class Command;
class SimpleRemoteControl
{
public:
    SimpleRemoteControl();

    void setCommand(Command *command);
    void buttonPressed() const;

private:
    Command *_slot;
};

#endif // SIMPLEREMOTECONTROL_H
