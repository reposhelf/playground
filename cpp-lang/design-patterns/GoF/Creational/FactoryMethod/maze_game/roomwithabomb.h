#ifndef ROOMWITHABOMB_H
#define ROOMWITHABOMB_H

#include "room.h"


class RoomWithABomb : public Room
{
public:
    explicit RoomWithABomb(int);
    void enter() override;
};

#endif // ROOMWITHABOMB_H
