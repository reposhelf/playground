#include "mstring.h"

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<String> vs;
    vs.push_back("foo");
    vs.push_back("bar");
    vs.push_back("zoom");
    vs.push_back("hack");
    vs.push_back("bitch");

    String str("Hello, world!");
    cout << str << endl;

    return 0;
}
