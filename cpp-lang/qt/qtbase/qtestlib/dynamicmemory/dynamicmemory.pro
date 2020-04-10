TEMPLATE = subdirs

SUBDIRS += src

# prepend ! to turn off the test:
isEmpty(BUILD_TESTS) {
    SUBDIRS += tests
    tests.depends += src
}
