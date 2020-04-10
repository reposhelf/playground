QT += core widgets

SOURCES += \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../corelib/release/ -lcorelib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../corelib/debug/ -lcorelib
else:unix: LIBS += -L$$OUT_PWD/../corelib/ -lcorelib

INCLUDEPATH += $$PWD/../corelib
DEPENDPATH += $$PWD/../corelib
