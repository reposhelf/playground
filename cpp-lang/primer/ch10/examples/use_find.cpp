#include <iterator>
using std::begin;
using std::end;

#include <algorithm>
using std::find;

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <list>
using std::list;

int main()
{
    int ia[] = {27, 210, 12, 47, 109, 83};
    int val = 83;
    int *result = find(begin(ia), end(ia), val);
    cout << "The value " << val
	 << (result == end(ia) ? " is not present" : " is present")
	 << endl;

    result = find(ia + 1, ia + 4, val);
    cout << "The value " << val
	 << (result == ia + 4 ? " is not present" : " is present")
	 << endl;

    vector<int> vec = {27, 210, 12, 47, 109, 83};
    int ival = 42;
    auto result2 = find(vec.cbegin(), vec.cend(), ival);
    cout << "The value " << ival
	 << (result2 == vec.cend() ? " is not present" : " is present")
	 << endl;

    list<string> lst = {"val1", "val2", "val3"};
    string sval = "a value";
    auto result3 = find(lst.cbegin(), lst.cend(), sval);
    cout << "The value " << sval
	 << (result3 == lst.cend() ? " is not present" : " is present")
	 << endl;

    return 0;
}
