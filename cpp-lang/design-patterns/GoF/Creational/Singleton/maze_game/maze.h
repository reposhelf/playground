#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <memory>
#include <typeinfo>
#include <vector>

#include "room.h"

class Maze {
public:
    using size_type = std::vector<std::shared_ptr<Room>>::size_type;

    void add_room(std::shared_ptr<Room>);
    std::shared_ptr<Room> get_room(size_type) const;

private:
    friend std::ostream &operator<<(std::ostream&, const Maze&);

    std::vector<std::shared_ptr<Room>> rooms_;
};

inline std::ostream &operator<<(std::ostream &os, const Maze &m) {
    os << typeid(m).name() << std::endl;
    for (auto r : m.rooms_)
        r->print(os);
    return os;
}

#endif
