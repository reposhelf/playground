TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    menuitem.cpp \
    dinermenu.cpp \
    pancakehousemenu.cpp \
    iterator.cpp \
    dinermenuiterator.cpp \
    pancakehouseiterator.cpp \
    waitress.cpp \
    menu.cpp \
    cafemenu.cpp \
    cafemenuiterator.cpp

HEADERS += \
    menuitem.h \
    dinermenu.h \
    pancakehousemenu.h \
    iterator.h \
    dinermenuiterator.h \
    pancakehouseiterator.h \
    waitress.h \
    menu.h \
    cafemenu.h \
    cafemenuiterator.h
