#include "CppUTest/TestHarness.h"
#include "chapter12.h"

#include <memory>

using namespace std;

TEST_GROUP(test_sol_12_15)
{
};

TEST(test_sol_12_15, test)
{
    destination dest;
    connection c = connect(&dest);

    CHECK(c.dest != 0);

    {
        shared_ptr<connection> connection_guard(&c, [](connection *c){disconnect(c);});
    }

    CHECK(c.dest == 0);
}
