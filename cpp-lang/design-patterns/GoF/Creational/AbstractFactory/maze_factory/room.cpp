#include "room.h"

#include <iterator>

Room::Room(int room_number)
    : room_number_(room_number) {
    // Empty
}

std::shared_ptr<MapSite> Room::get_side(MapSite::Direction d) const {
    return sides_[d];
}

void Room::set_side(MapSite::Direction d, std::shared_ptr<MapSite> ms) {
    sides_[d] = ms;
}

void Room::enter() {
    // Empty
}

void Room::print(std::ostream &os) const {
    MapSite::print(os);

    auto end = std::end(sides_);
    for (auto it = std::begin(sides_); it != end; ++it)
        (*it)->print(os);
}
