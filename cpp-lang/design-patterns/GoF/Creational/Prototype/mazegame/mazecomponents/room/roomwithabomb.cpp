#include "roomwithabomb.h"

RoomWithABomb::RoomWithABomb(const RoomWithABomb &other)
    : Room(other)
{
    // Empty
}

std::shared_ptr<Room> RoomWithABomb::clone() const
{
    return std::make_shared<RoomWithABomb>(*this);
}

void RoomWithABomb::enter()
{
    // Empty
}
