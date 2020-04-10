TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    quackcounter.cpp \
    duckfactory.cpp \
    duckcountingfactory.cpp \
    flock.cpp \
    duckcall.cpp \
    goose.cpp \
    gooseadapter.cpp \
    mallardduck.cpp \
    redheadduck.cpp \
    rubberduck.cpp \
    observable.cpp \
    quackologist.cpp

HEADERS += \
    quackable.h \
    mallardduck.h \
    redheadduck.h \
    rubberduck.h \
    duckcall.h \
    goose.h \
    gooseadapter.h \
    quackcounter.h \
    abstractduckfactory.h \
    duckfactory.h \
    duckcountingfactory.h \
    flock.h \
    quackobservable.h \
    observer.h \
    observable.h \
    quackologist.h
