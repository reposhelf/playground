TEMPLATE = subdirs

SUBDIRS += \
    duck \
    behavior

duck.depends += behavior
