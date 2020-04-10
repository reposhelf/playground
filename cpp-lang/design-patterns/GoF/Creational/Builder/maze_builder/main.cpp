#include <iostream>

#include "maze_game.h"
#include "standard_maze_builder.h"

int main()
{
    MazeGame game;
    StandardMazeBuilder builder;

    game.create_maze(builder);
    auto maze = builder.getMaze();

    std::cout << *maze << std::endl;

    return 0;
}
