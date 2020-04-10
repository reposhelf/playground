#include <algorithm>
using std::equal;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<string> roster1 = { "hello", "so long" };
    list<const char*> roster2 = { "hello", "so long", "tata" };

    auto b = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());

    (b) ? cout << "true" : cout << "false";
    cout << endl;

    return 0;
}
