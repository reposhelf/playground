#ifndef NOCOMMAND_H
#define NOCOMMAND_H

#include "command.h"

class NoCommand : public Command
{
public:
    NoCommand();

    void execute() const;
    void undo() const;
};

#endif // NOCOMMAND_H
