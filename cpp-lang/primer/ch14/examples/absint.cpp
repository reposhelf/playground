#include <iostream>

using std::cout;
using std::endl;

struct AbsInt
{
    int operator()(int val) {
        return val < 0 ? -val : val;
    }
};

int main()
{
    int i = -31;
    AbsInt absObj;
    cout << absObj(i) << endl;
}
