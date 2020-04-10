#include "CppUTest/TestHarness.h"
#include "strvec.h"

#include <string>
#include <vector>

using namespace std;

TEST_GROUP(test_strvec)
{
};

TEST(test_strvec, def_constr)
{
    StrVec strvec;
    UNSIGNED_LONGS_EQUAL(0, strvec.size());
    UNSIGNED_LONGS_EQUAL(0, strvec.capacity());
    CHECK(strvec.begin() == nullptr);
    CHECK(strvec.end() == nullptr);
}

TEST(test_strvec, init_list_constr)
{
    StrVec strvec({"one", "two", "three"});
    UNSIGNED_LONGS_EQUAL(3, strvec.size());
    UNSIGNED_LONGS_EQUAL(3, strvec.capacity());
    CHECK_EQUAL(string("one"), *(strvec.begin()));
    CHECK_EQUAL(string("two"), *(strvec.begin() + 1));
    CHECK_EQUAL(string("three"), *(strvec.begin() + 2));
}

TEST(test_strvec, copy_constr)
{
    StrVec strvec({"one", "two", "three"});
    StrVec strvec_copy(strvec);
    UNSIGNED_LONGS_EQUAL(strvec.size(), strvec_copy.size());
    UNSIGNED_LONGS_EQUAL(strvec.capacity(), strvec_copy.capacity());
    CHECK_EQUAL(*(strvec_copy.begin()), *(strvec.begin()));
    CHECK_EQUAL(*(strvec_copy.begin() + 1), *(strvec.begin() + 1));
    CHECK_EQUAL(*(strvec_copy.begin() + 2), *(strvec.begin() + 2));
}

TEST(test_strvec, assignment)
{
    StrVec strvec({"one", "two", "three"});
    StrVec strvec_copy;
    strvec_copy = strvec;
    UNSIGNED_LONGS_EQUAL(strvec.size(), strvec_copy.size());
    UNSIGNED_LONGS_EQUAL(strvec.capacity(), strvec_copy.capacity());
    CHECK_EQUAL(*(strvec_copy.begin()), *(strvec.begin()));
    CHECK_EQUAL(*(strvec_copy.begin() + 1), *(strvec.begin() + 1));
    CHECK_EQUAL(*(strvec_copy.begin() + 2), *(strvec.begin() + 2));
}

TEST(test_strvec, push_back)
{
    StrVec strvec;
    strvec.push_back("one");
    strvec.push_back("two");
    strvec.push_back("three");
    UNSIGNED_LONGS_EQUAL(3, strvec.size());
    UNSIGNED_LONGS_EQUAL(4, strvec.capacity());
    CHECK_EQUAL(string("one"), *(strvec.begin()));
    CHECK_EQUAL(string("two"), *(strvec.begin() + 1));
    CHECK_EQUAL(string("three"), *(strvec.begin() + 2));

    strvec.push_back("four");
    strvec.push_back("five");
    UNSIGNED_LONGS_EQUAL(5, strvec.size());
    UNSIGNED_LONGS_EQUAL(8, strvec.capacity());
    CHECK_EQUAL(string("one"), *(strvec.begin()));
    CHECK_EQUAL(string("two"), *(strvec.begin() + 1));
    CHECK_EQUAL(string("three"), *(strvec.begin() + 2));
    CHECK_EQUAL(string("four"), *(strvec.begin() + 3));
    CHECK_EQUAL(string("five"), *(strvec.begin() + 4));
}

TEST(test_strvec, resize)
{
    StrVec strvec({"one", "two", "three"});
    vector<string> vec({"one", "two", "three"});

    strvec.resize(6);
    vec.resize(6);
    UNSIGNED_LONGS_EQUAL(vec.size(), strvec.size());
    UNSIGNED_LONGS_EQUAL(vec.capacity(), strvec.capacity());

    strvec.resize(1);
    vec.resize(1);
    UNSIGNED_LONGS_EQUAL(vec.size(), strvec.size());
    UNSIGNED_LONGS_EQUAL(vec.capacity(), strvec.capacity());
}

TEST(test_strvec, reserve)
{
    StrVec strvec({"one", "two", "three"});
    vector<string> vec({"one", "two", "three"});

    strvec.reserve(6);
    vec.reserve(6);
    UNSIGNED_LONGS_EQUAL(vec.size(), strvec.size());
    UNSIGNED_LONGS_EQUAL(vec.capacity(), strvec.capacity());

    strvec.reserve(1);
    vec.reserve(1);
    UNSIGNED_LONGS_EQUAL(vec.size(), strvec.size());
    UNSIGNED_LONGS_EQUAL(vec.capacity(), strvec.capacity());
}

TEST(test_strvec, equal_test)
{
    StrVec sv1({"Hello", "world"});
    StrVec sv2({"Hello", "world"});

    CHECK(sv1 == sv2);

    sv2.push_back("!");

    CHECK(sv1 != sv2);
}

TEST(test_strvec, less)
{
    StrVec sv1{"Hello",};
    StrVec sv2{"Hello", "world"};
    CHECK(sv1 < sv2);

    sv1 = {"absurd"};
    sv2 = {"accord"};
    CHECK(sv1 < sv2);
}

TEST(test_strvec, greater)
{
    StrVec sv1{"Hello", "world"};
    StrVec sv2{"Hello"};
    CHECK(sv1 > sv2);

    sv1 = {"accord"};
    sv2 = {"absurd"};
    CHECK(sv1 > sv2);
}

TEST(test_strvec, less_equal)
{
    StrVec sv1{"Hello",};
    StrVec sv2{"Hello", "world"};
    CHECK(sv1 <= sv2);

    sv1 = {"accord"};
    sv2 = {"accord"};
    CHECK(sv1 <= sv2);
}

TEST(test_strvec, greater_equal)
{
    StrVec sv1{"Hello", "world"};
    StrVec sv2{"Hello"};
    CHECK(sv1 >= sv2);

    sv1 = {"absurd"};
    sv2 = {"absurd"};
    CHECK(sv1 >= sv2);
}

TEST(test_strvec, init_list)
{
    StrVec sv{"Chupa", "Chups"};
    StrVec sv1{"Chupa", "Chups"};
    StrVec sv2{"Beep", "Jeep"};
    CHECK(sv == sv1);

    sv = {"Beep", "Jeep"};
    CHECK(sv == sv2);
}

TEST(test_strvec, indecies)
{
    StrVec sv{"Chupa", "Chups"};
    CHECK(sv[0] == "Chupa");
    CHECK(sv[1] == "Chups");
}
