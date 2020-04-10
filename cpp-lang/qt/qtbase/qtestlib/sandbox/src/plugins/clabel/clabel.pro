#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T17:09:19
#
#-------------------------------------------------

QT       += widgets

QT       -= core gui

TARGET = clabel
TEMPLATE = lib

DEFINES += CLABEL_LIBRARY

SOURCES += clabel.cpp

HEADERS += clabel.h\
        clabel_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR += $$OUT_PWD/../../../lib
