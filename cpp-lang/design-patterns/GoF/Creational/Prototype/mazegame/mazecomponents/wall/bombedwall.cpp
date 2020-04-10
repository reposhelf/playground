#include "bombedwall.h"

std::shared_ptr<Wall> BombedWall::clone() const
{
    return std::make_shared<BombedWall>(*this);
}

void BombedWall::enter()
{
    // Empty
}

bool BombedWall::hasBomb() const
{
    return m_hasBomb;
}
