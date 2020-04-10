#include <iostream>
using namespace std;

int main()
{
    int val = 1024;
    int *p_val = &val;
    int **pp_val = &p_val;

    cout << "The value of val:\n"
         << "direct value = " << val << "\n"
         << "indirect value = " << *p_val << "\n"
         << "doubly indirect value = " << **pp_val << endl;
    return 0;
}