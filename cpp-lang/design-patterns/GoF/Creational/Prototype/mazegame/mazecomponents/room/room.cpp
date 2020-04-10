#include "room.h"

#include <iterator>

Room::Room(const Room &other)
    : MapSite(),
      m_roomNo(other.m_roomNo)
{
    // sides must be initialized manually by setSide() method
}

std::shared_ptr<MapSite> Room::getSide(MapSite::Direction direction) const
{
    return m_sides[static_cast<int>(direction)];
}

void Room::setSide(MapSite::Direction direction, std::shared_ptr<MapSite> side)
{
    m_sides[static_cast<int>(direction)] = side;
}

void Room::initialize(int roomNo)
{
    m_roomNo = roomNo;
}

std::shared_ptr<Room> Room::clone() const
{
    return std::make_shared<Room>(*this);
}

void Room::enter()
{
    // Empty
}

void Room::print(std::ostream &os) const
{
    MapSite::print(os);

    auto end = std::end(m_sides);
    for (auto it = std::begin(m_sides); it != end; ++it)
        (*it)->print(os);
}
