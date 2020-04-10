#-------------------------------------------------
#
# Project created by QtCreator 2016-08-11T12:52:29
#
#-------------------------------------------------

QT       += widgets

QT       -= gui

TARGET = corelib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += window.cpp

HEADERS += window.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/childwindow/release/ -lchildwindow
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/childwindow/debug/ -lchildwindow
else:unix: LIBS += -L$$OUT_PWD/../libs/childwindow/ -lchildwindow

INCLUDEPATH += $$PWD/../libs/childwindow
DEPENDPATH += $$PWD/../libs/childwindow
