#include "bombedmazegame.h"

#include "bombedwall.h"
#include "roomwithabomb.h"


std::shared_ptr<Wall> BombedMazeGame::make_wall() const
{
    return std::make_shared<BombedWall>();
}

std::shared_ptr<Room> BombedMazeGame::make_room(int rn) const
{
    return std::make_shared<RoomWithABomb>(rn);
}
