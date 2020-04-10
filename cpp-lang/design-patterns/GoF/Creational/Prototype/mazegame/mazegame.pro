TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    mazegame.cpp \
    mazeprototypefactory.cpp \
    mazecomponents/mapsite.cpp \
    mazecomponents/wall/wall.cpp \
    mazecomponents/room/room.cpp \
    mazecomponents/door/door.cpp \
    mazecomponents/maze/maze.cpp \
    mazecomponents/wall/bombedwall.cpp \
    mazecomponents/room/roomwithabomb.cpp

HEADERS += \
    mazegame.h \
    mazeprototypefactory.h \
    mazecomponents/mapsite.h \
    mazecomponents/wall/wall.h \
    mazecomponents/room/room.h \
    mazecomponents/door/door.h \
    mazecomponents/maze/maze.h \
    mazecomponents/wall/bombedwall.h \
    mazecomponents/room/roomwithabomb.h
