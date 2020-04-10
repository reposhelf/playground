TEMPLATE = subdirs

SUBDIRS += src
isEmpty(BUILD_UTESTS):SUBDIRS += utests

utests.depends = src
