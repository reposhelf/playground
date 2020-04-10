#include <list>
using std::list;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

template<typename Iterator>
void print(Iterator first, Iterator last) {
    for (; first != last; ++first)
	cout << *first << " ";
    cout << endl;
}

int main() {
    vector<string> svec{"a", "an", "the"};
    list<const char *> clist{"Hello", ",", "world!"};

    print(svec.cbegin(), svec.cend());
    svec.assign(clist.cbegin(), clist.cend());
    print(svec.cbegin(), svec.cend());

    return 0;
}
