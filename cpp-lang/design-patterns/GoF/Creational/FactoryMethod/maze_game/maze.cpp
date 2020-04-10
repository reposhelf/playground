#include "maze.h"


void Maze::add_room(std::shared_ptr<Room> r)
{
    rooms_.push_back(r);
}

std::shared_ptr<Room> Maze::get_room(size_type rn) const
{
    if (--rn >= rooms_.size())
        return std::shared_ptr<Room>();
    return rooms_[rn];
}
