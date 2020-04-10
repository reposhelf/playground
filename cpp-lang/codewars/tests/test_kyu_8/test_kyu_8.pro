#-------------------------------------------------
#
# Project created by QtCreator 2017-11-12T17:17:33
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_kyu_8
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        tst_kyu_8.cpp 

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../kyu_8/release/ -lkyu_8
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../kyu_8/debug/ -lkyu_8
else:unix: LIBS += -L$$OUT_PWD/../../kyu_8/ -lkyu_8

INCLUDEPATH += $$PWD/../../kyu_8
DEPENDPATH += $$PWD/../../kyu_8

include($$PWD/../testutil.pri)
