#ifndef ROOMWITHABOMB_H
#define ROOMWITHABOMB_H

#include "mazecomponents/room/room.h"

class RoomWithABomb : public Room
{
public:
    RoomWithABomb() = default;
    RoomWithABomb(const RoomWithABomb &other);

    std::shared_ptr<Room> clone() const override;
    void enter() override;
};

#endif // ROOMWITHABOMB_H
