#ifndef STEREOONWITHCDCOMMAND_H
#define STEREOONWITHCDCOMMAND_H

#include "command.h"

class Stereo;
class StereoOnWithCDCommand : public Command
{
public:
    StereoOnWithCDCommand(Stereo *stereo);

    void execute() const;
    void undo() const;

private:
    Stereo *_stereo;
};

#endif // STEREOONWITHCDCOMMAND_H
