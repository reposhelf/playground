#ifndef BUILDER_H
#define BUILDER_H

#include <string>

namespace Builder {

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

std::string toString(Builder builder);

}

#endif // BUILDER_H
