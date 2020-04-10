#ifndef CELLINGFANONCOMMAND_H
#define CELLINGFANONCOMMAND_H

#include "command.h"

class CellingFan;
class CellingFanOnCommand : public Command
{
public:
    CellingFanOnCommand(CellingFan *cellingFan);
    ~CellingFanOnCommand();

    void execute() const;
    void undo() const;

private:
    CellingFan *_cellingFan;
};

#endif // CELLINGFANONCOMMAND_H
