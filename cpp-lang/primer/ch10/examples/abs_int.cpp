#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <vector>
using std::vector;

#include <algorithm>
using std::for_each;
using std::transform;

int main()
{
    vector<int> vi;
    int val;
    while (cin >> val)
        vi.push_back(val);
    for_each(vi.begin(), vi.end(), [] (int i) { cout << i << " "; });
    cout << endl;

    vector<int> orig = vi;

    transform(vi.begin(), vi.end(), vi.begin(),
            [] (int i) { return i < 0 ? -i : i; });
    for_each(vi.begin(), vi.end(), [] (int i) { cout << i << " "; });
    cout << endl;

    vi = orig;
    for_each(vi.begin(), vi.end(), [] (int i) { cout << i << " "; });
    cout << endl;

    transform(vi.begin(), vi.end(), vi.begin(),
            [] (int i) -> int { if (i < 0) return -i; else return i; });
    for_each(vi.begin(), vi.end(), [] (int i) { cout << i << " "; });
    cout << endl;

    return 0;
}