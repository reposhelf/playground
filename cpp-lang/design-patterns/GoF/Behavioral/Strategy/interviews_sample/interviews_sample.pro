TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    composition.cpp \
    compositor.cpp \
    simplecompositor.cpp \
    texcompositor.cpp \
    arraycompositor.cpp

HEADERS += \
    composition.h \
    compositor.h \
    simplecompositor.h \
    texcompositor.h \
    arraycompositor.h
