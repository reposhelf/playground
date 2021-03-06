#ifndef MAZEGAME_H
#define MAZEGAME_H

#include <memory>

#include "door.h"
#include "maze.h"
#include "room.h"
#include "wall.h"


class MazeGame
{
public:
    std::shared_ptr<Maze> create_maze() const;

    // factory methods
    virtual std::shared_ptr<Maze> make_maze() const;
    virtual std::shared_ptr<Room> make_room(int) const;
    virtual std::shared_ptr<Wall> make_wall() const;
    virtual std::shared_ptr<Door> make_door(std::weak_ptr<Room>, std::weak_ptr<Room>) const;
};

#endif // MAZEGAME_H
