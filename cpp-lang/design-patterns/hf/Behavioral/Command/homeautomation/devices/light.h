#ifndef LIGHT_H
#define LIGHT_H

class Light
{
public:
    Light(const char *location);

    void on() const;
    void off() const;

private:
    const char *_location;
};

#endif // LIGHT_H
