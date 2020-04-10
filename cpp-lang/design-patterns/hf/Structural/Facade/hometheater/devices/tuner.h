#ifndef TUNER_H
#define TUNER_H

class Tuner
{
public:
    Tuner();

    void on() const;
    void off() const;
    void setAm() const;
    void setFm() const;
    void setFrequency() const;
};

#endif // TUNER_H
