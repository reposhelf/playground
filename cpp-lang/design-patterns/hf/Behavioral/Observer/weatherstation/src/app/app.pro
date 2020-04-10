TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    weatherdata.cpp \
    weatherdevice.cpp \
    currentconditionsdevice.cpp \
    statisticsdevice.cpp \
    forecastdevice.cpp

HEADERS += \
    weatherdata.h \
    weatherdevice.h \
    currentconditionsdevice.h \
    statisticsdevice.h \
    forecastdevice.h
