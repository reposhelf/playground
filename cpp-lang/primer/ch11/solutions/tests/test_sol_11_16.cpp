#include "CppUTest/TestHarness.h"
#include "chapter11.h"

using namespace std;

TEST_GROUP(test_sol_11_16)
{
    void setup()
    {
        MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    }

    void teardown()
    {
        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    }
};

TEST(test_sol_11_16, test_01)
{
    map<string, int> temperature = {{"Vinnytsia", -13}};
    LONGS_EQUAL(temperature["Vinnytsia"], -13);

    temperature["Vinnytsia"] = -19;
    LONGS_EQUAL(temperature["Vinnytsia"], -19);
}
