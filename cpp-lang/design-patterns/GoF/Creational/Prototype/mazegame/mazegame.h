#ifndef MAZEGAME_H
#define MAZEGAME_H

#include <memory>

class MazePrototypeFactory;
class Maze;
class MazeGame
{
public:
    static std::shared_ptr<Maze> createMaze(const MazePrototypeFactory &factory);
};

#endif // MAZEGAME_H
