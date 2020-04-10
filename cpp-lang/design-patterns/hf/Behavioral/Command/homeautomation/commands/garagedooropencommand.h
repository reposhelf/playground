#ifndef GARAGEDOOROPENCOMMAND_H
#define GARAGEDOOROPENCOMMAND_H

#include "command.h"

class GarageDoor;
class GarageDoorOpenCommand : public Command
{
public:
    GarageDoorOpenCommand(GarageDoor *garageDoor);
    ~GarageDoorOpenCommand();

    void execute() const;
    void undo() const;

private:
    GarageDoor *_garageDoor;
};

#endif // GARAGEDOOROPENCOMMAND_H
