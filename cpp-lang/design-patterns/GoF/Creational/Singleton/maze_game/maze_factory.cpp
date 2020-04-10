#include "maze_factory.h"

MazeFactory *MazeFactory::instance_ = nullptr;

MazeFactory *MazeFactory::instance()
{
    if (!instance_)
        instance_ = new MazeFactory();
    return instance_;
}

std::shared_ptr<Maze> MazeFactory::make_maze() const {
    return std::make_shared<Maze>();
}

std::shared_ptr<Room> MazeFactory::make_room(int rn) const {
    return std::make_shared<Room>(rn);
}

std::shared_ptr<Wall> MazeFactory::make_wall() const {
    return std::make_shared<Wall>();
}

std::shared_ptr<Door> MazeFactory::make_door(std::weak_ptr<Room> r1,
                                             std::weak_ptr<Room> r2) const {
    return std::make_shared<Door>(r1, r2);
}
