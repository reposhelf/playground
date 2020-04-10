#include "CppUTest/TestHarness.h"
#include "mstring.h"

using namespace std;

TEST_GROUP(test_mstring)
{
};

TEST(test_mstring, def_constr)
{
    String str;
    UNSIGNED_LONGS_EQUAL(0, str.size());
    UNSIGNED_LONGS_EQUAL(0, str.length());
    UNSIGNED_LONGS_EQUAL(0, str.capacity());
    CHECK(str.empty());
    CHECK(str.begin() == nullptr);
    CHECK(str.end() == nullptr);
    CHECK(str.cbegin() == nullptr);
    CHECK(str.cend() == nullptr);
}

TEST(test_mstring, c_str_constr)
{
    String str = "I'm custom string";
    CHECK(str == "I'm custom string");
}

TEST(test_mstring, copy_constr)
{
    String str = "Beep-beep! I'm a jeep!";
    String str2 = str;
    CHECK(str == str2);
}

TEST(test_mstring, assign_op)
{
    String str = "Beep-beep! I'm a jeep!";
    String str2 = "Hello, world!";
    str = str2;
    CHECK(str == str2);
}

TEST(test_mstring, access_elem)
{
    String str = "abc";
    CHECK(str[0] == 'a');
    CHECK(str.at(2) == 'c');

    const String conststr = "xyz";
    CHECK(conststr[1] == 'y');
    CHECK(conststr.at(0) == 'x');
}

TEST(test_mstring, capacity)
{
    String str = "abc";
    UNSIGNED_LONGS_EQUAL(str.capacity(), 3);

    str.push_back('z');
    UNSIGNED_LONGS_EQUAL(str.capacity(), 6);
}

TEST(test_mstring, clear)
{
    String str = "abc";
    UNSIGNED_LONGS_EQUAL(str.capacity(), 3);
    UNSIGNED_LONGS_EQUAL(str.size(), 3);
    UNSIGNED_LONGS_EQUAL(str.length(), 3);
    CHECK(str == "abc");

    str.clear();
    UNSIGNED_LONGS_EQUAL(str.capacity(), 0);
    UNSIGNED_LONGS_EQUAL(str.size(), 0);
    UNSIGNED_LONGS_EQUAL(str.length(), 0);
    CHECK(str == String());

    str = "xyzq";
    UNSIGNED_LONGS_EQUAL(str.capacity(), 4);
    UNSIGNED_LONGS_EQUAL(str.size(), 4);
    UNSIGNED_LONGS_EQUAL(str.length(), 4);
    CHECK(str == "xyzq");
}

TEST(test_mstring, push_back)
{
    String str;
    str.push_back('f');

    UNSIGNED_LONGS_EQUAL(str.size(), 1);
    UNSIGNED_LONGS_EQUAL(str.capacity(), 1);
    CHECK(str[0] == 'f');

    str.push_back('o');
    UNSIGNED_LONGS_EQUAL(str.size(), 2);
    UNSIGNED_LONGS_EQUAL(str.capacity(), 2);
    CHECK(str[0] == 'f');
    CHECK(str[1] == 'o');

    str.push_back('o');
    UNSIGNED_LONGS_EQUAL(str.size(), 3);
    UNSIGNED_LONGS_EQUAL(str.capacity(), 4);
    CHECK(str[0] == 'f');
    CHECK(str[1] == 'o');
    CHECK(str[2] == 'o');
}

TEST(test_mstring, pop_back)
{
    String str("foo");
    UNSIGNED_LONGS_EQUAL(str.size(), 3);
    UNSIGNED_LONGS_EQUAL(str.capacity(), 3);
    CHECK(str[0] == 'f');
    CHECK(str[1] == 'o');
    CHECK(str[2] == 'o');

    str.pop_back();
    UNSIGNED_LONGS_EQUAL(str.size(), 2);
    UNSIGNED_LONGS_EQUAL(str.capacity(), 3);
    CHECK(str[0] == 'f');
    CHECK(str[1] == 'o');

    str.pop_back();
    UNSIGNED_LONGS_EQUAL(str.size(), 1);
    UNSIGNED_LONGS_EQUAL(str.capacity(), 3);
    CHECK(str[0] == 'f');

    str.pop_back();
    UNSIGNED_LONGS_EQUAL(str.size(), 0);
    UNSIGNED_LONGS_EQUAL(str.capacity(), 3);
}

TEST(test_mstring, resize)
{
    String str("bar");
    UNSIGNED_LONGS_EQUAL(str.size(), 3);
    UNSIGNED_LONGS_EQUAL(str.capacity(), 3);
    CHECK(str[0] == 'b');
    CHECK(str[1] == 'a');
    CHECK(str[2] == 'r');

    str.resize(3, 'f');
    UNSIGNED_LONGS_EQUAL(str.size(), 3);
    UNSIGNED_LONGS_EQUAL(str.capacity(), 3);
    CHECK(str[0] == 'b');
    CHECK(str[1] == 'a');
    CHECK(str[2] == 'r');

    str.resize(5, 'f');
    UNSIGNED_LONGS_EQUAL(str.size(), 5);
    UNSIGNED_LONGS_EQUAL(str.capacity(), 6);
    CHECK(str[0] == 'b');
    CHECK(str[1] == 'a');
    CHECK(str[2] == 'r');
    CHECK(str[3] == 'f');
    CHECK(str[4] == 'f');

    str.resize(2, 'f');
    UNSIGNED_LONGS_EQUAL(str.size(), 2);
    UNSIGNED_LONGS_EQUAL(str.capacity(), 6);
    CHECK(str[0] == 'b');
    CHECK(str[1] == 'a');
}
