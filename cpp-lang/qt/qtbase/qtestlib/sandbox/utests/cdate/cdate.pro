#-------------------------------------------------
#
# Project created by QtCreator 2016-04-21T21:06:54
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_cdate
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += tst_cdate.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH += $$PWD/../../src/libs/cdate

LIBS += -L$$OUT_PWD/../../lib -lcdate
