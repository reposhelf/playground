#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T11:23:22
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_dynamicmemory
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_dynamicmemory.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../src/corelib/release/ -lcorelib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../src/corelib/debug/ -lcorelib
else:unix: LIBS += -L$$OUT_PWD/../../../src/corelib/ -lcorelib

INCLUDEPATH += $$PWD/../../../src/corelib
DEPENDPATH += $$PWD/../../../src/corelib
