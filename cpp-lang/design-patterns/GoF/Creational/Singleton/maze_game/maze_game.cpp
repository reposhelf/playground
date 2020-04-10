#include "maze_game.h"
#include "maze_factory.h"

std::shared_ptr<Maze> MazeGame::create_maze() const {
    auto maze = MazeFactory::instance()->make_maze();
    auto room1 = MazeFactory::instance()->make_room(1);
    auto room2 = MazeFactory::instance()->make_room(2);
    auto door = MazeFactory::instance()->make_door(room1, room2);

    maze->add_room(room1);
    maze->add_room(room2);

    room1->set_side(MapSite::North, MazeFactory::instance()->make_wall());
    room1->set_side(MapSite::East, door);
    room1->set_side(MapSite::South, MazeFactory::instance()->make_wall());
    room1->set_side(MapSite::West, MazeFactory::instance()->make_wall());

    room2->set_side(MapSite::North, MazeFactory::instance()->make_wall());
    room2->set_side(MapSite::East, MazeFactory::instance()->make_wall());
    room2->set_side(MapSite::South, MazeFactory::instance()->make_wall());
    room2->set_side(MapSite::West, door);

    return maze;
}
