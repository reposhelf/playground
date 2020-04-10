TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpthread

SOURCES += main.cpp \
    dogdoor.cpp \
    remote.cpp \
    automaticdoorcloser.cpp \
    barkrecognizer.cpp \
    bark.cpp

HEADERS += \
    dogdoor.h \
    remote.h \
    automaticdoorcloser.h \
    barkrecognizer.h \
    bark.h
