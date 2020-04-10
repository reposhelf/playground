#ifndef BUILDER_H
#define BUILDER_H

#include <string>

enum Builder {
    Fender,
    Martin,
    Gibson,
    Collings,
    Olson,
    Ryan,
    Prs,
    Any
};

std::string builderToString(Builder builder);

#endif // BUILDER_H
