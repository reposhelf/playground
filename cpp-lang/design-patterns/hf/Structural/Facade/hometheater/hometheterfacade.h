#ifndef HOMETHETERFACADE_H
#define HOMETHETERFACADE_H

class Amplifier;
class Tuner;
class DVDPlayer;
class CDPlayer;
class Projector;
class TheaterLights;
class Screen;
class PopcornPopper;
class HomeTheterFacade
{
public:
    HomeTheterFacade(Amplifier *ampfilier,
                     Tuner *tuner,
                     DVDPlayer *dvdPlayer,
                     CDPlayer *cdPlayer,
                     Projector *projector,
                     TheaterLights *theaterLights,
                     Screen *screen,
                     PopcornPopper *popcornPopper);

    void watchMovie() const;
    void endMovie() const;

private:
    Amplifier *m_amplifier;
    Tuner *m_tuner;
    DVDPlayer *m_dvdPlayer;
    CDPlayer *m_cdPlayer;
    Projector *m_projector;
    TheaterLights *m_theaterLights;
    Screen *m_screen;
    PopcornPopper *m_popcornPopper;
};

#endif // HOMETHETERFACADE_H
