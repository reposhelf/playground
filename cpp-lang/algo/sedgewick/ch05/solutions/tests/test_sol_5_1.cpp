#include "CppUTest/TestHarness.h"
#include "chapter05.h"

TEST_GROUP(tes_sol_5_1)
{
};

TEST(tes_sol_5_1, test_01)
{
    DOUBLES_EQUAL(0, log10factorial(1), 0);
    DOUBLES_EQUAL(0.30103, log10factorial(2), 0.00001);
    DOUBLES_EQUAL(0.77815, log10factorial(3), 0.00001);
    DOUBLES_EQUAL(1.38021, log10factorial(4), 0.00001);
    DOUBLES_EQUAL(2.07918, log10factorial(5), 0.00001);
    DOUBLES_EQUAL(2.85733, log10factorial(6), 0.00001);
}
