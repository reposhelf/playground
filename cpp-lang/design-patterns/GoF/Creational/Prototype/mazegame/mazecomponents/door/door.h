#ifndef DOOR_H
#define DOOR_H

#include <memory>
#include <utility>

#include "mazecomponents/mapsite.h"

class Room;
class Door : public MapSite
{
public:
    Door() = default;
    Door(const Door &other);

    virtual void initialize(std::weak_ptr<Room> r1, std::weak_ptr<Room> r2);
    virtual std::shared_ptr<Door> clone() const;
    void enter() override;
private:
    std::pair<std::weak_ptr<Room>, std::weak_ptr<Room>> m_rooms;
};

#endif // DOOR_H
