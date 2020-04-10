QT += widgets

SHARED_FOLDER = ../shared

include($$SHARED_FOLDER/shared.pri)

SOURCES += \
    main.cpp \
    xform.cpp

HEADERS += \
    xform.h

RESOURCES += \
    affine.qrc
