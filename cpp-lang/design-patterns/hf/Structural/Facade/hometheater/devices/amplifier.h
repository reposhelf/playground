#ifndef AMPLIFIER_H
#define AMPLIFIER_H

class Amplifier
{
public:
    Amplifier();

    void on() const;
    void off() const;
    void setCD() const;
    void setDVD() const;
    void setStereoSound() const;
    void setSurroundSound() const;
    void setTuner() const;
    void setVolume(int val) const;
};

#endif // AMPLIFIER_H
