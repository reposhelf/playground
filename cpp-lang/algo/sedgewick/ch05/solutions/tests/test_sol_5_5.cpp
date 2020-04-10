#include "CppUTest/TestHarness.h"
#include "chapter05.h"

TEST_GROUP(tes_sol_5_5)
{
};

TEST(tes_sol_5_5, test_3_7)
{
    LONGS_EQUAL(1, gcd(7, 3));
    LONGS_EQUAL(1, gcd(3, 7));
}

TEST(tes_sol_5_5, test_48_46)
{
    LONGS_EQUAL(2, gcd(48, 46));
    LONGS_EQUAL(2, gcd(46, 48));
}

TEST(tes_sol_5_5, test_148_44)
{
    LONGS_EQUAL(4, gcd(148, 44));
    LONGS_EQUAL(4, gcd(44, 148));
}

TEST(tes_sol_5_5, test_105_70)
{
    LONGS_EQUAL(35, gcd(105, 70));
    LONGS_EQUAL(35, gcd(70, 105));
}

TEST(tes_sol_5_5, test_13_13)
{
    LONGS_EQUAL(13, gcd(13, 13));
}

TEST(tes_sol_5_5, test_37_600)
{
    LONGS_EQUAL(1, gcd(37, 600));
    LONGS_EQUAL(1, gcd(600, 37));
}

TEST(tes_sol_5_5, test_20_100)
{
    LONGS_EQUAL(20, gcd(20, 100));
    LONGS_EQUAL(20, gcd(100, 20));
}

TEST(tes_sol_5_5, test_624129_2061517)
{
    LONGS_EQUAL(18913, gcd(624129, 2061517));
    LONGS_EQUAL(18913, gcd(2061517, 624129));
}