#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*
 * Exercise 4.10:
 * Write the condition for a while loop that would read ints
 * from the standard input and stop when the value read is equal to 42.
 */
void solve_4_10() {
    int number;
    while (cin >> number && number != 42) {}
}

/*
 * Exercise 4.11:
 * Write an expression that tests four values, a, b, c, and d,
 * and ensures that a is greater than b, which is greater than c, which is
 * greater than d.
 */
void solve_4_11() {
    int a;
    int b;
    int c;
    int d;
    cin >> a >> b >> c >> d;

    if (a > b && b > c && c > d)
        cout << "success" << endl;
    else
        cout << "fail" << endl;
}

int main() {
    // solve_4_10();
    solve_4_11();
    return 0;
}