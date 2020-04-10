#include "CppUTest/TestHarness.h"
#include "chapter11.h"

using namespace std;

TEST_GROUP(test_sol_11_9)
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

TEST(test_sol_11_9, test_01)
{
    map<string, list<int>> words_occurrence;
    read_words_occurrence("data/sol_11_9_data", words_occurrence);

    list<int> example_lines = {1};
    list<int> solution_lines = {1, 3};
    list<int> dought_lines = {1};
    list<int> laught_lines = {1, 2};
    list<int> worth_lines = {2, 3};
    list<int> simple_lines = {2};
    list<int> honey_lines = {2};
    list<int> transe_lines = {3};
    list<int> way_lines = {3};

    CHECK(words_occurrence["example"] == example_lines);
    CHECK(words_occurrence["solution"] == solution_lines);
    CHECK(words_occurrence["dought"] == dought_lines);
    CHECK(words_occurrence["laught"] == laught_lines);
    CHECK(words_occurrence["worth"] == worth_lines);
    CHECK(words_occurrence["simple"] == simple_lines);
    CHECK(words_occurrence["honey"] == honey_lines);
    CHECK(words_occurrence["transe"] == transe_lines);
    CHECK(words_occurrence["way"] == way_lines);
}
