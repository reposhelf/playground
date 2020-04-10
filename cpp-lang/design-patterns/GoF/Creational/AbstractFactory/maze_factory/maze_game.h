#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include <memory>

#include "maze.h"
#include "maze_factory.h"

class MazeGame {
public:
    std::shared_ptr<Maze> create_maze(const MazeFactory&) const;
};

#endif
