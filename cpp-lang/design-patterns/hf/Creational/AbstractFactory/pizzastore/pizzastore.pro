QT += widgets

INCLUDEPATH = factory product

SOURCES += \
    main.cpp \
    pizza.cpp \
    product/dough.cpp \
    product/sauce.cpp \
    product/cheese.cpp \
    product/clam.cpp \
    product/pepperoni.cpp \
    product/veggie.cpp \
    factory/pizzaingredientfactory.cpp \
    pizzastore.cpp

HEADERS += \
    pizza.h \
    factory/pizzaingredientfactory.h \
    product/dough.h \
    product/sauce.h \
    product/cheese.h \
    product/pepperoni.h \
    product/clam.h \
    product/veggie.h \
    pizzastore.h
