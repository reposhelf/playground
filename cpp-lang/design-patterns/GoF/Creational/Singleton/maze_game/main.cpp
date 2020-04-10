#include <iostream>

#include "maze_game.h"

int main() {
    auto maze = MazeGame().create_maze();
    std::cout << *maze << std::endl;
    return 0;
}
