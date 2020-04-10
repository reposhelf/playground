#include "CppUTest/TestHarness.h"
#include "chapter05.h"

TEST_GROUP(tes_sol_5_16)
{
};

TEST(tes_sol_5_16, test_01)
{
    int values[] = {
        100, 781, 654, 123, 589,
        547, 689, 257, 498, 588,
        698, 753, 398, 879, 985,
        265, 981, 467, 352, 598,
        599, 300, 401, 456, 687};

    LONGS_EQUAL(985, max(values, 0, sizeof(values) / sizeof(int)));
}

TEST(tes_sol_5_16, test_02)
{
    int values[] = {
        100, 781, 654, 123, 589,
        547, 689, 257, 498, 588,
        698, 753, 398, 879, 985,
        265, 981, 467, 352, 598,
        599, 300, 401, 456, 999};

    LONGS_EQUAL(999, max(values, 0, sizeof(values) / sizeof(int)));
}

TEST(tes_sol_5_16, test_03)
{
    int values[] = {
        999, 781, 654, 123, 589,
        547, 689, 257, 498, 588,
        698, 753, 398, 879, 985,
        265, 981, 467, 352, 598,
        599, 300, 401, 456, 687};

    LONGS_EQUAL(999, max(values, 0, sizeof(values) / sizeof(int)));
}

TEST(tes_sol_5_16, test_04)
{
    int values[] = {1};

    LONGS_EQUAL(1, max(values, 0, sizeof(values) / sizeof(int)));
}

TEST(tes_sol_5_16, test_05)
{
    int values[] = {};

    LONGS_EQUAL(0, max(values, 0, sizeof(values) / sizeof(int)));
}

TEST(tes_sol_5_16, test_06)
{
    int values[] = {99, 99};

    LONGS_EQUAL(99, max(values, 0, sizeof(values) / sizeof(int)));
}
