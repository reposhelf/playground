#include "dynamicmemory.h"
#include "dynamicmemorypreset.h"

#include <QString>
#include <QtTest>

class tst_DynamicMemory : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void testDynamicMemory_data();
    void testDynamicMemory();

    void testPreset_data();
    void testPreset();

    void modelTest_data();
    void modelTest();

    void editModelOverflowTest_data();
    void editModelOverflowTest();

    void deletePresetTest_data();
    void deletePresetTest();

    void statusFlagTest_data();
    void statusFlagTest();
};

void tst_DynamicMemory::testDynamicMemory_data()
{
    QTest::addColumn<QString>("DefaultName");
    QTest::addColumn<QString>("SetName");
    QTest::addColumn<QString>("ModelName");

    QTest::newRow("DynamicMemory Test")
            << QStringLiteral("DYNAMIC MEMORY")
            << QStringLiteral("DM")
            << QStringLiteral("QStandardItemModel");
}

void tst_DynamicMemory::testDynamicMemory()
{
    QFETCH(QString, DefaultName);
    QFETCH(QString, SetName);
    QFETCH(QString, ModelName);

    // tests default name of the DynamicMemory:
    DynamicMemory dm;
    QCOMPARE(dm.name(), DefaultName);

    // tests DynamicMemory's name after setName():
    dm.setName(QStringLiteral("DM"));
    QCOMPARE(dm.name(), SetName);

    // tests DynamicMemory's model:
    QCOMPARE(QString(dm.model()->metaObject()->className()), ModelName);
}

void tst_DynamicMemory::testPreset_data()
{
    QTest::addColumn<QString>("DefaultName");
    QTest::addColumn<QString>("SetName");
    QTest::addColumn<bool>("IsNull");
    QTest::addColumn<bool>("IsNotNull");

    QTest::newRow("Preset Test")
            << QStringLiteral("None")
            << QStringLiteral("Preset")
            << true
            << false;
}

void tst_DynamicMemory::testPreset()
{
    QFETCH(QString, DefaultName);
    QFETCH(QString, SetName);
    QFETCH(bool, IsNull);
    QFETCH(bool, IsNotNull);

    // tests default name of the Preset:
    DynamicMemoryPreset preset;
    QCOMPARE(preset.name(), DefaultName);

    // tests Preset's name after setName():
    preset.setName(QStringLiteral("Preset"));
    QCOMPARE(preset.name(), SetName);

    // tests whether the default Preset is null:
    DynamicMemoryPreset presetNull;
    QCOMPARE(presetNull.isNull(), IsNull);

    // tests whether the Preset is
    // not null if it has the owher:
    DynamicMemory owner;
    DynamicMemoryPreset presetChild(&owner);
    QCOMPARE(presetChild.isNull(), IsNotNull);
}

void tst_DynamicMemory::modelTest_data()
{
    QTest::addColumn<QString>("DefaultPresetName");
    QTest::addColumn<bool>("DefaultPresetIsNull");
    QTest::addColumn<QString>("CustomPresetName");
    QTest::addColumn<bool>("CustomPresetNotNull");

    QTest::newRow("ModelTest")
            << QStringLiteral("None") << true
            << QStringLiteral("My Preset 1") << false;
}

void tst_DynamicMemory::modelTest()
{
    QFETCH(QString, DefaultPresetName);
    QFETCH(bool, DefaultPresetIsNull);
    QFETCH(QString, CustomPresetName);
    QFETCH(bool, CustomPresetNotNull);

    // tests the DynamicMemory's model at the start:
    DynamicMemory dm;
    QModelIndex index = dm.model()->index(0, 0);
    QVariant data = index.data(Qt::UserRole + 1);
    DynamicMemoryPreset *dmp = data.value<DynamicMemoryPreset *>();
    QCOMPARE(dmp->name(), DefaultPresetName);
    QCOMPARE(dmp->isNull(), DefaultPresetIsNull);

    // tests the DynamicMemory's model after adding first custom preset:
    dm.newPreset(QStringLiteral("My Preset 1"));
    index = dm.model()->index(0, 0);
    data = index.data(Qt::UserRole + 1);
    dmp = data.value<DynamicMemoryPreset *>();
    QCOMPARE(dmp->name(), CustomPresetName);
    QCOMPARE(dmp->isNull(), CustomPresetNotNull);
}

void tst_DynamicMemory::editModelOverflowTest_data()
{
    QTest::addColumn<int>("Count");
    QTest::addColumn<int>("CountToAdd");

    QTest::newRow("Add 1 preset if None") << 1 << 1;
    QTest::newRow("Add 2 presets") << 2 << 2;
    QTest::newRow("Add 3 presets") << 3 << 3;
    QTest::newRow("Add 4 presets") << 4 << 4;
    QTest::newRow("Add 5 presets") << 5 << 5;
    QTest::newRow("Add 6 presets") << 6 << 6;
    QTest::newRow("Add 7 presets") << 6 << 7;
    QTest::newRow("Add 8 presets") << 6 << 8;
}

