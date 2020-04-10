#ifndef TESTUTIL_H
#define TESTUTIL_H

namespace TestUtil {
template<typename T>
static inline void doTest() {
    QFETCH(T, actual);
    QFETCH(T, expected);
    QCOMPARE(actual, expected);
}
} // namespace TestUtil

#endif
