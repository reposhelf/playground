#include "clabel.h"

#include <QString>
#include <QtTest>

class tst_CLabel : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void setText_data();
    void setText();
};

void tst_CLabel::setText_data()
{
    QTest::addColumn<QString>("actual");
    QTest::addColumn<QString>("expected");

    QTest::newRow("without any text") << "" << "";
    QTest::newRow("the hello lower text") << "hello" << "hello";
    QTest::newRow("the hello upper text") << "HELLO" << "HELLO";
    QTest::newRow("the hello mixed test") << "Hello" << "Hello";
}

void tst_CLabel::setText()
{
    QFETCH(QString, actual);
    QFETCH(QString, expected);

    CLabel label(actual);
    QCOMPARE(label.getText(), expected);
}

QTEST_MAIN(tst_CLabel)

#include "tst_clabel.moc"
