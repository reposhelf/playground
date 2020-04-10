#ifndef TILE_H
#define TILE_H

#include <memory>
#include <vector>

#include "unit.h"

class Tile
{
public:
    Tile() {}
    Tile(const Tile&) = delete;
    Tile& operator=(const Tile&) = delete;

private:
    friend class Board;

    std::vector<std::shared_ptr<Unit>>& get_units() {
        return units_;
    }

    void add_unit(std::shared_ptr<Unit> unit) {
        units_.push_back(unit);
    }

    void remove_units() {
        units_.clear();
    }

    void remove_unit(std::shared_ptr<Unit> unit);

    std::vector<std::shared_ptr<Unit>> units_;
};

#endif // TILE_H
