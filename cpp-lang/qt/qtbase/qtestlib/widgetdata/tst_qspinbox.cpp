#include <QString>
#include <QtTest>
#include <QtWidgets>

Q_DECLARE_METATYPE(Qt::Key)

class tst_QSpinBox : public QObject
{
    Q_OBJECT

private slots:
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

    QFETCH(Qt::Key, keys);
    QFETCH(int, startValue);

    spinBox.setValue(startValue);
    QTest::keyClick(&spinBox, keys);
    QTEST(spinBox.value(), "endValue");

}

void tst_QSpinBox::testKeys_data()
{
    QTest::addColumn<Qt::Key>("keys");
    QTest::addColumn<int>("startValue");
    QTest::addColumn<int>("endValue");

    QTest::newRow("Up") << Qt::Key_Up << 5 << 6;
    QTest::newRow("Down") << Qt::Key_Down << 5 << 4;
    QTest::newRow("Up, limit") << Qt::Key_Up << 10 << 10;
    QTest::newRow("Down, limit") << Qt::Key_Down << 1 << 1;
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

    if (direction.toLower() == "up")
        QTest::mouseClick(&spinBox, Qt::LeftButton, 0, upButton);
    else if (direction.toLower() == "down")
        QTest::mouseClick(&spinBox, Qt::LeftButton, 0, downButton);
    else
        QWARN("Unknown direction - no clicks issued.");

    QTEST(spinBox.value(), "endValue");
}

void tst_QSpinBox::testClicks_data()
{
    QTest::addColumn<QString>("direction");
    QTest::addColumn<int>("startValue");
    QTest::addColumn<int>("endValue");

    QTest::newRow("Up") << "Up" << 5 << 6;
    QTest::newRow("Down") << "Down" << 5 << 4;
    QTest::newRow("Up, limit") << "Up" << 10 << 10;
    QTest::newRow("Down, limit") << "Down" << 1 << 1;
}

void tst_QSpinBox::testSetting()
{
    QSpinBox spinBox;
    spinBox.setRange(1, 10);

    QFETCH(int, value);

    spinBox.setValue(value);
    QTEST(spinBox.value(), "endValue");
}

void tst_QSpinBox::testSetting_data()
{
    QTest::addColumn<int>("value");
    QTest::addColumn<int>("endValue");

    QTest::newRow("Valid") << 5 << 5;
    QTest::newRow("Over") << 11 << 10;
    QTest::newRow("Under") << 0 << 1;
}

QTEST_MAIN(tst_QSpinBox)

#include "tst_qspinbox.moc"
