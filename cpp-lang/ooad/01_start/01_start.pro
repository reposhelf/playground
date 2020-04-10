TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    guitar.cpp \
    inventory.cpp \
    type.cpp \
    builder.cpp \
    wood.cpp \
    guitarspec.cpp

HEADERS += \
    guitar.h \
    inventory.h \
    type.h \
    builder.h \
    wood.h \
    guitarspec.h
