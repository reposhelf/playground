#include "hometheterfacade.h"
#include "amplifier.h"
#include "tuner.h"
#include "dvdplayer.h"
#include "cdplayer.h"
#include "projector.h"
#include "theaterlights.h"
#include "screen.h"
#include "popcornpopper.h"

#include <iostream>
using namespace std;

HomeTheterFacade::HomeTheterFacade(
        Amplifier *ampfilier,
        Tuner *tuner,
        DVDPlayer *dvdPlayer,
        CDPlayer *cdPlayer,
        Projector *projector,
        TheaterLights *theaterLights,
        Screen *screen,
        PopcornPopper *popcornPopper)
    : m_amplifier(ampfilier),
      m_tuner(tuner),
      m_dvdPlayer(dvdPlayer),
      m_cdPlayer(cdPlayer),
      m_projector(projector),
      m_theaterLights(theaterLights),
      m_screen(screen),
      m_popcornPopper(popcornPopper)
{
}

void HomeTheterFacade::watchMovie() const
{
    cout << "Get ready to watch a movie..." << endl;
    m_popcornPopper->on();
    m_popcornPopper->pop();
    m_theaterLights->dim(10);
    m_screen->down();
    m_projector->on();
    m_projector->wideScreenMode();
    m_amplifier->on();
    m_amplifier->setDVD();
    m_amplifier->setSurroundSound();
    m_amplifier->setVolume(5);
    m_dvdPlayer->on();
    m_dvdPlayer->play();
}

void HomeTheterFacade::endMovie() const
{
    cout << "Shutting movie theater down..." << endl;
    m_popcornPopper->off();
    m_theaterLights->on();
    m_screen->up();
    m_projector->off();
    m_amplifier->off();
    m_dvdPlayer->stop();
    m_dvdPlayer->eject();
    m_dvdPlayer->off();
}
