#include "dvdplayer.h"

#include <iostream>
using namespace std;

DVDPlayer::DVDPlayer()
{
}

void DVDPlayer::on() const
{
    cout << "Top-O-Line DVD Player on" << endl;
}

void DVDPlayer::off() const
{
    cout << "Top-O-Line DVD Player off" << endl;
}

void DVDPlayer::eject() const
{
    cout << "Top-O-Line DVD Player eject" << endl;
}

void DVDPlayer::pause() const
{
    cout << "Top-O-Line DVD Player pause" << endl;
}

void DVDPlayer::setSurroundAudio() const
{
    cout << "Top-O-Line DVD Player surround sound on (5 speakers, 1 subwoofer)" << endl;
}

void DVDPlayer::setTwoChannelAudio() const
{
    cout << "Top-O-Line DVD Player two channel sound on (5 speakers, 1 subwoofer)" << endl;
}

void DVDPlayer::play() const
{
    cout << "Top-O-Line DVD Player play" << endl;
}

void DVDPlayer::stop() const
{
    cout << "Top-O-Line DVD Player stop" << endl;
}
