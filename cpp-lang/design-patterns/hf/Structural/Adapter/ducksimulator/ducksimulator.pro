TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ducks/duck.cpp \
    ducks/mallardduck.cpp \
    turkeys/turkey.cpp \
    turkeys/wildturkey.cpp \
    adapters/turkeyadapter.cpp \
    adapters/duckadapter.cpp

HEADERS += \
    ducks/duck.h \
    ducks/mallardduck.h \
    turkeys/turkey.h \
    turkeys/wildturkey.h \
    adapters/turkeyadapter.h \
    adapters/duckadapter.h

INCLUDEPATH += ducks \
    turkeys \
    adapters
