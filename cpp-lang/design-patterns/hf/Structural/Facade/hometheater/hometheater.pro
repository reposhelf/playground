TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += devices

SOURCES += main.cpp \
    devices/popcornpopper.cpp \
    devices/theaterlights.cpp \
    devices/projector.cpp \
    devices/amplifier.cpp \
    devices/dvdplayer.cpp \
    hometheterfacade.cpp \
    devices/tuner.cpp \
    devices/screen.cpp \
    devices/cdplayer.cpp

HEADERS += \
    devices/popcornpopper.h \
    devices/theaterlights.h \
    devices/projector.h \
    devices/amplifier.h \
    devices/dvdplayer.h \
    hometheterfacade.h \
    devices/tuner.h \
    devices/screen.h \
    devices/cdplayer.h
