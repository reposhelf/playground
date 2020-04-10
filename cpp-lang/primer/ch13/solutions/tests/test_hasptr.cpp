#include "CppUTest/TestHarness.h"
#include "hasptr.h"

#include <vector>
#include <algorithm>

using namespace std;

TEST_GROUP(test_hasptr)
{
};

TEST(test_hasptr, test_swap)
{
    HasPtr hp1("Foo");
    HasPtr hp2("Bar");
    swap(hp1, hp2);
    CHECK(hp2.data() == "Foo");
    CHECK(hp1.data() == "Bar");
}

TEST(test_hasptr, test_assign)
{
    HasPtr hp1("Foo");
    HasPtr hp2("Bar");
    hp1 = hp2;
    CHECK(hp1.data() == hp2.data());
}

TEST(test_hasptr, test_vec)
{
    vector<HasPtr> vec;
    vec.push_back(HasPtr("Foo"));
    vec.push_back(HasPtr("Bar"));
    vec.push_back(HasPtr("Ptr"));
    vec.push_back(HasPtr("Has"));

    vector<string> unsorted({"Foo", "Bar", "Ptr", "Has"});
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i)
        CHECK(vec[i].data() == unsorted[i]);

    vector<string> sorted({"Bar", "Foo", "Has", "Ptr"});
    sort(vec.begin(), vec.end());
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i)
        CHECK(vec[i].data() == sorted[i]);
}