#include "CppUTest/TestHarness.h"
#include "chapter12.h"

using namespace std;

void end_connection(connection *c)
{
    disconnect(c);
}

TEST_GROUP(test_sol_12_14)
{
};

TEST(test_sol_12_14, test)
{
    destination dest = {"192.168.0.1"};
    connection c = connect(&dest);

    CHECK(c.dest != 0);

    {
        shared_ptr<connection> connection_guard(&c, end_connection);
    }

    CHECK(c.dest == 0);
}
