TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mapsite.cpp \
    wall.cpp \
    room.cpp \
    door.cpp \
    maze.cpp \
    roomwithabomb.cpp \
    enchantedroom.cpp \
    bombedwall.cpp \
    doorneedingspell.cpp \
    mazegame.cpp \
    bombedmazegame.cpp \
    enchantedmazegame.cpp

HEADERS += \
    mapsite.h \
    wall.h \
    room.h \
    door.h \
    maze.h \
    roomwithabomb.h \
    enchantedroom.h \
    bombedwall.h \
    doorneedingspell.h \
    mazegame.h \
    bombedmazegame.h \
    enchantedmazegame.h
