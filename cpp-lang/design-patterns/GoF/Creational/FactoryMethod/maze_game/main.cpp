#include <iostream>

#include "bombedmazegame.h"
#include "enchantedmazegame.h"
#include "mazegame.h"


int main()
{
    MazeGame mazeGame;
    auto maze = mazeGame.create_maze();
    std::cout << *maze << std::endl;

    BombedMazeGame bombedMazeGame;
    auto bombedMaze = bombedMazeGame.create_maze();
    std::cout << *bombedMaze << std::endl;

    EnchantedMazeGame enchantedMazeGame;
    auto enchantedMaze = enchantedMazeGame.create_maze();
    std::cout << *enchantedMaze << std::endl;

    return 0;
}
