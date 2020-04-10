#-------------------------------------------------
#
# Project created by QtCreator 2016-06-12T13:38:52
#
#-------------------------------------------------

QT       -= core gui

TARGET = duck
TEMPLATE = lib
CONFIG += staticlib

SOURCES += duck.cpp \
    mallardduck.cpp \
    modelduck.cpp

HEADERS += duck.h \
    mallardduck.h \
    modelduck.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../behavior/release/ -lbehavior
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../behavior/debug/ -lbehavior
else:unix: LIBS += -L$$OUT_PWD/../behavior/ -lbehavior

INCLUDEPATH += $$PWD/../behavior
DEPENDPATH += $$PWD/../behavior

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../behavior/release/libbehavior.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../behavior/debug/libbehavior.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../behavior/release/behavior.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../behavior/debug/behavior.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../behavior/libbehavior.a
