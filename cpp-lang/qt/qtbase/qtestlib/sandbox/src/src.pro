TEMPLATE = subdirs

SUBDIRS += app \
    libs \
    plugins

app.depends += libs plugins
