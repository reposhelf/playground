#include "CppUTest/TestHarness.h"
#include "chapter11.h"

using namespace std;

TEST_GROUP(test_sol_11_3_4)
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

TEST(test_sol_11_3_4, test_01)
{
    map<string, size_t> word_count;
    read_word_count("data/sol_11_3_4_data", word_count);

    UNSIGNED_LONGS_EQUAL(word_count["head"], 2);
    UNSIGNED_LONGS_EQUAL(word_count["tail"], 2);
    UNSIGNED_LONGS_EQUAL(word_count["c"], 1);
    UNSIGNED_LONGS_EQUAL(word_count["cxx"], 2);
    UNSIGNED_LONGS_EQUAL(word_count["rust"], 5);
    UNSIGNED_LONGS_EQUAL(word_count["example"], 3);
}
