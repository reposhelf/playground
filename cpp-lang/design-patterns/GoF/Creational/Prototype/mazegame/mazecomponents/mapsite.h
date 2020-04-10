#ifndef MAPSITE_H
#define MAPSITE_H

#include <iostream>
#include <memory>

class MapSite
{
public:
    MapSite() = default;
    MapSite(const MapSite&) = default;
    MapSite &operator=(const MapSite&) = delete;
    virtual ~MapSite() = default;

    virtual void enter() = 0;
    virtual void print(std::ostream &os) const;

    enum class Direction { North, East, South, West };
};
#endif // MAPSITE_H
