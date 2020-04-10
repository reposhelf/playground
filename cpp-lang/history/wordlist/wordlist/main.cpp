/*
 * The program inputs a text file, scans for words and builds a list
 * of the words in the file and a count of the number of occurences
 * of each word.
 */

#include "cwordlist.h"
#include "shared.h"

#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
        error("  Usage:\n\twordlist <file-name>");

    ifstream fin(argv[1]);
    if (!fin.is_open())
        error(string("error: cannot open file ") + "\'" + string(argv[1]) + "\'");

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

    word_list.print();

    return 0;
}
