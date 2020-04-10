#ifndef BOMBED_WALL_H
#define BOMBED_WALL_H

#include "wall.h"

class BombedWall : public Wall {
public:
    void enter() override;
};

#endif
