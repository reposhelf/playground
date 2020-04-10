#include "macrocommand.h"

MacroCommand::MacroCommand(const std::vector<Command *> commands)
    : _commands(commands)
{
}

MacroCommand::~MacroCommand()
{
    for (Command *cmd : _commands)
        delete cmd;
}

void MacroCommand::execute() const
{
    for (Command *cmd : _commands)
        cmd->execute();
}

void MacroCommand::undo() const
{
    for (Command *cmd : _commands)
        cmd->undo();
}
