#include "style.h"

std::string styleToString(Style style)
{
    switch (style) {
    case A:
        return "A";
    case F:
        return "F";
    default:
        break;
    }
    return "Unknown style";
}
