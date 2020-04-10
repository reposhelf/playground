#include "door.h"

Door::Door(const Door&)
    : MapSite()
{
    // must be initialize manually by initialize() method
}

void Door::initialize(std::weak_ptr<Room> r1, std::weak_ptr<Room> r2)
{
    m_rooms = std::make_pair(r1, r2);
}

std::shared_ptr<Door> Door::clone() const
{
    return std::make_shared<Door>(*this);
}

void Door::enter()
{
    // Empty
}
