TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    door.cpp \
    map_site.cpp \
    maze.cpp \
    maze_game.cpp \
    room.cpp \
    wall.cpp \
    maze_builder.cpp \
    standard_maze_builder.cpp

HEADERS += \
    door.h \
    map_site.h \
    maze.h \
    maze_game.h \
    room.h \
    wall.h \
    maze_builder.h \
    standard_maze_builder.h
