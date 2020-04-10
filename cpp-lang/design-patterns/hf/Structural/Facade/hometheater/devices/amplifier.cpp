#include "amplifier.h"

#include <iostream>
using namespace std;

Amplifier::Amplifier()
{
}

void Amplifier::on() const
{
    cout << "Top-O-Line Amplifier on" << endl;
}

void Amplifier::off() const
{
    cout << "Top-O-Line Amplifier off" << endl;
}

void Amplifier::setCD() const
{
    cout << "Top-O-Line Amplifier setting CD player to Top-O-Line CD Plyer" << endl;
}

void Amplifier::setDVD() const
{
    cout << "Top-O-Line Amplifier setting DVD player to Top-O-Line DVD Plyer" << endl;
}

void Amplifier::setStereoSound() const
{
    cout << "Top-O-Line Amplifier stereo sound on" << endl;
}

void Amplifier::setSurroundSound() const
{
    cout << "Top-O-Line Amplifier surround sound on (5 speakers, 1 subwoofer)" << endl;
}

void Amplifier::setTuner() const
{
    cout << "Top-O-Line Amplifier setting Tuner" << endl;
}

void Amplifier::setVolume(int val) const
{
    cout << "Top-O-Line Amplifier setting volume to " << val << endl;
}
