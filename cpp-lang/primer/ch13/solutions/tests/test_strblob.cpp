#include "CppUTest/TestHarness.h"
#include "strblob.h"
#include "strblobptr.h"

using namespace std;

TEST_GROUP(test_strblob)
{
};

TEST(test_strblob, test_1)
{
    StrBlob b1;
    StrBlob b2({"a", "an", "the"});
    b1 = b2;

    LONGS_EQUAL(b1.size(), b2.size());
}

TEST(test_strblob, test_2)
{
    StrBlob b1;
    StrBlob b2({"a", "an", "the"});
    b1 = b2;
    b1.push_back("or");

    CHECK(b1.size() != b2.size());
}

TEST(test_strblob, test_3)
{
    StrBlob b1;
    StrBlob b2({"a", "an", "the"});
    b1 = b2;
    b1.push_back("or");

    StrBlobPtr pb1 = b1.begin();
    StrBlobPtr pb2 = b2.begin();
    CHECK(pb1.deref() == "a");
    CHECK(pb2.deref() == "a");

    pb1.incr();
    pb2.incr();
    CHECK(pb1.deref() == "an");
    CHECK(pb2.deref() == "an");

    pb1.incr();
    pb2.incr();
    CHECK(pb1.deref() == "the");
    CHECK(pb2.deref() == "the");

    pb1.incr();
    CHECK(pb1.deref() == "or");
}

// TEST(test_strblob, test_pop_back)
// {
//     StrBlob b1;
//     {
//         StrBlob b2({"a", "an", "the"});
//         b1 = b2;
//         b2.pop_back();
//     }

//     LONGS_EQUAL(b1.size(), 2);
// }

// TEST(test_strblob, test_front)
// {
//     StrBlob b1;
//     {
//         StrBlob b2({"a", "an", "the"});
//         b1 = b2;
//     }

//     CHECK(b1.front() == "a");
// }

// TEST(test_strblob, test_const_front)
// {
//     const StrBlob b1({"a", "an", "the"});
    
//     CHECK(b1.front() == "a");
// }

// TEST(test_strblob, test_back)
// {
//     StrBlob b1;
//     {
//         StrBlob b2({"a", "an", "the"});
//         b1 = b2;
//     }
    
//     CHECK(b1.back() == "the");
// }   

// TEST(test_strblob, test_const_back)
// {
//     const StrBlob b1({"a", "an", "the"});

//     CHECK(b1.back() == "the");
// }
