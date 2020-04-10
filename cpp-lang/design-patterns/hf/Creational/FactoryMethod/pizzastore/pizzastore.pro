TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pizza.cpp \
    pizzastore.cpp \
    nystylecheesepizza.cpp \
    chicagostylecheesepizza.cpp \
    nypizzastore.cpp \
    chicagopizzastore.cpp

HEADERS += \
    pizza.h \
    pizzastore.h \
    nystylecheesepizza.h \
    chicagostylecheesepizza.h \
    nypizzastore.h \
    chicagopizzastore.h
