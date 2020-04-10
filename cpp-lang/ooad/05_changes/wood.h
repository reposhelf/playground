#ifndef WOOD_H
#define WOOD_H

#include <string>

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

std::string woodToString(Wood wood);

#endif // WOOD_H
