#include "chapter12.h"
#include "textquery.h"

#include <fstream>

using namespace std;

void error(const char *msg)
{
    cout << msg << endl;
    exit(1);
}

int main()
{
//    sol_12_23_1();
//    sol_12_23_2();
//    sol_12_24();
//    sol_12_26();

/*
    ifstream infile("storyDataFile");
    if (!infile.is_open())
        error("Cannot open file.");

    TextQuery tq(infile);

    while (true) {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        cout << tq.query(s) << endl;
    }
*/

    sol_12_28();

    return 0;
}
