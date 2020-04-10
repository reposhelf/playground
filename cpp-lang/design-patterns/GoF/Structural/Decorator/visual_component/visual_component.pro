TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    visual_component.cpp \
    text_view.cpp \
    decorator.cpp \
    border_decorator.cpp \
    scroll_decorator.cpp

HEADERS += \
    visual_component.h \
    text_view.h \
    decorator.h \
    border_decorator.h \
    scroll_decorator.h
