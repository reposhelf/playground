QT += widgets

SOURCES += \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../corelib/release/ -lcorelib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../corelib/debug/ -lcorelib
else:unix: LIBS += -L$$OUT_PWD/../corelib/ -lcorelib

INCLUDEPATH += $$PWD/../corelib
DEPENDPATH += $$PWD/../corelib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../corelib/release/libcorelib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../corelib/debug/libcorelib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../corelib/release/corelib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../corelib/debug/corelib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../corelib/libcorelib.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/childwindow/release/ -lchildwindow
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/childwindow/debug/ -lchildwindow
else:unix: LIBS += -L$$OUT_PWD/../libs/childwindow/ -lchildwindow

INCLUDEPATH += $$PWD/../libs/childwindow
DEPENDPATH += $$PWD/../libs/childwindow
