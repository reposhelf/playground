QT += widgets

SHARED_FOLDER = ../shared
include($$SHARED_FOLDER/shared.pri)

qtHaveModule(opengl) {
    DEFINES += QT_OPENGL_SUPPORT
    QT += opengl
}

SOURCES += \
    main.cpp \
    pathdeform.cpp

HEADERS += \
    pathdeform.h

RESOURCES += \
    deform.qrc
