#include "mapsite.h"

#include <typeinfo>


MapSite::MapSite()
{
    // Empty
}

MapSite::~MapSite()
{
    // Empty
}

void MapSite::print(std::ostream &os) const
{
    os << typeid(*this).name() << std::endl;
}
