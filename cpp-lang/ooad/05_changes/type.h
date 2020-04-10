#ifndef TYPE_H
#define TYPE_H

#include <string>

enum Type {
    Acoustic,
    Electric
};

std::string typeToString(Type type);

#endif // TYPE_H
