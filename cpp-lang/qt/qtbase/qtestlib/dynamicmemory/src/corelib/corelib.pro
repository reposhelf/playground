#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T10:50:05
#
#-------------------------------------------------

QT       += widgets

QT       -= gui

TARGET = corelib
TEMPLATE = lib

DEFINES += CORELIB_LIBRARY

SOURCES += dynamicmemory.cpp \
    dynamicmemorywidget.cpp \
    presetnamedialog.cpp \
    dynamicmemorypreset.cpp

HEADERS += dynamicmemory.h\
        corelib_global.h \
    dynamicmemorywidget.h \
    presetnamedialog.h \
    dynamicmemorypreset.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    dynamicmemorywidget.ui

RESOURCES += \
    icons.qrc

DISTFILES +=
