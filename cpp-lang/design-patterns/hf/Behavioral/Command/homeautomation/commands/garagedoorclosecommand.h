#ifndef GARAGEDOORCLOSECOMMAND_H
#define GARAGEDOORCLOSECOMMAND_H

#include "command.h"

class GarageDoor;
class GarageDoorCloseCommand : public Command
{
public:
    GarageDoorCloseCommand(GarageDoor *garageDoor);
    ~GarageDoorCloseCommand();

    void execute() const;
    void undo() const;

private:
    GarageDoor *_garageDoor;
};

#endif // GARAGEDOORCLOSECOMMAND_H
