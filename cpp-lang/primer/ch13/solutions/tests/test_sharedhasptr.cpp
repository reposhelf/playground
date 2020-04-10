#include "CppUTest/TestHarness.h"
#include "sharedhasptr.h"

TEST_GROUP(test_sharedhasptr)
{
};

TEST(test_sharedhasptr, test_1)
{
    SharedHasPtr shp1("foo");
    SharedHasPtr shp2(shp1);

    CHECK(shp1 == shp2);
}

TEST(test_sharedhasptr, test_2)
{
    SharedHasPtr shp1("foo");
    {
        SharedHasPtr shp2(shp1);
    }
    CHECK(shp1.data() == "foo");
}

TEST(test_sharedhasptr, test_3)
{
    SharedHasPtr shp1("foo");
    SharedHasPtr shp2("bar");

    shp1 = shp2;

    CHECK(shp1 == shp2);
}
