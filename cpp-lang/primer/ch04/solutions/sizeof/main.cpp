#include <iostream>
using std::cout;
using std::endl;

/*
 * Exercise 4.28: Write a program to print the size of each of the built-in
 * types.
 */
void solve_4_28()
{
    cout << "size of: bool = " << sizeof(bool) << endl;
    cout << "size of: char = " << sizeof(char) << endl;
    cout << "size of: short = " << sizeof(short) << endl;
    cout << "size of: unsigned short = " << sizeof(unsigned short) << endl;
    cout << "size of: int = " << sizeof(int) << endl;
    cout << "size of: unsigned int = " << sizeof(unsigned int) << endl;
    cout << "size of: long = " << sizeof(long) << endl;
    cout << "size of: unsigned long = " << sizeof(unsigned long) << endl;
    cout << "size of: float = " << sizeof(float) << endl;
    cout << "size of: double = " << sizeof(double) << endl;
}

int main()
{
    solve_4_28();
    return 0;
}