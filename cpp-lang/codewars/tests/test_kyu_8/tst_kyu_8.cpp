#include <QString>
#include <QtTest>

#include "kyu_8.h"
#include "testutil.h"


class Test_kyu_8 : public QObject {
    Q_OBJECT

public:
    Test_kyu_8();

private Q_SLOTS:
    void testOpposite_data();
    void testOpposite();

    void testOtherAngle_data();
    void testOtherAngle();

    void testSakuraFall_data();
    void testSakuraFall();

    void testCenturyFromYear_data();
    void testCenturyFromYear();

    void testArrayPlusArray_data();
    void testArrayPlusArray();

    void testReverseSeq_data();
    void testReverseSeq();

    void testIsDivideBy_data();
    void testIsDivideBy();
};

Test_kyu_8::Test_kyu_8() {
}

void Test_kyu_8::testOpposite_data() {
    QTest::addColumn<int>("actual");
    QTest::addColumn<int>("expected");

    QTest::newRow("one") << opposite(1) << -1;
    QTest::newRow("zero") << opposite(0) << 0;
    QTest::newRow("minus ten") << opposite(-10) << 10;
}

void Test_kyu_8::testOpposite() {
    TestUtil::doTest<int>();
}

void Test_kyu_8::testOtherAngle_data() {
    QTest::addColumn<int>("actual");
    QTest::addColumn<int>("expected");

    QTest::newRow("res90") << otherAngle(30, 60) << 90;
    QTest::newRow("res60") << otherAngle(60, 60) << 60;
    QTest::newRow("res59") << otherAngle(43, 78) << 59;
    QTest::newRow("res150") << otherAngle(10, 20) << 150;
}

void Test_kyu_8::testOtherAngle() {
    TestUtil::doTest<int>();
}

void Test_kyu_8::testSakuraFall_data() {
    QTest::addColumn<double>("actual");
    QTest::addColumn<double>("expected");

    QTest::newRow("res80") << sakuraFall(5.0) << 80.0;
    QTest::newRow("res0") << sakuraFall(-0.0002) << 0.0;
}

void Test_kyu_8::testSakuraFall() {
    TestUtil::doTest<double>();
}

void Test_kyu_8::testCenturyFromYear_data() {
    QTest::addColumn<int>("actual");
    QTest::addColumn<int>("expected");

    QTest::newRow("1705 = 18") << centuryFromYear(1705) << 18;
    QTest::newRow("1900 = 19") << centuryFromYear(1900) << 19;
    QTest::newRow("1601 = 17") << centuryFromYear(1601) << 17;
    QTest::newRow("2000 = 20") << centuryFromYear(2000) << 20;
}

void Test_kyu_8::testCenturyFromYear() {
    TestUtil::doTest<int>();
}

void Test_kyu_8::testArrayPlusArray_data() {
    QTest::addColumn<int>("actual");
    QTest::addColumn<int>("expected");

    QTest::newRow("1") << arrayPlusArray({1, 2, 3}, {4, 5, 6}) << 21;
    QTest::newRow("2") << arrayPlusArray({1, -2, -3}, {4, -5, 6}) << 1;
    QTest::newRow("3") << arrayPlusArray({-1, -2, -3}, {-4, -5, -6}) << -21;
    QTest::newRow("4") << arrayPlusArray({0, 0, 0}, {4, 5, 6}) << 15;
    QTest::newRow("5") << arrayPlusArray({-1}, {-1}) << -2;
}

void Test_kyu_8::testArrayPlusArray() {
    TestUtil::doTest<int>();
}

void Test_kyu_8::testReverseSeq_data() {
    QTest::addColumn<std::vector<int>>("actual");
    QTest::addColumn<std::vector<int>>("expected");

    std::vector<int> v1 = {1};
    std::vector<int> v2 = {2, 1};
    std::vector<int> v3 = {5, 4, 3, 2, 1};
    std::vector<int> v4 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    QTest::newRow("1") << reverseSeq(1) << v1;
    QTest::newRow("2") << reverseSeq(2) << v2;
    QTest::newRow("3") << reverseSeq(5) << v3;
    QTest::newRow("4") << reverseSeq(10) << v4;
}

void Test_kyu_8::testReverseSeq() {
    TestUtil::doTest<std::vector<int>>();
}

void Test_kyu_8::testIsDivideBy_data() {
    QTest::addColumn<bool>("actual");
    QTest::addColumn<bool>("expected");

    QTest::newRow("1") << isDivideBy(8, 2, 4) << true;
    QTest::newRow("2") << isDivideBy(12, -3, 4) << true;
    QTest::newRow("3") << isDivideBy(8, 3, 4) << false;
    QTest::newRow("4") << isDivideBy(48, 2, -5) << false;
    QTest::newRow("5") << isDivideBy(-100, -25, 10) << true;
    QTest::newRow("6") << isDivideBy(10000, 5, -3) << false;
    QTest::newRow("7") << isDivideBy(4, 4, 2) << true;
    QTest::newRow("8") << isDivideBy(5, 2, 3) << false;
    QTest::newRow("9") << isDivideBy(-96, 25, 17) << false;
    QTest::newRow("0") << isDivideBy(33, 1, 33) << true;
}

void Test_kyu_8::testIsDivideBy() {
    TestUtil::doTest<bool>();
}

QTEST_APPLESS_MAIN(Test_kyu_8)

#include "tst_kyu_8.moc"
