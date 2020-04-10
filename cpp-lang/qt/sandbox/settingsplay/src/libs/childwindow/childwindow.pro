#-------------------------------------------------
#
# Project created by QtCreator 2016-08-11T13:46:09
#
#-------------------------------------------------

QT       += widgets

QT       -= gui

TARGET = childwindow
TEMPLATE = lib

DEFINES += CHILDWINDOW_LIBRARY

SOURCES += childwindow.cpp

HEADERS += childwindow.h\
        childwindow_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
