TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    waitress.cpp \
    menucomponent.cpp \
    menuitem.cpp \
    menu.cpp

HEADERS += \
    waitress.h \
    menucomponent.h \
    menuitem.h \
    menu.h
