TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    gumballmachine.cpp \
    state.cpp \
    noquarterstate.cpp \
    hasquarterstate.cpp \
    soldoutstate.cpp \
    soldstate.cpp \
    winnerstate.cpp

HEADERS += \
    gumballmachine.h \
    state.h \
    noquarterstate.h \
    hasquarterstate.h \
    soldoutstate.h \
    soldstate.h \
    winnerstate.h
