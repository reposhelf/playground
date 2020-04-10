#-------------------------------------------------
#
# Project created by QtCreator 2016-06-12T13:40:46
#
#-------------------------------------------------

QT       -= core gui

TARGET = behavior
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    quackbehavior.cpp \
    flybehavior.cpp \
    flynoway.cpp \
    flyrocketpowered.cpp \
    flywithwings.cpp \
    mutequack.cpp \
    quack.cpp \
    squeak.cpp

HEADERS += \
    quackbehavior.h \
    flybehavior.h \
    flynoway.h \
    flyrocketpowered.h \
    flywithwings.h \
    mutequack.h \
    quack.h \
    squeak.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
