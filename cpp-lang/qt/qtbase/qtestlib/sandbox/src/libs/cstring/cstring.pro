#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T15:33:50
#
#-------------------------------------------------

QT       -= gui

TARGET = cstring
TEMPLATE = lib

DEFINES += CSTRING_LIBRARY

SOURCES += cstring.cpp

HEADERS += cstring.h\
        cstring_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR += $$OUT_PWD/../../../lib
