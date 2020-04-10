#include <iostream>
using namespace std;

int main()
{
    int curVal = 0, newVal = 0;
    if (cin >> curVal) {
        int cnt = 1;
        while (cin >> newVal) {
            if (curVal == newVal) {
                ++cnt;
            } else {
                cout << curVal << " occurs "
                     << cnt << " times" << endl;
                curVal = newVal;
                cnt = 1;
            }
        }
        cout << curVal << " occurs "
             << cnt << " times" << endl;
    }
    return 0;
}