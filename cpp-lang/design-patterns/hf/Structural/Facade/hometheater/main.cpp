#include "hometheterfacade.h"
#include "amplifier.h"
#include "tuner.h"
#include "dvdplayer.h"
#include "cdplayer.h"
#include "projector.h"
#include "theaterlights.h"
#include "screen.h"
#include "popcornpopper.h"

int main()
{
    Amplifier amplifier;
    Tuner tuner;
    DVDPlayer dvdPlayer;
    CDPlayer cdPlayer;
    Projector projector;
    TheaterLights theaterLights;
    Screen screen;
    PopcornPopper popcornPopper;

    HomeTheterFacade homeTheater(&amplifier,
                                 &tuner,
                                 &dvdPlayer,
                                 &cdPlayer,
                                 &projector,
                                 &theaterLights,
                                 &screen,
                                 &popcornPopper);

    homeTheater.watchMovie();
    homeTheater.endMovie();

    return 0;
}
