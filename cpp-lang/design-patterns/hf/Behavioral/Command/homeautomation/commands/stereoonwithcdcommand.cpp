#include "stereoonwithcdcommand.h"
#include "stereo.h"

StereoOnWithCDCommand::StereoOnWithCDCommand(Stereo *stereo)
    : Command(),
      _stereo(stereo)
{
}

void StereoOnWithCDCommand::execute() const
{
    _stereo->on();
    _stereo->setCD();
    _stereo->setVolume();
}

void StereoOnWithCDCommand::undo() const
{
    _stereo->off();
}
