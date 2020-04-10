#-------------------------------------------------
#
# Project created by QtCreator 2013-12-04T18:28:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtCamera
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui

INCLUDEPATH += ..\include
LIBS += -L..\libs \
    libopencv_core231d \
    libopencv_highgui231d \
    libopencv_imgproc231d \

RESOURCES += \
    images.qrc


DESTDIR = ../bin
