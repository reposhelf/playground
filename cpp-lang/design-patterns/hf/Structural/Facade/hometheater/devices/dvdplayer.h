#ifndef DVDPLAYER_H
#define DVDPLAYER_H

class DVDPlayer
{
public:
    DVDPlayer();

    void on() const;
    void off() const;
    void eject() const;
    void pause() const;
    void setSurroundAudio() const;
    void setTwoChannelAudio() const;
    void play() const;
    void stop() const;
};

#endif // DVDPLAYER_H
