#ifndef GARAGEDOOR_H
#define GARAGEDOOR_H

class GarageDoor
{
public:
    GarageDoor(const char *location);

    void up() const;
    void down() const;
    void stop() const;
    void lightOn() const;
    void lightOff() const;

private:
    const char *_location;
};

#endif // GARAGEDOOR_H
