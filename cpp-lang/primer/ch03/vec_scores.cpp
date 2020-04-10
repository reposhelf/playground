#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    // count of the number from the standard input
    // 0--9, 10--19, ..., 90--99, 100
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++scores[grade / 10];
    }
    for (auto i : scores)
        cout << i << " ";
    cout << endl;
    return 0;
}