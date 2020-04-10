#ifndef WOOD_H
#define WOOD_H

#include <string>

namespace Wood {

enum Wood {
    IndinRosewood,
    BrasilianRosewood,
    Mahogany,
    Maple,
    Cocobolo,
    Cedar,
    Adirondack,
    Alder,
    Sitka
};

std::string toString(Wood wood);

}

#endif // WOOD_H
