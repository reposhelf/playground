#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "command.h"

#include <vector>

class MacroCommand : public Command
{
public:
    MacroCommand(const std::vector<Command *> commands);
    ~MacroCommand();

    void execute() const;
    void undo() const;

private:
    std::vector<Command *> _commands;
};

#endif // MACROCOMMAND_H
