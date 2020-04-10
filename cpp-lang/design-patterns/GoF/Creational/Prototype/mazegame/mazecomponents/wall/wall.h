#ifndef WALL_H
#define WALL_H

#include <memory>

#include "mazecomponents/mapsite.h"

class Wall : public MapSite
{
public:
    virtual std::shared_ptr<Wall> clone() const;
    void enter() override;
};

#endif // WALL_H
