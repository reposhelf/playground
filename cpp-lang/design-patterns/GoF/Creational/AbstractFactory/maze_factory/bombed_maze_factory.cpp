#include "bombed_maze_factory.h"

#include "bombed_wall.h"
#include "room_with_a_bomb.h"

std::shared_ptr<Maze> BombedMazeFactory::make_maze() const {
    return std::make_shared<Maze>();
}

std::shared_ptr<Room> BombedMazeFactory::make_room(int rn) const {
    return std::make_shared<RoomWithABomb>(rn);
}

std::shared_ptr<Door> BombedMazeFactory::make_door(std::weak_ptr<Room> r1,
                                                   std::weak_ptr<Room> r2) const {
    return std::make_shared<Door>(r1, r2);
}

std::shared_ptr<Wall> BombedMazeFactory::make_wall() const {
    return std::make_shared<BombedWall>();
}
