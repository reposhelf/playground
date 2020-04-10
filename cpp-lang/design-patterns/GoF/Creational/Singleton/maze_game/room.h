#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <memory>

#include "map_site.h"

class Room : public MapSite {
public:
    explicit Room(int);

    std::shared_ptr<MapSite> get_side(MapSite::Direction) const;
    void set_side(MapSite::Direction, std::shared_ptr<MapSite>);

    void enter() override;
    void print(std::ostream&) const override;

private:
    static constexpr int sides_count = 4;

    std::shared_ptr<MapSite> sides_[sides_count];
    int room_number_;
};

#endif
