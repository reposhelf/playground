#ifndef DOOR_H
#define DOOR_H

#include <memory>
#include <utility>

#include "mapsite.h"
#include "room.h"


class Door : public MapSite
{
public:
    Door(std::weak_ptr<Room>, std::weak_ptr<Room>);
    void enter() override;

private:
    std::pair<std::weak_ptr<Room>, std::weak_ptr<Room>> rooms_;
};

#endif // DOOR_H
