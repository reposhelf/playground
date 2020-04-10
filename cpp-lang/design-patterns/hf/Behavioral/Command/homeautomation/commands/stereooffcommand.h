#ifndef STEREOOFFCOMMAND_H
#define STEREOOFFCOMMAND_H

#include "command.h"

class Stereo;
class StereoOffCommand : public Command
{
public:
    StereoOffCommand(Stereo *stereo);

    void execute() const;
    void undo() const;

private:
    Stereo *_stereo;
};

#endif // STEREOOFFCOMMAND_H
