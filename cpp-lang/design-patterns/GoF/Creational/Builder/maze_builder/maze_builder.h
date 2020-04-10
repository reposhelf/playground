#ifndef MAZE_BUILDER_H
#define MAZE_BUILDER_H

#include <memory>

class Maze;
class MazeBuilder
{
public:
    MazeBuilder() = default;
    MazeBuilder(const MazeBuilder&) = delete;
    MazeBuilder &operator=(const MazeBuilder&) = delete;
    virtual ~MazeBuilder() = default;

    virtual void buildMaze();
    virtual void buildRoom(int);
    virtual void buildDoor(int, int);

    virtual std::shared_ptr<Maze> getMaze();
};

#endif // MAZE_BUILDER_H
