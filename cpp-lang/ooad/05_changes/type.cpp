#include "type.h"

std::string typeToString(Type type)
{
    switch (type) {
    case Acoustic:
        return "Acoustic";
    case Electric:
        return "Electric";
    default:
        break;
    }
    return "Unknown type";
}
