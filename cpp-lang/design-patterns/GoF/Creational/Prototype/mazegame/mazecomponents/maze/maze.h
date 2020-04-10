#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>

#include "mazecomponents/room/room.h"

class Maze
{
public:
    using size_type = std::vector<std::shared_ptr<Room>>::size_type;

    Maze() = default;
    Maze(const Maze&) = delete;
    Maze &operator=(const Maze&) = delete;

    void addRoom(std::shared_ptr<Room> room);
    std::shared_ptr<Room> getRoom(size_type roomNo) const;

private:
    friend std::ostream &operator<<(std::ostream &os, const Maze &m);

    std::vector<std::shared_ptr<Room>> m_rooms;
};

inline std::ostream &operator<<(std::ostream &os, const Maze &m) {
    os << typeid(m).name() << std::endl;
    for (auto r : m.m_rooms)
        r->print(os);
    return os;
}

#endif // MAZE_H
