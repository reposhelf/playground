#ifndef WALL_H
#define WALL_H

#include "mapsite.h"


class Wall : public MapSite
{
public:
    void enter() override;
};

#endif // WALL_H
