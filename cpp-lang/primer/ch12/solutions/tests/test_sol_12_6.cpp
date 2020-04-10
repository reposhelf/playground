#include "CppUTest/TestHarness.h"
#include "chapter12.h"

#include <fstream>
#include <iterator>

using namespace std;

TEST_GROUP(test_sol_12_6)
{
};

TEST(test_sol_12_6, test)
{
    vector<int> *vi = createVectorOfInt();
    ifstream in("data/sol_12_6");
    readVectorOfInt(in, vi);
    ofstream out("data/res_12_6");
    printVectorOfInt(out, vi);
    out.close();
    delete vi;

    // Test
    in.close();
    in.open("data/sol_12_6");
    istream_iterator<string> end;
    istream_iterator<string> sol_it(in);
    vector<string> sol_vec(sol_it, end);

    in.close();
    in.open("data/res_12_6");
    istream_iterator<string> res_it(in);
    vector<string> res_vec(res_it, end);

    CHECK(sol_vec == res_vec);
}
