#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include <memory>

#include "maze.h"

class MazeGame {
public:
    std::shared_ptr<Maze> create_maze() const;
};

#endif
