#include "CppUTest/TestHarness.h"
#include "chapter05.h"

TEST_GROUP(test_sol_5_60)
{
};

TEST(test_sol_5_60, test_01)
{
    int numbers[11] = {3, 7, 5, 2, 4, 9, 8, 6, 1, 0, 7};

    LONGS_EQUAL(max_partition(numbers, 0, 10, 2), 9);
}

TEST(test_sol_5_60, test_02)
{
    int numbers[11] = {3, 7, 5, 2, 4, 6, 5, 6, 1, 0, 7};

    LONGS_EQUAL(max_partition(numbers, 0, 10, 3), 7);
}

TEST(test_sol_5_60, test_03)
{
    int numbers[11] = {3, 7, 5, 2, 4, 5, 8, 6, 1, 0, 7};

    LONGS_EQUAL(max_partition(numbers, 0, 10, 4), 8);
}

TEST(test_sol_5_60, test_04)
{
    int numbers[11] = {3, 7, 5, 2, 4, 9, 8, 6, 1, 0, 7};

    LONGS_EQUAL(max_partition(numbers, 0, 10, 5), 9);
}

TEST(test_sol_5_60, test_05)
{
    int numbers[11] = {3, 7, 5, 2, 4, 9, 8, 6, 1, 0, 7};

    LONGS_EQUAL(max_partition(numbers, 0, 10, 6), 9);
}

TEST(test_sol_5_60, test_06)
{
    int numbers[11] = {3, 7, 5, 2, 4, 9, 8, 6, 1, 0, 7};

    LONGS_EQUAL(max_partition(numbers, 0, 10, 7), 9);
}

TEST(test_sol_5_60, test_07)
{
    int numbers[11] = {3, 7, 5, 2, 4, 9, 8, 6, 1, 0, 7};

    LONGS_EQUAL(max_partition(numbers, 0, 10, 8), 9);
}

TEST(test_sol_5_60, test_08)
{
    int numbers[11] = {3, 7, 5, 2, 4, 9, 8, 6, 1, 0, 7};

    LONGS_EQUAL(max_partition(numbers, 0, 10, 9), 9);
}

TEST(test_sol_5_60, test_09)
{
    int numbers[11] = {3, 7, 5, 2, 4, 9, 8, 6, 1, 0, 7};

    LONGS_EQUAL(max_partition(numbers, 0, 10, 10), 9);
}

TEST(test_sol_5_60, test_10)
{
    int numbers[11] = {3, 7, 5, 2, 4, 9, 8, 6, 1, 0, 7};

    LONGS_EQUAL(max_partition(numbers, 0, 10, 11), 9);
}

TEST(test_sol_5_60, test_11)
{
    int numbers[11] = {3, 7, 5, 2, 4, 9, 8, 6, 1, 0, 7};

    LONGS_EQUAL(max_partition(numbers, 0, 10, 12), 9);
}

TEST(test_sol_5_60, test_12)
{
    int numbers[1] = {3};

    LONGS_EQUAL(max_partition(numbers, 0, 0, 3), 3);
}

TEST(test_sol_5_60, test_13)
{
    int numbers[2] = {3, 7};
   
    LONGS_EQUAL(max_partition(numbers, 0, 1, 2), 7);
}
