#include "board.h"

#include <algorithm>

Board::Board(unsigned width, unsigned height)
    : width_(width), height_(height)
{
    Initialize();
}

void Board::Initialize()
{
    for (unsigned i = 0; i != width_; ++i) {
        std::vector<std::shared_ptr<Tile>> row(height_);
        std::generate(row.begin(), row.end(),
                      []{return std::shared_ptr<Tile>(new Tile());});
        tiles_.push_back(row);
    }
}
