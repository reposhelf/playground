#include "CppUTest/TestHarness.h"
#include "cwordlist.h"
#include "shared.h"

#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;

TEST_GROUP(test_wordlist)
{
};

TEST(test_wordlist, test)
{
    // preparing to test
    ifstream fin("data");
    if (!fin.is_open())
        error(string("error: cannot open file ") + "\'data\'");

    string line;
    CWordList word_list;
    while (getline(fin, line)) {
        istringstream sin(line);
        string word;
        while (sin >> word) {
            reformat(word);
            word_list.insert(word);
        }
    }

    const char *result_file = "actual";
    word_list.fprint(result_file);

    // actually test
    ifstream expected_file("expected");
    ifstream actual_file("actual");

    while (expected_file && actual_file) {
        string expected_line;
        string actual_line;

        expected_file >> expected_line;
        actual_file >> actual_line;

        CHECK(expected_line == actual_line);
    }

    remove(result_file);
}
