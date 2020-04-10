#include "type.h"

using std::string;
using Type::Type;

string Type::toString(Type type)
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
