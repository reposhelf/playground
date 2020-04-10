#include <iostream>
using namespace std;

string global_str; // empty string
int global_int; // 0

int main()
{
    int local_int; // undefined
    string local_str; // empty string

    cout << global_str << endl;
    cout << global_int << endl;
    cout << local_str << endl;
    cout << local_int << endl;

    return 0;
}