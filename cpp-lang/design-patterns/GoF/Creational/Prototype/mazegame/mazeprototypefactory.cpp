#include "mazeprototypefactory.h"

#include "mazecomponents/door/door.h"
#include "mazecomponents/room/room.h"
#include "mazecomponents/maze/maze.h"
#include "mazecomponents/wall/wall.h"

MazePrototypeFactory::MazePrototypeFactory(std::unique_ptr<Room> room,
                                           std::unique_ptr<Wall> wall,
                                           std::unique_ptr<Door> door)
    : m_prototypeRoom(std::move(room)),
      m_prototypeWall(std::move(wall)),
      m_prototypeDoor(std::move(door))
{
    // Empty
}

std::shared_ptr<Maze> MazePrototypeFactory::makeMaze() const
{
    return std::make_shared<Maze>();
}

std::shared_ptr<Room> MazePrototypeFactory::makeRoom(int roomNo) const
{
    auto room = m_prototypeRoom->clone();
    room->initialize(roomNo);
    return room;
}

std::shared_ptr<Wall> MazePrototypeFactory::makeWall() const
{
    return m_prototypeWall->clone();
}

std::shared_ptr<Door> MazePrototypeFactory::makeDoor(std::weak_ptr<Room> r1,
                                                     std::weak_ptr<Room> r2) const
{
    auto door = m_prototypeDoor->clone();
    door->initialize(r1, r2);
    return door;
}
