#ifndef ROOM_WITH_A_BOMB_H
#define ROOM_WITH_A_BOMB_H

#include "room.h"

class RoomWithABomb : public Room {
public:
    explicit RoomWithABomb(int);
    void enter() override;
};

#endif
