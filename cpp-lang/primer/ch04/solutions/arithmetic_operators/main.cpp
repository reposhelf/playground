#include <iostream>
using std::cout;
using std::endl;
using std::cin;

/*
 * Exercise 4.4.
 * Parenthesize the following expression to show how it is
 * evaluated. Test your answer by compiling the expression (without
 * parentheses) and printing its result.
 *
 * 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
 */
void solve_4_4() {
    cout << ((((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2)) << endl;
    cout << 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 << endl;
}

/*
 * Exercise 4.5.
 * Determine the result of the following expressions.
 *
 * (a) -30 * 3 + 21 / 5
 * (b) -30 + 3 * 21 / 5
 * (c) 30 / 3 * 21 % 5
 * (d) -30 / 3 * 21 % 4
 */
void solve_4_5() {
    cout << "result: " << -30 * 3 + 21 / 5 << "; guess: " << -86 << endl;
    cout << "result: " << -30 + 3 * 21 / 5 << "; guess: " << -18 << endl;
    cout << "result: " << 30 / 3 * 21 % 5 << "; guess: " << 0 << endl;
    cout << "result: " << -30 / 3 * 21 % 4 << "; guess: " << -2 << endl;
}

/*
 * Exercise 4.6. Write an expression to determine whether an int value is
 * even or odd.
 */
void solve_4_6() {
    int number;
    char contin;
    do {
        cout << "Type a number: ";
        cin >> number;
        if (!cin) {
            cout << "error: unexpected symbol" << endl;
            return;
        }
        if (number % 2 == 0)
            cout << "It's an even number" <<endl;
        else
            cout << "It's an odd number" <<endl;

        cout << "Do you want to continue (type 'y' to continue)? ";
        cin >> contin;
    } while (contin == 'y');
}

/*
 * Exercise 4.7.
 * What does overflow mean? Show three expressions that will
 * overflow.
 */
void solve_4_7() {
    // 1st
    short res1 = 32767 * 2;
    cout << res1 << endl;

    // 2nd
    int res2 = 4294967295 + 1;
    cout << res2 << endl;

    // 3rd
    unsigned res3 = -1;
    cout << res3 << endl;
}

int main() {
    // solve_4_4();
    // solve_4_5();
    // solve_4_6();
    solve_4_7();
    return 0;
}