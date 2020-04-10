TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

STRVEC_SRC_PATH = ../strvec

SOURCES += main.cpp \
    test_strvec.cpp \
    $$STRVEC_SRC_PATH/strvec.cpp

CPPUTEST = /home/vova/bin/cpputest-3.7dev
LIBS = -L$$CPPUTEST/lib -lCppUTest
INCLUDEPATH += $$CPPUTEST/include
INCLUDEPATH += ../strvec
