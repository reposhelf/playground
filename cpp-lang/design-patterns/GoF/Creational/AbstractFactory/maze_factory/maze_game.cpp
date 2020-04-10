#include "maze_game.h"

std::shared_ptr<Maze> MazeGame::create_maze(const MazeFactory &factory) const {
    auto maze = factory.make_maze();
    auto room1 = factory.make_room(1);
    auto room2 = factory.make_room(2);
    auto door = factory.make_door(room1, room2);

    maze->add_room(room1);
    maze->add_room(room2);

    room1->set_side(MapSite::North, factory.make_wall());
    room1->set_side(MapSite::East, door);
    room1->set_side(MapSite::South, factory.make_wall());
    room1->set_side(MapSite::West, factory.make_wall());

    room2->set_side(MapSite::North, factory.make_wall());
    room2->set_side(MapSite::East, factory.make_wall());
    room2->set_side(MapSite::South, factory.make_wall());
    room2->set_side(MapSite::West, door);

    return maze;
}
