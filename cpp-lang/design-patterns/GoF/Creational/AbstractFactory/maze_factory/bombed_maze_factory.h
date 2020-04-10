#ifndef BOMBED_MAZE_FACTORY_H
#define BOMBED_MAZE_FACTORY_H

#include <memory>

#include "door.h"
#include "maze.h"
#include "maze_factory.h"
#include "room.h"
#include "wall.h"

class BombedMazeFactory : public MazeFactory {
public:
    std::shared_ptr<Maze> make_maze() const override;
    std::shared_ptr<Room> make_room(int) const override;
    std::shared_ptr<Door> make_door(std::weak_ptr<Room>,
                                    std::weak_ptr<Room>) const override;
    std::shared_ptr<Wall> make_wall() const override;
};

#endif
