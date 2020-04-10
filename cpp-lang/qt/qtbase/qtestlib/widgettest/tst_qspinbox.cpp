#include <QtTest>
#include <QtWidgets>

class tst_QSpinBox : public QObject
{
    Q_OBJECT

private slots:
    void testKeys();
    void testClicks();
    void testSetting();
};

void tst_QSpinBox::testKeys()
{
    QSpinBox spinBox;
    spinBox.setRange(1, 10);
    spinBox.setValue(5);

    QTest::keyClick(&spinBox, Qt::Key_Up);
    QCOMPARE(spinBox.value(), 6);

    QTest::keyClick(&spinBox, Qt::Key_Down);
    QCOMPARE(spinBox.value(), 5);

    spinBox.setValue(10);
    QTest::keyClick(&spinBox, Qt::Key_Up);
    QCOMPARE(spinBox.value(), 10);

    spinBox.setValue(1);
    QTest::keyClick(&spinBox, Qt::Key_Down);
    QCOMPARE(spinBox.value(), 1);
}

void tst_QSpinBox::testClicks()
{
    QSpinBox spinBox;
    spinBox.setRange(1, 10);
    spinBox.setValue(5);

    QSize size = spinBox.size();
    QPoint upButton = QPoint(size.width() - 2, 2);
    QPoint downButton = QPoint(size.width() - 2, size.height() - 2);

    QTest::mouseClick(&spinBox, Qt::LeftButton, 0, upButton);
    QCOMPARE(spinBox.value(), 6);

    QTest::mouseClick(&spinBox, Qt::LeftButton, 0, downButton);
    QCOMPARE(spinBox.value(), 5);

    spinBox.setValue(10);
    QTest::mouseClick(&spinBox, Qt::LeftButton, 0, upButton);
    QCOMPARE(spinBox.value(), 10);

    spinBox.setValue(1);
    QTest::mouseClick(&spinBox, Qt::LeftButton, 0, downButton);
    QCOMPARE(spinBox.value(), 1);
}

void tst_QSpinBox::testSetting()
{
    QSpinBox spinBox;
    spinBox.setRange(1, 10);

    spinBox.setValue(5);
    QCOMPARE(spinBox.value(), 5);

    spinBox.setValue(0);
    QCOMPARE(spinBox.value(), 1);

    spinBox.setValue(11);
    QCOMPARE(spinBox.value(), 10);
}

QTEST_MAIN(tst_QSpinBox)

#include "tst_qspinbox.moc"
