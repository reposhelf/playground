#ifndef THEATERLIGHTS_H
#define THEATERLIGHTS_H

class TheaterLights
{
public:
    TheaterLights();

    void on() const;
    void off() const;
    void dim(int val) const;
};

#endif // THEATERLIGHTS_H
