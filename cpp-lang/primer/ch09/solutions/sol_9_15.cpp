#include <vector>
using std::vector;

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
    vector<int> v2 = { 1, 3, 9 };
    vector<int> v3 = { 1, 3, 5, 7 };
    vector<int> v4 = { 1, 3, 5, 7, 9, 12 };

    cout << iveccmp(v1, v2) << endl;
    cout << iveccmp(v1, v3) << endl;
    cout << iveccmp(v1, v4) << endl;

    return 0;
}
