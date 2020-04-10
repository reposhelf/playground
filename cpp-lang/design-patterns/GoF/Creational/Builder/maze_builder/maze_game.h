#ifndef MAZE_GAME_H
#define MAZE_GAME_H

#include <memory>

#include "maze.h"

class MazeBuilder;
class MazeGame
{
public:
    std::shared_ptr<Maze> create_maze(MazeBuilder&) const;
};

#endif
