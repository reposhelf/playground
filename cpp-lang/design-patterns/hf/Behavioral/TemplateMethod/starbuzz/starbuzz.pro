TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    caffeinebeverage.cpp \
    tea.cpp \
    coffee.cpp

HEADERS += \
    caffeinebeverage.h \
    tea.h \
    coffee.h
