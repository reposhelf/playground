TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pizzastore.cpp \
    simplepizzafactory.cpp \
    pizza/pizza.cpp \
    pizza/cheesepizza.cpp \
    pizza/veggiepizza.cpp \
    pizza/clampizza.cpp \
    pizza/pepperonipizza.cpp

HEADERS += \
    pizzastore.h \
    simplepizzafactory.h \
    pizza/pizza.h \
    pizza/cheesepizza.h \
    pizza/veggiepizza.h \
    pizza/clampizza.h \
    pizza/pepperonipizza.h

INCLUDEPATH = pizza
