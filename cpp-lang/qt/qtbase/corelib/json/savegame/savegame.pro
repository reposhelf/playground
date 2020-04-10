QT += core
QT -= gui

CONFIG += c++11

TARGET = savegame
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    character.cpp \
    level.cpp \
    game.cpp

HEADERS += \
    character.h \
    level.h \
    game.h
