QT += widgets

SHARED_FOLDER = ../shared
include($$SHARED_FOLDER/shared.pri)

qtHaveModule(opengl) {
    DEFINES += QT_OPENGL_SUPPORT
    QT += opengl
}

SOURCES += \
    main.cpp \
    shadewidget.cpp \
    gradienteditor.cpp \
    gradientrenderer.cpp \
    gradientwidget.cpp

HEADERS += \
    shadewidget.h \
    gradienteditor.h \
    gradientrenderer.h \
    gradientwidget.h

RESOURCES += \
    gradients.qrc
