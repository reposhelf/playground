TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

WORDLIST_SRC_PATH = ../wordlist

SOURCES += main.cpp \
    test_wordlist.cpp \
    $$WORDLIST_SRC_PATH/cwordlist.cpp \
    $$WORDLIST_SRC_PATH/shared.cpp

CPPUTEST = /home/vova/bin/cpputest-3.7dev
LIBS = -L$$CPPUTEST/lib -lCppUTest
INCLUDEPATH += $$CPPUTEST/include
INCLUDEPATH += ../wordlist
