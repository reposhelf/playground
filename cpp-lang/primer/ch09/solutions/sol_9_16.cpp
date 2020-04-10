#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iostream>
using std::cout;
using std::endl;

bool iveccmp(const vector<int> &vec1, const vector<int> &vec2) {
    if (vec1.size() != vec2.size())
	return false;

    const vector<int>::size_type size = vec1.size();
    for (vector<int>::size_type i = 0; i != size; ++i) {
	if (vec1[i] != vec2[i])
	    return false;
    }
    return true;
}

int main() {
    vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
    list<int> l2 = { 1, 3, 9 };
    list<int> l3 = { 1, 3, 5, 7 };
    list<int> l4 = { 1, 3, 5, 7, 9, 12 };

    vector<int> temp;

    temp.assign(l2.cbegin(), l2.cend());
    cout << iveccmp(v1, temp) << endl;

    temp.assign(l3.cbegin(), l3.cend());
    cout << iveccmp(v1, temp) << endl;

    temp.assign(l4.cbegin(), l4.cend());
    cout << iveccmp(v1, temp) << endl;

    return 0;
}
