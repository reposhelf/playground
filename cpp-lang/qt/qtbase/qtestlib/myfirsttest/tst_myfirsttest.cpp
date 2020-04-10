#include <QString>
#include <QtTest>

class tst_MyFirstTest : public QObject
{
    Q_OBJECT

public:
    tst_MyFirstTest();

private Q_SLOTS:
    void initTestCase();
    void myFirstTest();
    void mySecondTest();
    void cleanupTestCase();
};

tst_MyFirstTest::tst_MyFirstTest()
{
}

void tst_MyFirstTest::initTestCase()
{
    qDebug("Called before everything else");
}

void tst_MyFirstTest::myFirstTest()
{
    QVERIFY(1 == 1);
}

void tst_MyFirstTest::mySecondTest()
{
    QVERIFY(1 != 2);
}

void tst_MyFirstTest::cleanupTestCase()
{
    qDebug("Called after myFirstTest and mySecondTest");
}

QTEST_APPLESS_MAIN(tst_MyFirstTest)

#include "tst_myfirsttest.moc"
