#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T20:09:42
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_cstring
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += tst_cstring.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += $$PWD/../../src/libs/cstring

LIBS += -L$$OUT_PWD/../../lib -lcstring

