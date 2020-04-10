#include <algorithm>
using std::replace;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    replace(ivec.begin(), ivec.end(), 0, 42);

    for (const int &i : ivec)
	cout << i << " ";
    cout << endl;

    return 0;
}
