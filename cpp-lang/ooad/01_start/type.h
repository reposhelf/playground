#ifndef TYPE_H
#define TYPE_H

#include <string>

namespace Type {

enum Type {
    Acoustic,
    Electric
};

std::string toString(Type type);

}

#endif // TYPE_H
