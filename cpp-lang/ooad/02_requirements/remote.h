#ifndef REMOTE_H
#define REMOTE_H

#include "dogdoor.h"

class Remote
{
public:
    Remote(DogDoor *door);
    void pressButton() const;

private:
    DogDoor *m_door;
};

#endif // REMOTE_H
