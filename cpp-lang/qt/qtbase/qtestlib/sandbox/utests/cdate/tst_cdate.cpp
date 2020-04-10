#include "cdate.h"

#include <QString>
#include <QtTest>

class tst_CDate : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void isValid_data();
    void isValid();
};

void tst_CDate::isValid_data()
{
    QTest::addColumn<int>("year");
    QTest::addColumn<int>("month");
    QTest::addColumn<int>("day");
    QTest::addColumn<bool>("result");

    QTest::newRow("Is Valid") << 1980 << 2 << 29 << true;
    QTest::newRow("Is Invalid") << 1979 << 2 << 29 << false;
}

void tst_CDate::isValid()
{
    QFETCH(int, year);
    QFETCH(int, month);
    QFETCH(int, day);
    QFETCH(bool, result);

    CDate date;

    QCOMPARE(date.isValid(QDate(year, month, day)), result);
}

QTEST_MAIN(tst_CDate)

#include "tst_cdate.moc"
