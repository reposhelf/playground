#include "mazegame.h"

#include "mazecomponents/door/door.h"
#include "mazecomponents/mapsite.h"
#include "mazecomponents/maze/maze.h"
#include "mazecomponents/room/room.h"
#include "mazecomponents/wall/wall.h"
#include "mazeprototypefactory.h"

std::shared_ptr<Maze> MazeGame::createMaze(const MazePrototypeFactory &factory)
{
    auto maze = factory.makeMaze();
    auto room1 = factory.makeRoom(1);
    auto room2 = factory.makeRoom(2);
    auto door = factory.makeDoor(room1, room2);

    maze->addRoom(room1);
    maze->addRoom(room2);

    room1->setSide(MapSite::Direction::North, factory.makeWall());
    room1->setSide(MapSite::Direction::East, door);
    room1->setSide(MapSite::Direction::South, factory.makeWall());
    room1->setSide(MapSite::Direction::West, factory.makeWall());

    room2->setSide(MapSite::Direction::North, factory.makeWall());
    room2->setSide(MapSite::Direction::East, factory.makeWall());
    room2->setSide(MapSite::Direction::South, factory.makeWall());
    room2->setSide(MapSite::Direction::West, door);

    return maze;
}
