#ifndef CDPLAYER_H
#define CDPLAYER_H

class CDPlayer
{
public:
    CDPlayer();

    void on() const;
    void off() const;
    void eject() const;
    void play() const;
    void pause() const;
    void stop() const;
};

#endif // CDPLAYER_H
