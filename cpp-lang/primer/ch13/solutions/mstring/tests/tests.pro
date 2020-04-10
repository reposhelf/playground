TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

STRING_SRC_PATH = ../mstring

SOURCES += main.cpp \
    test_mstring.cpp \
    $$STRING_SRC_PATH/mstring.cpp

CPPUTEST = /home/vova/bin/cpputest-3.7dev
LIBS = -L$$CPPUTEST/lib -lCppUTest
INCLUDEPATH += $$CPPUTEST/include
INCLUDEPATH += ../mstring
