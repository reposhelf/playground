#include "wood.h"

std::string woodToString(Wood wood)
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
