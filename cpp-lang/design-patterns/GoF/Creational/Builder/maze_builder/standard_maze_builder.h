#ifndef STANDARD_MAZE_BUILDER_H
#define STANDARD_MAZE_BUILDER_H

#include <memory>

#include "maze_builder.h"

class Maze;
class StandardMazeBuilder : public MazeBuilder
{
public:
    StandardMazeBuilder() = default;
    ~StandardMazeBuilder() = default;

    void buildMaze();
    void buildRoom(int room);
    void buildDoor(int roomFrom, int roomTo);

    std::shared_ptr<Maze> getMaze();
private:
    std::shared_ptr<Maze> currentMaze_;
};

#endif // STANDARD_MAZE_BUILDER_H
