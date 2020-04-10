#include <iostream>

#include "bombed_maze_factory.h"
#include "enchanted_maze_factory.h"
#include "maze_factory.h"
#include "maze_game.h"

int main() {
    MazeGame maze_game;

    MazeFactory maze_factory;
    auto maze = maze_game.create_maze(maze_factory);
    std::cout << *maze << std::endl;

    BombedMazeFactory bombed_maze_factory;
    auto bombed_maze = maze_game.create_maze(bombed_maze_factory);
    std::cout << *bombed_maze << std::endl;

    EnchantedMazeFactory enchanted_maze_factory;
    auto enchanted_maze = maze_game.create_maze(enchanted_maze_factory);
    std::cout << *enchanted_maze << std::endl;

    *bombed_maze = *maze;
    std::cout << *bombed_maze << std::endl;

    return 0;
}
