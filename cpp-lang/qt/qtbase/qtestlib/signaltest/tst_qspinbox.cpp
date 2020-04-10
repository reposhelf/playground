#include <QString>
#include <QtTest>
#include <QtWidgets>

Q_DECLARE_METATYPE(Qt::Key)

class tst_QSpinBox : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void testKeys();
    void testKeys_data();
    void testClicks();
    void testClicks_data();
    void testSetting();
    void testSetting_data();
};

void tst_QSpinBox::testKeys()
{
    QSpinBox spinBox;
    spinBox.setRange(1, 10);

    QFETCH(Qt::Key, key);
    QFETCH(int, startValue);

    spinBox.setValue(startValue);

    QSignalSpy spy(&spinBox, SIGNAL(valueChanged(int)));

    QTest::keyClick(&spinBox, key);
    QTEST(spinBox.value(), "endValue");

    QFETCH(bool, willSignal);
    if (willSignal) {
        QCOMPARE(spy.count(), 1);
        QTEST(spy.takeFirst()[0].toInt(), "endValue");
    } else {
        QCOMPARE(spy.count(), 0);
    }
}

void tst_QSpinBox::testKeys_data()
{
    QTest::addColumn<Qt::Key>("key");
    QTest::addColumn<int>("startValue");
    QTest::addColumn<int>("endValue");
    QTest::addColumn<bool>("willSignal");

    QTest::newRow("Up") << Qt::Key_Up << 5 << 6 << true;
    QTest::newRow("Down") << Qt::Key_Down << 5 << 4 << true;
    QTest::newRow("Up, limit") << Qt::Key_Up << 10 << 10 << false;
    QTest::newRow("Down, limit") << Qt::Key_Down << 1 << 1 << false;
}

void tst_QSpinBox::testClicks()
{
    QSpinBox spinBox;
    spinBox.setRange(1, 10);

    QSize size = spinBox.size();
    QPoint upButton = QPoint(size.width() - 2, 2);
    QPoint downButton = QPoint(size.width() - 2, size.height() - 2);

    QFETCH(QString, direction);
    QFETCH(int, startValue);

    spinBox.setValue(startValue);

    QSignalSpy spy(&spinBox, SIGNAL(valueChanged(int)));

    if (direction.toLower() == "up")
        QTest::mouseClick(&spinBox, Qt::LeftButton, 0, upButton);
    else if (direction.toLower() == "down")
        QTest::mouseClick(&spinBox, Qt::LeftButton, 0, downButton);
    else
        QWARN("Unknown direction - no clicks issued");

    QTEST(spinBox.value(), "endValue");

    QFETCH(bool, willSignal);
    if (willSignal) {
        QCOMPARE(spy.count(), 1);
        QTEST(spy.takeFirst()[0].toInt(), "endValue");
    } else {
        QCOMPARE(spy.count(), 0);
    }
}

void tst_QSpinBox::testClicks_data()
{
    QTest::addColumn<QString>("direction");
    QTest::addColumn<int>("startValue");
    QTest::addColumn<int>("endValue");
    QTest::addColumn<bool>("willSignal");

    QTest::newRow("Up") << "Up" << 5 << 6 << true;
    QTest::newRow("Down") << "Down" << 5 << 4 << true;
    QTest::newRow("Up, limit") << "Up" << 10 << 10 << false;
    QTest::newRow("Down, limit") << "Down" << 1 << 1 << false;
}

void tst_QSpinBox::testSetting()
{
    QSpinBox spinBox;
    spinBox.setRange(1, 10);

    QFETCH(int, startValue);
    spinBox.setValue(startValue);

    QSignalSpy spy(&spinBox, SIGNAL(valueChanged(int)));

    QFETCH(int, value);
    spinBox.setValue(value);
    QTEST(spinBox.value(), "endValue");

    QFETCH(bool, willSignal);
    if (willSignal) {
        QCOMPARE(spy.count(), 1);
        QTEST(spy.takeFirst()[0].toInt(), "endValue");
    } else {
        QCOMPARE(spy.count(), 0);
    }
}

void tst_QSpinBox::testSetting_data()
{
    QTest::addColumn<int>("startValue");
    QTest::addColumn<int>("value");
    QTest::addColumn<int>("endValue");
    QTest::addColumn<bool>("willSignal");

    QTest::newRow("Valid") << 1 << 5 << 5 << true;
    QTest::newRow("Over") << 9 << 11 << 10 << true;
    QTest::newRow("Under") << 2 << 0 << 1 << true;
    QTest::newRow("Valid, no change") << 5 << 5 << 5 << false;
    QTest::newRow("Over, no change") << 10 << 11 << 10 << false;
    QTest::newRow("Under, no change") << 1 << 0 << 1 << false;
}

QTEST_MAIN(tst_QSpinBox)

#include "tst_qspinbox.moc"
