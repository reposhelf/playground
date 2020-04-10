#ifndef BOMBEDWALL_H
#define BOMBEDWALL_H

#include "mazecomponents/wall/wall.h"

class BombedWall : public Wall
{
public:
    std::shared_ptr<Wall> clone() const override;
    void enter() override;
    bool hasBomb() const;
private:
    bool m_hasBomb = true;
};

#endif // BOMBEDWALL_H
