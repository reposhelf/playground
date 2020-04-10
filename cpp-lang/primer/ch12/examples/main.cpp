#include "textquery.h"
#include "queryresult.h"

#include <iostream>

using namespace std;

void error(const char *msg)
{
    cout << msg << endl;
    exit(1);
}

int main()
{
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

    return 0;
}
