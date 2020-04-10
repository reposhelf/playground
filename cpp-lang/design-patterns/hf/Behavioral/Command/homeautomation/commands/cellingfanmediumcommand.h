#ifndef CELLINGFANMEDIUMCOMMAND_H
#define CELLINGFANMEDIUMCOMMAND_H

#include "command.h"

class CellingFan;
class CellingFanMediumCommand : public Command
{
public:
    CellingFanMediumCommand(CellingFan *cellingFan);
    ~CellingFanMediumCommand();

    void execute() const;
    void undo() const;

private:
    CellingFan *_cellingFan;
    mutable int _lastSpeed;
};

#endif // CELLINGFANMEDIUMCOMMAND_H
