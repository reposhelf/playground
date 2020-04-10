#include "CppUTest/TestHarness.h"
#include "chapter11.h"

using namespace std;

TEST_GROUP(test_sol_11_7)
{
    void setup()
    {
        MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    }

    void teardown()
    {
        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    }
};

TEST(test_sol_11_7, test_01)
{
    map<string, vector<string>> family;

    vector<string> becks_children = {"Alan", "Diana", "Bruce"};
    vector<string> schmidts_children = {"Oliver", "Michael"};
    vector<string> jacksons_children = {"Anna"};
    vector<string> hodjsons_children = {"Barbara", "Sarah"};

    add_family("Becks", vector<string>(), family);
    add_child("Becks", "Alan", family);
    add_child("Becks", "Diana", family);
    add_child("Becks", "Bruce", family);

    add_family("Schmidt", vector<string>(), family);
    add_child("Schmidt", "Oliver", family);
    add_child("Schmidt", "Michael", family);

    add_family("Jackson", vector<string>(), family);
    add_child("Jackson", "Anna", family);

    add_family("Hodjson", hodjsons_children, family);

    CHECK(family["Becks"] == becks_children);
    CHECK(family["Schmidt"] == schmidts_children);
    CHECK(family["Jackson"] == jacksons_children);
    CHECK(family["Hodjson"] == hodjsons_children);
}
