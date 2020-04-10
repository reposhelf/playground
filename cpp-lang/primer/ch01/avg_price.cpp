#include "Sales_item.h"

#include <iostream>
using namespace std;

int main()
{
    Sales_item total;
    if (cin >> total) {
        Sales_item trans;
        while (cin >> trans) {
            if (total.isbn() == trans.isbn()) {
                total += trans;
            } else {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    } else {
        cerr << "No Data?!" << endl;
        return -1;
    }
    return 0;
}