#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

template<class T> void print(const T &vector) {
    cout << "size: " << vector.size() << endl;
    cout << "capacity: " << vector.capacity() << endl;
}

int main() {
    vector<int> ivec;
    print(ivec);

    for (decltype(ivec.size()) i = 0; i != 24; ++i)
	ivec.push_back(i);
    print(ivec);

    while (ivec.size() != ivec.capacity())
	ivec.push_back(0);
    print(ivec);

    ivec.push_back(30);
    print(ivec);

    return 0;
}
