#include "wood.h"

using std::string;
using Wood::Wood;

string Wood::toString(Wood wood)
{
    switch (wood) {
    case IndinRosewood:
        return "Indian rosewood";
    case BrasilianRosewood:
        return "Brasilian rosewood";
    case Mahogany:
        return "Mahogany";
    case Maple:
        return "Maple";
    case Cocobolo:
        return "Cocobolo";
    case Cedar:
        return "Cedar";
    case Adirondack:
        return "Adirondack";
    case Alder:
        return "Alder";
    case Sitka:
        return "Sitka";
    default:
        break;
    }
    return "Unknown wood";
}
