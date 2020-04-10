TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/duck/release/ -lduck
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/duck/debug/ -lduck
else:unix: LIBS += -L$$OUT_PWD/../libs/duck/ -lduck

INCLUDEPATH += $$PWD/../libs/duck
DEPENDPATH += $$PWD/../libs/duck

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/duck/release/libduck.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/duck/debug/libduck.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/duck/release/duck.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/duck/debug/duck.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libs/duck/libduck.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/behavior/release/ -lbehavior
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/behavior/debug/ -lbehavior
else:unix: LIBS += -L$$OUT_PWD/../libs/behavior/ -lbehavior

INCLUDEPATH += $$PWD/../libs/behavior
DEPENDPATH += $$PWD/../libs/behavior

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/behavior/release/libbehavior.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/behavior/debug/libbehavior.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/behavior/release/behavior.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/behavior/debug/behavior.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libs/behavior/libbehavior.a
