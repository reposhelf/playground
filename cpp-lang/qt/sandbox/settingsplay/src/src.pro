TEMPLATE = subdirs

SUBDIRS += \
    app \
    corelib \
    libs

app.depends += corelib
corelib.depends += libs
