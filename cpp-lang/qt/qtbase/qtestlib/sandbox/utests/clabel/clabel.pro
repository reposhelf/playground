#-------------------------------------------------
#
# Project created by QtCreator 2016-04-22T17:26:30
#
#-------------------------------------------------

QT       += testlib widgets

QT       -= gui

TARGET = tst_clabel
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_clabel.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += $$PWD/../../src/plugins/clabel

LIBS += -L$$OUT_PWD/../../lib -lclabel
