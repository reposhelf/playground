#include "maze.h"

void Maze::addRoom(std::shared_ptr<Room> room)
{
    m_rooms.push_back(room);
}

std::shared_ptr<Room> Maze::getRoom(Maze::size_type roomNo) const
{
    if (--roomNo >= m_rooms.size())
            return std::shared_ptr<Room>();
    return m_rooms[roomNo];
}
