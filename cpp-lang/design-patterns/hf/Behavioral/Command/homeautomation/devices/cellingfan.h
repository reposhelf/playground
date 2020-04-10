#ifndef CELLINGFAN_H
#define CELLINGFAN_H


class CellingFan
{
public:
    enum Speed { Off, Low, Medium, High };

    CellingFan(const char *location);

    void high();
    void medium();
    void low();
    void off();

    int speed() const { return _speed; }

private:
    const char *_location;
    int _speed;
};

#endif // CELLINGFAN_H
