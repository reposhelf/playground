#include "door.h"

Door::Door(std::weak_ptr<Room> r1, std::weak_ptr<Room> r2) {
    rooms_ = std::make_pair(r1, r2);
}

void Door::enter() {
    // Empty
}
