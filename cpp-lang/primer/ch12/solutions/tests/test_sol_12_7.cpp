#include "CppUTest/TestHarness.h"
#include "chapter12.h"

#include <fstream>
#include <iterator>

using namespace std;

TEST_GROUP(test_sol_12_7)
{
};

TEST(test_sol_12_7, test)
{
    auto vi = createSharedPtrVectorOfInt();
    ifstream in("data/sol_12_7");
    readVectorOfInt(in, vi);
    in.close();
    ofstream out("data/res_12_7");
    printVectorOfInt(out, vi);
    out.close();

    // test
    in.open("data/sol_12_7");
    istream_iterator<string> it_sol(in);
    istream_iterator<string> end;
    vector<string> vec_sol(it_sol, end);
    in.close();
    in.open("data/res_12_7");
    istream_iterator<string> it_res(in);
    vector<string> vec_res(it_res, end);

    CHECK(vec_sol == vec_res);
}
