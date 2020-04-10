#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <vector>
using std::vector;

#include <string>
using std::string;

/*
 * Exercise 4.21:
 * Write a program to use a conditional operator to find the
 * elements in a vector<int> that have odd value and double the value of
 * each such element.
 */
void solve_4_21() {
    vector<int> vec;
    for (int i = 1; i <= 50; ++i)
        vec.push_back(i);

    for (decltype(vec.size()) i = 0; i < vec.size(); ++i) {
        (vec[i] % 2) != 0 
            ? cout << vec[i] << endl 
            : cout << vec[i] * 2 << endl;
    }
}

/*
 * Exercise 4.22:
 * Extend the program that assigned high pass, pass, and fail
 * grades to also assign low pass for grades between 60 and 75 inclusive. Write
 * two versions: One version that uses only conditional operators; the other
 * should use one or more if statements. Which version do you think is easier
 * to understand and why?
 */
void solve_4_22_v1() {
    int grade = 0;
    cin >> grade;
    if (cin) {
        string finalgrade;
        finalgrade = (grade > 90) ? "high pass"
                                  : (grade >= 60) ? (grade <= 75) ? "minimal pass" 
                                                                 : "pass" : "fail";
        cout << finalgrade << endl;
    }
}

void solve_4_22_v2() {
    int grade = 0;
    cin >> grade;
    if (cin) {
        string finalgrade;
        if (grade < 60) {
            finalgrade = "fail";
        } else if (grade >= 60 && grade <= 75) {
            finalgrade = "minimal pass";
        } else if (grade > 75 && grade < 90) {
            finalgrade = "pass";
        } else {
            finalgrade = "high pass";
        }
        cout << finalgrade << endl;
    }
}

/*
 * Exercise 4.23: The following expression fails to compile due to operator
 * precedence. Using Table 4.12 (p. 166), explain why it fails. How would you
 * fix it?
 */
void solve_4_23() {
    string s = "word";
    string p = s + ((s[s.size() - 1] == 's') ? "" : "s");
    cout << p << endl;
}

int main() {
    // solve_4_21();
    // solve_4_22_v1();
    // solve_4_22_v2();
    solve_4_23();
    return 0;
}