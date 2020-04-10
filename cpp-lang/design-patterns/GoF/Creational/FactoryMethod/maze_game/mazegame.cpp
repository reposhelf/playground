#include "mazegame.h"


std::shared_ptr<Maze> MazeGame::create_maze() const
{
    auto maze = make_maze();
    auto room1 = make_room(1);
    auto room2 = make_room(2);
    auto door = make_door(room1, room2);

    maze->add_room(room1);
    maze->add_room(room2);

    room1->set_side(MapSite::North, make_wall());
    room1->set_side(MapSite::East, door);
    room1->set_side(MapSite::South, make_wall());
    room1->set_side(MapSite::West, make_wall());

    room2->set_side(MapSite::North, make_wall());
    room2->set_side(MapSite::East, make_wall());
    room2->set_side(MapSite::South, make_wall());
    room2->set_side(MapSite::West, door);

    return maze;
}

std::shared_ptr<Maze> MazeGame::make_maze() const
{
    return std::make_shared<Maze>();
}

std::shared_ptr<Room> MazeGame::make_room(int rn) const
{
    return std::make_shared<Room>(rn);
}

std::shared_ptr<Wall> MazeGame::make_wall() const
{
    return std::make_shared<Wall>();
}

std::shared_ptr<Door> MazeGame::make_door(std::weak_ptr<Room> r1, std::weak_ptr<Room> r2) const
{
    return std::make_shared<Door>(r1, r2);
}
