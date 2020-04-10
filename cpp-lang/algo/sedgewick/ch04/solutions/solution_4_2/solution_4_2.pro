TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

SHARED_FOLDER = ../shared
include($$SHARED_FOLDER/shared.pri)
