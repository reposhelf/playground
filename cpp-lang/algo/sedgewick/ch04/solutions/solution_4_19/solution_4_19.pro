TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    minicalculator.cpp

SHARED_FOLDER = ../shared
include($$SHARED_FOLDER/shared.pri)

HEADERS += \
    minicalculator.h \
    global.h
