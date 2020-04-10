#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T15:31:15
#
#-------------------------------------------------

QT       -= gui

TARGET = cdate
TEMPLATE = lib

DEFINES += CDATE_LIBRARY

SOURCES += cdate.cpp

HEADERS += cdate.h\
        cdate_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR += $$OUT_PWD/../../../lib
