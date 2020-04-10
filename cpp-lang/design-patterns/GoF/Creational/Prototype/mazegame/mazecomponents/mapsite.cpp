#include "mapsite.h"

#include <typeinfo>

void MapSite::print(std::ostream &os) const
{
    os << typeid(*this).name() << std::endl;
}
