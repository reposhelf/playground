#include <QString>
#include <QtTest>

class tst_QString : public QObject
{
    Q_OBJECT

public:
    tst_QString();

private Q_SLOTS:
    void toUpper();
};

tst_QString::tst_QString()
{
}

void tst_QString::toUpper()
{
    QString str = "Hello";
    QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_APPLESS_MAIN(tst_QString)

#include "tst_qstring.moc"
