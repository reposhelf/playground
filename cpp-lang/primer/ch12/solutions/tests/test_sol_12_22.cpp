#include "CppUTest/TestHarness.h"
#include "strblob.h"
#include "conststrblobptr.h"

#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

TEST_GROUP(test_sol_12_22)
{
};

TEST(test_sol_12_22, test)
{
    StrBlob str_blob;
    ifstream in("data/sol_12_22");
    CHECK_TEXT(in.is_open(), "cannot open 'data/sol_12_22'");

    string word;
    while (in >> word)
        str_blob.push_back(word);
    in.close();

    const StrBlob cstr_blob(str_blob);
    ofstream out("data/res_12_22");
    ConstStrBlobPtr c_it = cstr_blob.begin();
    for (; c_it != cstr_blob.end(); c_it.incr())
        out << c_it.deref() << ' ';
    out.close();

    // test
    in.open("data/sol_12_22");
    CHECK_TEXT(in.is_open(), "cannot open 'data/sol_12_22'");
    
    istream_iterator<string> sol_it(in), end;
    vector<string> sol_vec(sol_it, end);
    in.close();

    in.open("data/res_12_22");
    CHECK_TEXT(in.is_open(), "cannot open 'data/res_12_22'");

    istream_iterator<string> res_it(in);
    vector<string> res_vec(res_it, end);
    in.close();

    CHECK(sol_vec == res_vec);
}
