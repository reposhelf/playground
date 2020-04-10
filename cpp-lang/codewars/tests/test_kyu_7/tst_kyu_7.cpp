#include <QString>
#include <QtTest>

#include "kyu_7.h"
#include "testutil.h"


class Test_kyu_7 : public QObject {
    Q_OBJECT

public:
    Test_kyu_7();

private Q_SLOTS:
    void testCapitalize_data();
    void testCapitalize();

    void testGetMiddle_data();
    void testGetMiddle();

    void testArithmeticSequenceElements_data();
    void testArithmeticSequenceElements();

    void testAccum_data();
    void testAccum();

    void testCompose_data();
    void testCompose();

    void testScale_data();
    void testScale();
};

Test_kyu_7::Test_kyu_7() {
}

void Test_kyu_7::testCapitalize_data() {
    QTest::addColumn<QString>("actual");
    QTest::addColumn<QString>("expected");

    QTest::newRow("abcdef, [1,2,5]") << QString::fromUtf8(capitalize("abcdef", {1,2,5}).c_str())
                                     << QString("aBCdeF");
}

void Test_kyu_7::testCapitalize() {
    TestUtil::doTest<QString>();
}

void Test_kyu_7::testGetMiddle_data() {
    QTest::addColumn<QString>("actual");
    QTest::addColumn<QString>("expected");

    QTest::newRow("test") << QString::fromUtf8(getMiddle("test").c_str())
                          << QString("es");
    QTest::newRow("testing") << QString::fromUtf8(getMiddle("testing").c_str())
                             << QString("t");
    QTest::newRow("middle") << QString::fromUtf8(getMiddle("middle").c_str())
                            << QString("dd");
    QTest::newRow("A") << QString::fromUtf8(getMiddle("A").c_str())
                       << QString("A");
}

void Test_kyu_7::testGetMiddle() {
    TestUtil::doTest<QString>();
}

void Test_kyu_7::testArithmeticSequenceElements_data() {
    QTest::addColumn<QString>("actual");
    QTest::addColumn<QString>("expected");

    QTest::newRow("test1") << QString::fromUtf8(arithmeticSequenceElements(1, 2, 5).c_str())
                           << QString("1, 3, 5, 7, 9");
    QTest::newRow("test2") << QString::fromUtf8(arithmeticSequenceElements(1, -3, 10).c_str())
                           << QString("1, -2, -5, -8, -11, -14, -17, -20, -23, -26");
    QTest::newRow("test3") << QString::fromUtf8(arithmeticSequenceElements(100, -10, 10).c_str())
                           << QString("100, 90, 80, 70, 60, 50, 40, 30, 20, 10");
}

void Test_kyu_7::testArithmeticSequenceElements() {
    TestUtil::doTest<QString>();
}

void Test_kyu_7::testAccum_data() {
    QTest::addColumn<QString>("actual");
    QTest::addColumn<QString>("expected");

    QTest::newRow("test1") << QString::fromUtf8(accum("abcd").c_str())
                           << QString("A-Bb-Ccc-Dddd");
    QTest::newRow("test2") << QString::fromUtf8(accum("RqaEzty").c_str())
                           << QString("R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy");
    QTest::newRow("test3") << QString::fromUtf8(accum("cwAt").c_str())
                           << QString("C-Ww-Aaa-Tttt");
    QTest::newRow("test4") << QString::fromUtf8(accum("ZpglnRxqenU").c_str())
                           << QString("Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq"
                                      "-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu");
    QTest::newRow("test5") << QString::fromUtf8(accum("NyffsGeyylB").c_str())
                           << QString("N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy"
                                      "-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb");
}

void Test_kyu_7::testAccum() {
    TestUtil::doTest<QString>();
}

void Test_kyu_7::testCompose_data() {
    QTest::addColumn<QString>("actual");
    QTest::addColumn<QString>("expected");

    QTest::newRow("test1") << QString::fromUtf8(compose("abcd\nefgh\nijkl\nmnop",
                                                        "qrst\nuvwx\nyz12\n3456").c_str())
                           << QString("a3456\nefyz1\nijkuv\nmnopq");
    QTest::newRow("test2") << QString::fromUtf8(compose("byGt\nhTts\nRTFF\nCnnI",
                                                        "jIRl\nViBu\nrWOb\nNkTB").c_str())
                           << QString("bNkTB\nhTrWO\nRTFVi\nCnnIj");
    QTest::newRow("test3") << QString::fromUtf8(compose("HXxA\nTGBf\nIPhg\nuUMD",
                                                        "Hcbj\nqteH\nGbMJ\ngYPW").c_str())
                           << QString("HgYPW\nTGGbM\nIPhqt\nuUMDH");
}

void Test_kyu_7::testCompose() {
    TestUtil::doTest<QString>();
}

void Test_kyu_7::testScale_data() {
    QTest::addColumn<QString>("actual");
    QTest::addColumn<QString>("expected");

    QTest::newRow("test1") << QString::fromUtf8(scale("abcd\nefgh\nijkl\nmnop", 2, 3).c_str())
                           << QString("aabbccdd\naabbccdd\naabbccdd\neeffgghh\neeffgghh\n"
                                      "eeffgghh\niijjkkll\niijjkkll\niijjkkll\nmmnnoopp\n"
                                      "mmnnoopp\nmmnnoopp");
    QTest::newRow("test2") << QString::fromUtf8(scale("", 5, 5).c_str())
                           << QString();
    QTest::newRow("test3") << QString::fromUtf8(scale("Kj\nSH", 1, 2).c_str())
                           << QString("Kj\nKj\nSH\nSH");
}

void Test_kyu_7::testScale() {
    TestUtil::doTest<QString>();
}

QTEST_APPLESS_MAIN(Test_kyu_7)

#include "tst_kyu_7.moc"
