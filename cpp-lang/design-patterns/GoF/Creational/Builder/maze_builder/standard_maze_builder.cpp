#include "standard_maze_builder.h"
#include "door.h"
#include "maze.h"
#include "room.h"
#include "wall.h"

void StandardMazeBuilder::buildMaze()
{
    currentMaze_ = std::make_shared<Maze>();
}

void StandardMazeBuilder::buildRoom(int roomNo)
{
    if (currentMaze_ && !currentMaze_->get_room(roomNo)) {
        auto room = std::make_shared<Room>(roomNo);
        currentMaze_->add_room(room);

        room->set_side(MapSite::Direction::North, std::make_shared<Wall>());
        room->set_side(MapSite::Direction::South, std::make_shared<Wall>());
        room->set_side(MapSite::Direction::East, std::make_shared<Wall>());
        room->set_side(MapSite::Direction::West, std::make_shared<Wall>());
    }
}

void StandardMazeBuilder::buildDoor(int roomFrom, int roomTo)
{
    auto room1 = currentMaze_->get_room(roomFrom);
    auto room2 = currentMaze_->get_room(roomTo);
    auto door = std::make_shared<Door>(room1, room2);

    room1->set_side(MapSite::Direction::East, door);
    room2->set_side(MapSite::Direction::West, door);
}

std::shared_ptr<Maze> StandardMazeBuilder::getMaze()
{
    return currentMaze_;
}
