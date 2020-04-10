#ifndef MAPSITE_H
#define MAPSITE_H

#include <iostream>


class MapSite
{
public:
    MapSite();
    MapSite(const MapSite&) = delete;
    MapSite &operator=(const MapSite&) = delete;
    virtual ~MapSite();

    virtual void enter() = 0;
    virtual void print(std::ostream&) const;

    enum Direction {North, East, South, West};
};
#endif // MAPSITE_H
