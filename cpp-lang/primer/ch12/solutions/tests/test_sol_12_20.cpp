#include "CppUTest/TestHarness.h"
#include "strblob.h"
#include "strblobptr.h"

#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

TEST_GROUP(test_sol_12_20)
{
};

TEST(test_sol_12_20, test)
{
    ifstream in("data/sol_12_20");
    CHECK_TEXT(in.is_open(), "cannot open 'data/sol_12_20'");

    StrBlob str_blob;
    string word;
    while (in >> word)
        str_blob.push_back(word);
    in.close();

    ofstream out("data/res_12_20");
    StrBlobPtr it = str_blob.begin();
    for (; it != str_blob.end(); it.incr()) {
        out << it.deref() << ' ';
    }
    out.close();

    // test
    in.open("data/sol_12_20");
    CHECK_TEXT(in.is_open(), "cannot open 'data/sol_12_20'");
    
    istream_iterator<string> sol_it(in), end;
    vector<string> sol_vec(sol_it, end);
    in.close();

    in.open("data/res_12_20");
    CHECK_TEXT(in.is_open(), "cannot open 'data/res_12_20'");

    istream_iterator<string> res_it(in);
    vector<string> res_vec(res_it, end);
    in.close();

    CHECK(sol_vec == res_vec);
}
