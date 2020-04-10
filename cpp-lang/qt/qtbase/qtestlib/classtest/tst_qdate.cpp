#include <QString>
#include <QtTest>
#include <QDate>

class tst_QDate : public QObject
{
    Q_OBJECT

private slots:
    void addDays();
    void addMonths();
    void addYears();
    void isValid();
};

void tst_QDate::addDays()
{
    QDate date(1986, 1, 3);
    QCOMPARE(date.year(), 1986);
    QCOMPARE(date.month(), 1);
    QCOMPARE(date.day(), 3);

    QDate next = date.addDays(1);
    QCOMPARE(next.year(), 1986);
    QCOMPARE(next.month(), 1);
    QCOMPARE(next.day(), 4);

    next = date.addDays(-2);
    QCOMPARE(next.year(), 1986);
    QCOMPARE(next.month(), 1);
    QCOMPARE(next.day(), 1);

    next = date.addDays(-3);
    QCOMPARE(next.year(), 1985);
    QCOMPARE(next.month(), 12);
    QCOMPARE(next.day(), 31);

    next = date.addDays(30);
    QCOMPARE(next.year(), 1986);
    QCOMPARE(next.month(), 2);
    QCOMPARE(next.day(), 2);

    next = date.addDays(366);
    QCOMPARE(next.year(), 1987);
    QCOMPARE(next.month(), 1);
    QCOMPARE(next.day(), 3);
}

void tst_QDate::addMonths()
{
    QDate date(1973, 8, 16);
    QCOMPARE(date.year(), 1973);
    QCOMPARE(date.month(), 8);
    QCOMPARE(date.day(), 16);

    QDate next = date.addMonths(1);
    QCOMPARE(next.year(), 1973);
    QCOMPARE(next.month(), 9);
    QCOMPARE(next.day(), 16);

    next = date.addMonths(12);
    QCOMPARE(next.year(), 1974);
    QCOMPARE(next.month(), 8);
    QCOMPARE(next.day(), 16);
}

void tst_QDate::addYears()
{
    QDate date(1991, 8, 24);
    QCOMPARE(date.year(), 1991);
    QCOMPARE(date.month(), 8);
    QCOMPARE(date.day(), 24);

    QDate next = date.addYears(1);
    QCOMPARE(next.year(), 1992);
    QCOMPARE(next.month(), 8);
    QCOMPARE(next.day(), 24);

    next = date.addYears(5);
    QCOMPARE(next.year(), 1996);
    QCOMPARE(next.month(), 8);
    QCOMPARE(next.day(), 24);

    next = QDate(1996, 2, 29);
    QVERIFY(next.isValid());
    next = next.addYears(1);
    QCOMPARE(next.year(), 1997);
    QCOMPARE(next.month(), 2);
    QCOMPARE(next.day(), 29);
}

void tst_QDate::isValid()
{
    QDate date;
    QVERIFY(!date.isValid());

    date = QDate(1979, 5, 16);
    QVERIFY(date.isValid());

    date = QDate(1980, 2, 29);
    QVERIFY(date.isValid());

    date = QDate(1979, 2, 29);
    QVERIFY(date.isValid());
}

QTEST_APPLESS_MAIN(tst_QDate)

#include "tst_qdate.moc"
