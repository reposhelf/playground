#include "builder.h"

std::string builderToString(Builder builder)
{
    switch (builder) {
    case Fender:
        return "Fender";
    case Martin:
        return "Martin";
    case Gibson:
        return "Gibson";
    case Collings:
        return "Collings";
    case Olson:
        return "Olson";
    case Ryan:
        return "Ryan";
    case Prs:
        return "PRS";
    case Any:
        return "Any";
    default:
        break;
    }
    return "Unknown builder";
}
