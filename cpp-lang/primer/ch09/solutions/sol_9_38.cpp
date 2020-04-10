#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

template<class T> void print(const T &vector) {
    cout << "size: " << vector.size() << endl;
    cout << "capacity: " << vector.capacity() << endl;
}

int main() {
    vector<int> ivec;
    print(ivec);

    for (decltype(ivec.size()) i = 0; i != 10; ++i) {
	print(ivec);
	ivec.push_back(0);
    }
    return 0;
}
