TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
DEFINES += X_WINDOW_SYSTEM

SOURCES += main.cpp \
    window.cpp \
    windowimp.cpp \
    windowsystemfactory.cpp \
    xwindowimp.cpp \
    view.cpp \
    pmwindowimp.cpp

HEADERS += \
    window.h \
    windowimp.h \
    windowsystemfactory.h \
    xwindowimp.h \
    view.h \
    pmwindowimp.h
