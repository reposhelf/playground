#ifndef MAZEPROTOTYPEFACTORY_H
#define MAZEPROTOTYPEFACTORY_H

#include <memory>

class Door;
class Maze;
class Room;
class Wall;
class MazePrototypeFactory
{
public:
    MazePrototypeFactory(std::unique_ptr<Room> room,
                         std::unique_ptr<Wall> wall,
                         std::unique_ptr<Door> door);
    virtual std::shared_ptr<Maze> makeMaze() const;
    virtual std::shared_ptr<Room> makeRoom(int roomNo) const;
    virtual std::shared_ptr<Wall> makeWall() const;
    virtual std::shared_ptr<Door> makeDoor(std::weak_ptr<Room> r1,
                                           std::weak_ptr<Room> r2) const;
private:
    std::unique_ptr<Room> m_prototypeRoom;
    std::unique_ptr<Wall> m_prototypeWall;
    std::unique_ptr<Door> m_prototypeDoor;
};

#endif // MAZEPROTOTYPEFACTORY_H
