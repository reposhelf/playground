#ifndef ROOM_H
#define ROOM_H

#include <memory>

#include "mazecomponents/mapsite.h"

class Room : public MapSite
{
public:
    Room() = default;
    Room(const Room &other);

    std::shared_ptr<MapSite> getSide(MapSite::Direction direction) const;
    void setSide(MapSite::Direction direction, std::shared_ptr<MapSite> side);

    virtual void initialize(int roomNo);
    virtual std::shared_ptr<Room> clone() const;
    void enter() override;
    void print(std::ostream &os) const override;
private:
    static constexpr int SidesCount = 4;
    std::shared_ptr<MapSite> m_sides[SidesCount];
    int m_roomNo = -1;
};

#endif // ROOM_H
