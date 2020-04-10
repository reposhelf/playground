#ifndef BOARD_H
#define BOARD_H

#include <cassert>
#include <memory>
#include <vector>

#include "board_global.h"

#include "unit.h"

#include "tile.h"

class BOARDSHARED_EXPORT Board
{

public:
    Board(unsigned width, unsigned height);
    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;

    void add_unit(std::shared_ptr<Unit> unit, unsigned x, unsigned y) const {
        assert(--x < width_ && --y < height_);
        tiles_[x][y]->add_unit(unit);
    }

    void remove_unit(std::shared_ptr<Unit> unit, unsigned x, unsigned y) const {
        assert(--x < width_ && --y < height_);
        tiles_[x][y]->remove_unit(unit);
    }

    void remove_units(unsigned x, unsigned y) const {
        assert(--x < width_ && --y < height_);
        tiles_[x][y]->remove_units();
    }

    std::vector<std::shared_ptr<Unit>>& get_units(unsigned x, unsigned y) const {
        assert(--x < width_ && --y < height_);
        return tiles_[x][y]->get_units();
    }

private:
    void Initialize();

    unsigned width_;
    unsigned height_;
    std::vector<std::vector<std::shared_ptr<Tile>>> tiles_;
};

#endif // BOARD_H
