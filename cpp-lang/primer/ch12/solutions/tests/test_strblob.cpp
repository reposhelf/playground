#include "CppUTest/TestHarness.h"
#include "strblob.h"

using namespace std;

TEST_GROUP(test_strblob)
{
};

TEST(test_strblob, test_size)
{
    StrBlob b1;
    {
        StrBlob b2({"a", "an", "the"});
        b1 = b2;
     }

    LONGS_EQUAL(b1.size(), 3);
}

TEST(test_strblob, test_push_back)
{
    StrBlob b1;
    {
        StrBlob b2({"a", "an", "the"});
        b1 = b2;
        b2.push_back("about");
    }

    LONGS_EQUAL(b1.size(), 4);
}

TEST(test_strblob, test_pop_back)
{
    StrBlob b1;
    {
        StrBlob b2({"a", "an", "the"});
        b1 = b2;
        b2.pop_back();
    }

    LONGS_EQUAL(b1.size(), 2);
}

TEST(test_strblob, test_front)
{
    StrBlob b1;
    {
        StrBlob b2({"a", "an", "the"});
        b1 = b2;
    }

    CHECK(b1.front() == "a");
}

TEST(test_strblob, test_const_front)
{
    const StrBlob b1({"a", "an", "the"});
    
    CHECK(b1.front() == "a");
}

TEST(test_strblob, test_back)
{
    StrBlob b1;
    {
        StrBlob b2({"a", "an", "the"});
        b1 = b2;
    }
    
    CHECK(b1.back() == "the");
}   

TEST(test_strblob, test_const_back)
{
    const StrBlob b1({"a", "an", "the"});

    CHECK(b1.back() == "the");
}
