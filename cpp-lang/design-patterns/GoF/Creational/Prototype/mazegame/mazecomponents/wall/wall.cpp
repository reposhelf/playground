#include "wall.h"

std::shared_ptr<Wall> Wall::clone() const
{
    return std::make_shared<Wall>(*this);
}

void Wall::enter()
{
    // Empty
}
