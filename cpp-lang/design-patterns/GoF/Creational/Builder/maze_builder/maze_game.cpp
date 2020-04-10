#include "maze_game.h"
#include "maze_builder.h"

std::shared_ptr<Maze> MazeGame::create_maze(MazeBuilder &builder) const
{
    builder.buildMaze();

    builder.buildRoom(1);
    builder.buildRoom(2);
    builder.buildDoor(1, 2);

    return builder.getMaze();
}
