TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += devices \
    commands

SOURCES += main.cpp \
    devices/light.cpp \
    commands/command.cpp \
    commands/lightoncommand.cpp \
    simpleremotecontrol.cpp \
    devices/garagedoor.cpp \
    commands/garagedooropencommand.cpp \
    remotecontrol.cpp \
    commands/nocommand.cpp \
    commands/lightoffcommand.cpp \
    devices/cellingfan.cpp \
    commands/cellingfanoncommand.cpp \
    commands/cellingfanoffcommand.cpp \
    devices/stereo.cpp \
    commands/stereoonwithcdcommand.cpp \
    commands/stereooffcommand.cpp \
    commands/garagedoorclosecommand.cpp \
    commands/cellingfanhighcommand.cpp \
    commands/cellingfanmediumcommand.cpp \
    commands/macrocommand.cpp

HEADERS += \
    devices/light.h \
    commands/command.h \
    commands/lightoncommand.h \
    simpleremotecontrol.h \
    devices/garagedoor.h \
    commands/garagedooropencommand.h \
    remotecontrol.h \
    commands/nocommand.h \
    commands/lightoffcommand.h \
    devices/cellingfan.h \
    commands/cellingfanoncommand.h \
    commands/cellingfanoffcommand.h \
    devices/stereo.h \
    commands/stereoonwithcdcommand.h \
    commands/stereooffcommand.h \
    commands/garagedoorclosecommand.h \
    commands/cellingfanhighcommand.h \
    commands/cellingfanmediumcommand.h \
    commands/macrocommand.h
