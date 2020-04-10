#include <QString>
#include <QtTest>
#include <QDate>

class tst_QDate : public QObject
{
    Q_OBJECT

private slots:
    void isValid();
    void isValid_data();
    void add();
    void add_data();
};

void tst_QDate::isValid()
{
    QFETCH(int, year);
    QFETCH(int, month);
    QFETCH(int, day);

    QDate date(year, month, day);
    QTEST(date.isValid(), "valid");
}

void tst_QDate::isValid_data()
{
    QTest::addColumn<int>("year");
    QTest::addColumn<int>("month");
    QTest::addColumn<int>("day");
    QTest::addColumn<bool>("valid");

    QTest::newRow("Valid, normal") << 1973 << 8 << 16 << true;
    QTest::newRow("Invalid, normal") << 1973 << 9 << 31 << false;
    QTest::newRow("Valid, leap-year") << 1980 << 2 << 29 << true;
    QTest::newRow("Invalid, leap-year") << 1981 << 2 << 29 << false;
}

void tst_QDate::add()
{
    QDate date(1979, 5, 16);

    QFETCH(int, addYears);
    QFETCH(int, addMonths);
    QFETCH(int, addDays);

    QDate next = date.addYears(addYears).addMonths(addMonths).addDays(addDays);

    QTEST(next.year(), "year");
    QTEST(next.month(), "month");
    QTEST(next.day(), "day");
}

void tst_QDate::add_data()
{
    QTest::addColumn<int>("addYears");
    QTest::addColumn<int>("addMonths");
    QTest::addColumn<int>("addDays");
    QTest::addColumn<int>("year");
    QTest::addColumn<int>("month");
    QTest::addColumn<int>("day");

    QTest::newRow("Start date") << 0 << 0 << 0 << 1979 << 5 << 16;
    QTest::newRow("One day") << 0 << 0 << 1 << 1979 << 5 << 17;
    QTest::newRow("Twenty days") << 0 << 0 << 20 << 1979 << 6 << 5;
    QTest::newRow("366 days") << 0 << 0 << 366 << 1980 << 5 << 16;
    QTest::newRow("One month") << 0 << 1 << 0 << 1979 << 6 << 16;
    QTest::newRow("Twelve months") << 0 << 12 << 0 << 1980 << 5 << 16;
    QTest::newRow("28 years") << 28 << 0 << 0 << 2007 << 5 << 16;
}

QTEST_APPLESS_MAIN(tst_QDate)

#include "tst_qdate.moc"