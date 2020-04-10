#include "nocommand.h"

#include <iostream>
using namespace std;

NoCommand::NoCommand()
{
}

void NoCommand::execute() const
{
    cout << "No Command" << endl;
}

void NoCommand::undo() const
{
    cout << "No Command" << endl;
}
