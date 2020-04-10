#ifndef BOMBEDWALL_H
#define BOMBEDWALL_H

#include "wall.h"


class BombedWall : public Wall
{
public:
    void enter() override;
};

#endif // BOMBEDWALL_H
