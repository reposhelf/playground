#include "CppUTest/TestHarness.h"
#include "chapter11.h"

using namespace std;

TEST_GROUP(test_sol_11_12)
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

TEST(test_sol_11_12, test_01)
{
    vector<pair<string, int>> pairs;
    read_pairs("data/sol_11_12_data", pairs);

    CHECK(pairs[0].first == "Kyiv");
    LONGS_EQUAL(pairs[0].second, 3);
    CHECK(pairs[1].first == "Tokio");
    LONGS_EQUAL(pairs[1].second, 7);
    CHECK(pairs[2].first == "Moskow");
    LONGS_EQUAL(pairs[2].second, -11);
    CHECK(pairs[3].first == "Oulu");
    LONGS_EQUAL(pairs[3].second, -21);
    CHECK(pairs[4].first == "Minsk");
    LONGS_EQUAL(pairs[4].second, 5);
}
