TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    maze.cpp \
    room.cpp \
    wall.cpp \
    door.cpp \
    map_site.cpp \
    maze_factory.cpp \
    maze_game.cpp

HEADERS += \
    maze.h \
    room.h \
    wall.h \
    door.h \
    map_site.h \
    maze_factory.h \
    maze_game.h
