TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    minicompiler.cpp

SHARED_FOLDER = ../shared
include($$SHARED_FOLDER/shared.pri)

HEADERS += \
    minicompiler.h
