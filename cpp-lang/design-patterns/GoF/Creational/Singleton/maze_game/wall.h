#ifndef WALL_H
#define WALL_H

#include "map_site.h"

class Wall : public MapSite {
public:
    void enter() override;
};

#endif
