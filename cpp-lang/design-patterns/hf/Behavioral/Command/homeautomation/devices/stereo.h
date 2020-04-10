#ifndef STEREO_H
#define STEREO_H

class Stereo
{
public:
    Stereo(const char *location);

    void on() const;
    void off() const;
    void setCD() const;
    void setDVD() const;
    void setRadio() const;
    void setVolume() const;

private:
    const char *_location;
};

#endif // STEREO_H
