QT += widgets

SHARED_FOLDER = ../shared
include($$SHARED_FOLDER/shared.pri)

SOURCES += \
    main.cpp \
    pathstrokerenderer.cpp \
    pathstrokecontrols.cpp \
    pathstrokewidget.cpp

HEADERS += \
    pathstrokerenderer.h \
    pathstrokecontrols.h \
    pathstrokewidget.h

RESOURCES += \
    pathstroke.qrc
