#include <iostream>
#include <memory>

#include "mazecomponents/wall/bombedwall.h"
#include "mazecomponents/door/door.h"
#include "mazecomponents/maze/maze.h"
#include "mazecomponents/room/roomwithabomb.h"
#include "mazecomponents/wall/wall.h"
#include "mazegame.h"
#include "mazeprototypefactory.h"

int main()
{
    MazePrototypeFactory simpleMazeFactory(
                std::make_unique<Room>(),
                std::make_unique<Wall>(),
                std::make_unique<Door>());

    auto simpleMaze = MazeGame::createMaze(simpleMazeFactory);
    std::cout << *simpleMaze << std::endl;

    MazePrototypeFactory bombedMazeFactory(
                std::make_unique<RoomWithABomb>(),
                std::make_unique<BombedWall>(),
                std::make_unique<Door>());

    auto bombedMaze = MazeGame::createMaze(bombedMazeFactory);
    std::cout << *bombedMaze << std::endl;

    return 0;
}
