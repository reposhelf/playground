#include "cstring.h"

#include <QtTest>

class tst_CString : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void toUpper_data();
    void toUpper();
};

void tst_CString::toUpper_data()
{
    QTest::addColumn<QString>("actual");
    QTest::addColumn<QString>("expected");

    QTest::newRow("All lower") << "hello" << "HELLO";
    QTest::newRow("Mixed") << "Hello" << "HELLO";
    QTest::newRow("All upper") << "HELLO" << "HELLO";
}

void tst_CString::toUpper()
{
    QFETCH(QString, actual);
    QFETCH(QString, expected);

    CString c_str;
    QCOMPARE(c_str.up(actual), expected);
}

QTEST_MAIN(tst_CString)

#include "tst_cstring.moc"
