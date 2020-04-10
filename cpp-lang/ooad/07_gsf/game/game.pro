TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../board/release/ -lboard
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../board/debug/ -lboard
else:unix: LIBS += -L$$OUT_PWD/../board/ -lboard

INCLUDEPATH += $$PWD/../board
DEPENDPATH += $$PWD/../board

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../unit/release/ -lunit
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../unit/debug/ -lunit
else:unix: LIBS += -L$$OUT_PWD/../unit/ -lunit

INCLUDEPATH += $$PWD/../unit
DEPENDPATH += $$PWD/../unit
