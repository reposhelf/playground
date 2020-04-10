#include <QtWidgets>
#include <QString>
#include <QtTest>

class tst_QLineEdit : public QObject
{
    Q_OBJECT

public:
    tst_QLineEdit();

private Q_SLOTS:
    void testGui();
};

tst_QLineEdit::tst_QLineEdit()
{
}

void tst_QLineEdit::testGui()
{
    QLineEdit lineEdit;

    QTest::keyClicks(&lineEdit, "hello world");

    QCOMPARE(lineEdit.text(), QString("hello world"));
}

QTEST_MAIN(tst_QLineEdit)

#include "tst_qlineedit.moc"
