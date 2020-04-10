#include "tile.h"

#include <algorithm>
#include <iostream>

void Tile::remove_unit(std::shared_ptr<Unit> unit)
{
    auto it = std::find(units_.begin(), units_.end(), unit);
    if (it == units_.end()) {
        std::cerr << "Cannot find unit to remove" << std::endl;
        return;
    }
    units_.erase(it);
}
