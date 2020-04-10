#ifndef BOMBEDMAZEGAME_H
#define BOMBEDMAZEGAME_H

#include "mazegame.h"


class BombedMazeGame : public MazeGame
{
public:
    std::shared_ptr<Wall> make_wall() const override;
    std::shared_ptr<Room> make_room(int) const override;
};

#endif // BOMBEDMAZEGAME_H
