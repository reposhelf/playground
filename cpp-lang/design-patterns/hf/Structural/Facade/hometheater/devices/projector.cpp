#include "projector.h"

#include <iostream>
using namespace std;

Projector::Projector()
{
}

void Projector::on() const
{
    cout << "Top-O-Line Projector on" << endl;
}

void Projector::off() const
{
    cout << "Top-O-Line Projector off" << endl;
}

void Projector::tvMode() const
{
    cout << "Top-O-Line Projector in TV mode" << endl;
}

void Projector::wideScreenMode() const
{
    cout << "Top-O-Line Projector in widescreen mode (16x9 aspect ratio)" << endl;
}
