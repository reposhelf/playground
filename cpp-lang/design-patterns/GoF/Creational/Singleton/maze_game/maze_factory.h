#ifndef MAZE_FACTORY_H
#define MAZE_FACTORY_H

#include <memory>

#include "door.h"
#include "maze.h"
#include "room.h"
#include "wall.h"

class MazeFactory {
public:
    static MazeFactory *instance();
    virtual std::shared_ptr<Maze> make_maze() const;
    virtual std::shared_ptr<Room> make_room(int) const;
    virtual std::shared_ptr<Wall> make_wall() const;
    virtual std::shared_ptr<Door> make_door(std::weak_ptr<Room>,
                                            std::weak_ptr<Room>) const;
protected:
    MazeFactory() = default;
private:
    static MazeFactory *instance_;
};

#endif
