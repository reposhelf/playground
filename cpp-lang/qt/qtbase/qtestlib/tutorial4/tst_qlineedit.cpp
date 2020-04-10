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
    void testGui_data();
};

tst_QLineEdit::tst_QLineEdit()
{
}

void tst_QLineEdit::testGui()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    QLineEdit lineEdit;

    events.simulate(&lineEdit);

    QCOMPARE(lineEdit.text(), expected);
}

void tst_QLineEdit::testGui_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList list1;
    list1.addKeyClick('a');
    QTest::newRow("char") << list1 << "a";

    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::newRow("there and back again") << list2 << "";
}

QTEST_MAIN(tst_QLineEdit)

#include "tst_qlineedit.moc"
