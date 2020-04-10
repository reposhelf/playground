#include "stereooffcommand.h"
#include "stereo.h"

StereoOffCommand::StereoOffCommand(Stereo *stereo)
    : Command(),
      _stereo(stereo)
{
}

void StereoOffCommand::execute() const
{
    _stereo->off();
}

void StereoOffCommand::undo() const
{
    _stereo->on();
    _stereo->setCD();
    _stereo->setVolume();
}
