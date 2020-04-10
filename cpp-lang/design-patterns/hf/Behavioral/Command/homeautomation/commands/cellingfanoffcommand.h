#ifndef CELLINGFANOFFCOMMAND_H
#define CELLINGFANOFFCOMMAND_H

#include "command.h"

class CellingFan;
class CellingFanOffCommand : public Command
{
public:
    CellingFanOffCommand(CellingFan *cellingFan);
    ~CellingFanOffCommand();

    void execute() const;
    void undo() const;

private:
    CellingFan *_cellingFan;
    mutable int _lastSpeed;
};

#endif // CELLINGFANOFFCOMMAND_H
