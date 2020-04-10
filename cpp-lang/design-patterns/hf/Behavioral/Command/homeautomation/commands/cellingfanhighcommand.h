#ifndef CELLINGFANHIGHCOMMAND_H
#define CELLINGFANHIGHCOMMAND_H

#include "command.h"

class CellingFan;
class CellingFanHighCommand : public Command
{
public:
    CellingFanHighCommand(CellingFan *cellingFan);
    ~CellingFanHighCommand();

    void execute() const;
    void undo() const;

private:
    CellingFan *_cellingFan;
    mutable int _lastSpeed;
};

#endif // CELLINGFANHIGHCOMMAND_H
