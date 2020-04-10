#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T16:11:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app
TEMPLATE = app

HEADERS += \
    mainwindow.h

SOURCES += \
    mainwindow.cpp \
    main.cpp

INCLUDEPATH += $$PWD/../libs/cdate
INCLUDEPATH += $$PWD/../libs/cstring
INCLUDEPATH += $$PWD/../plugins/clabel

LIBS += -L$$OUT_PWD/../../lib -lcdate \
    -lcstring \
    -lclabel

DESTDIR += $$OUT_PWD/../../bin
