QT += widgets

SHARED_FOLDER = ../shared
include($$SHARED_FOLDER/shared.pri)

qtHaveModule(opengl): !contains(QT_CONFIG,dynamicgl) {
    DEFINES += USE_OPENGL
    QT += opengl
}

SOURCES += \
    main.cpp \
    compositionwidget.cpp \
    compositionrenderer.cpp

HEADERS += \
    compositionwidget.h \
    compositionrenderer.h

RESOURCES += \
    composition.qrc
