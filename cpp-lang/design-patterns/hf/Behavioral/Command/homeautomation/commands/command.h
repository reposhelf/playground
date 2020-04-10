#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    Command();
    virtual ~Command();

    virtual void execute() const = 0;
    virtual void undo() const = 0;
};

#endif // COMMAND_H
