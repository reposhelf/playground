#include "remote.h"

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;

Remote::Remote(DogDoor *door)
    : m_door(door)
{

}

void Remote::pressButton() const
{
    assert(m_door);

    cout << "Pressing the remote control button..." << endl;
    if (m_door->isOpen())
        m_door->close();
    else
        m_door->open();
}
