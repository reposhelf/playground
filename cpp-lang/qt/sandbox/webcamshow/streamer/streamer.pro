TEMPLATE = app
TARGET = ../bin/streamer
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += /usr/include/gstreamer-1.0 \
               /usr/include/glib-2.0 \
               /usr/lib/i386-linux-gnu/glib-2.0/include

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += gstreamer-1.0 \
                   gstreamer-app-1.0 \
                   gstreamer-plugins-base-1.0 \
                   gstreamer-video-1.0

SOURCES += main.cpp \
    streamer.cpp \
    abstractgraph.cpp \
    previewgraph.cpp \
    youtubegraph.cpp \
    youtubewithpreviewgraph.cpp \
    videotestgraph.cpp

HEADERS += \
    streamer.h \
    abstractgraph.h \
    previewgraph.h \
    youtubegraph.h \
    youtubewithpreviewgraph.h \
    videotestgraph.h
