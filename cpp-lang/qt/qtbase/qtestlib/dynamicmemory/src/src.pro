TEMPLATE = subdirs

SUBDIRS += \
    app \
    corelib

app.depends += corelib