void tst_DynamicMemory::editModelOverflowTest()
{
    QFETCH(int, Count);
    QFETCH(int, CountToAdd);

    DynamicMemory dm;
    for (int i = 0; i < CountToAdd; ++i)
        dm.newPreset(QString("Presset%0").arg(i));
    QCOMPARE(dm.model()->rowCount(), Count);
}

void tst_DynamicMemory::deletePresetTest_data()
{
    QTest::addColumn<int>("Count");
    QTest::addColumn<int>("CountToRemove");
    QTest::addColumn<QStringList>("PresetNames");

    QStringList names;
    names = QStringList() << QStringLiteral("Preset 1")
                          << QStringLiteral("Preset 2")
                          << QStringLiteral("Preset 3")
                          << QStringLiteral("Preset 4")
                          << QStringLiteral("Preset 5");
    QTest::newRow("Remove 1") << 5 << 1 << names;
    names.clear();

    names = QStringList()<< QStringLiteral("Preset 1")
                         << QStringLiteral("Preset 2")
                         << QStringLiteral("Preset 3")
                         << QStringLiteral("Preset 4");
    QTest::newRow("Remove 2") << 4 << 2 << names;
    names.clear();

    names = QStringList() << QStringLiteral("Preset 1")
                          << QStringLiteral("Preset 2")
                          << QStringLiteral("Preset 3");
    QTest::newRow("Remove 3") << 3 << 3 << names;
    names.clear();

    names = QStringList() << QStringLiteral("Preset 1")
                          << QStringLiteral("Preset 2");
    QTest::newRow("Remove 4") << 2 << 4 << names;
    names.clear();

    names = QStringList() << QStringLiteral("Preset 1");
    QTest::newRow("Remove 5") << 1 << 5 << names;
    names.clear();

    names = QStringList() << QStringLiteral("None");
    QTest::newRow("Remove 6") << 1 << 6 << names;
}

void tst_DynamicMemory::deletePresetTest()
{
    QFETCH(int, Count);
    QFETCH(int, CountToRemove);
    QFETCH(QStringList, PresetNames);

    DynamicMemory dm;
    dm.newPreset(QStringLiteral("Preset 1"));
    dm.newPreset(QStringLiteral("Preset 2"));
    dm.newPreset(QStringLiteral("Preset 3"));
    dm.newPreset(QStringLiteral("Preset 4"));
    dm.newPreset(QStringLiteral("Preset 5"));
    dm.newPreset(QStringLiteral("Preset 6"));

    for (int i = 0; i < CountToRemove; ++i)
        dm.deletePreset(dm.model()->rowCount() - 1);

    QCOMPARE(dm.model()->rowCount(), Count);

    QStringList names;
    for (int i = 0; i < dm.model()->rowCount(); ++i)
    {
        QModelIndex index = dm.model()->index(i, 0);
        QVariant data = index.data(Qt::UserRole + 1);
        names.append(data.value<DynamicMemoryPreset *>()->name());
    }

    QCOMPARE(names, PresetNames);
}

void tst_DynamicMemory::statusFlagTest_data()
{
    QTest::addColumn<int>("DefaultStatus");
    QTest::addColumn<int>("EditableStatus");
    QTest::addColumn<int>("AfterRemoveSingle");
    QTest::addColumn<int>("FullStatus");
    QTest::addColumn<int>("AddAvailable");

    QTest::newRow("FlagsTest") << 0x1 << 0x3 << 0x1 << 0x2 << 0x3;
}

void tst_DynamicMemory::statusFlagTest()
{
    QFETCH(int, DefaultStatus);
    QFETCH(int, EditableStatus);
    QFETCH(int, AfterRemoveSingle);
    QFETCH(int, FullStatus);
    QFETCH(int, AddAvailable);

    DynamicMemory dm;
    QCOMPARE(dm.statusFlags(), DefaultStatus);

    dm.newPreset("Preset1");
    QCOMPARE(dm.statusFlags(), EditableStatus);

    dm.deletePreset(0);
    QCOMPARE(dm.statusFlags(), AfterRemoveSingle);

    dm.newPreset("1");
    dm.newPreset("2");
    dm.newPreset("3");
    dm.newPreset("4");
    dm.newPreset("5");
    dm.newPreset("6");
    QCOMPARE(dm.statusFlags(), FullStatus);

    dm.deletePreset(5);
    QCOMPARE(dm.statusFlags(), AddAvailable);
}

QTEST_APPLESS_MAIN(tst_DynamicMemory)

#include "tst_dynamicmemory.moc"
