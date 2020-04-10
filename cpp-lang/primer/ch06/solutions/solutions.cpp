#include "solutions.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iterator>

#include <initializer_list>
using std::initializer_list;

#include <vector>
using std::vector;

/*
 * Exercise 6.3: Write and test your own version of fact.
 */
int fact(int val)
{
    if (val == 1) return 1;
    return val * fact(val - 1);
}

/*
 * Exercise 6.4:
 * Write a function that interacts with the user, asking for a
 * number and generating the factorial of that number. Call this function from
 * main.
 */
void fact2()
{
    cout << "Enter a number to compute it factorial value:" << endl;
    int val;
    while (cin >> val) {
        cout << fact(val) << endl;

        cout << "continue (y/n)?: ";
        char c;
        cin >> c;
        if (!cin || c == 'n')
            break;
    }
}

/*
 * Exercise 6.5:
 * Write a function to return the absolute value of its argument.
 */
int abslt(int val)
{
    return val < 0 ? -val : val;
}

/*
 * Exercise 6.7:
 * Write a function that returns 0 when it is first called and then
 * generates numbers in sequence each time it is called again.
 */
int count_calls()
{
    static size_t ctr = 0;
    return ctr++;
}

/*
 * Exercise 6.10:
 * Using pointers, write a function to swap the values of two
 * ints. Test the function by calling it and printing the swapped values.
 */
void reset(int *a, int *b)
{
    *a = 0;
    *b = 0;
}

/*
 * Exercise 6.11:
 * Write and test your own version of reset that takes a
 * reference.
 */
void reset(int &a)
{
    a = 0;
}

/*
 * Exercise 6.12:
 * Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210)
 * to use references instead of pointers to swap the value of two ints. Which
 * version do you think would be easier to use and why?
 */
void reset(int &a, int &b)
{
    a = 0;
    b = 0;
}

/*
 * Exercise 6.17:
 * Write a function to determine whether a string contains
 * any capital letters. Write a function to change a string to all lowercase. Do
 * the parameters you used in these functions have the same type? If so, why?
 * If not, why not?
 */
bool hasCapitalLetters(const std::string &s)
{
    for (char i = 'A'; i <= 'Z'; ++i) {
        if (s.find(i) != string::npos)
            return true;
    }
    return false;
}

void toLowercase(std::string &s)
{
    for (char &i : s) {
        if (!isspace(i))
            i = tolower(i);
    }
}

/*
 * Exercise 6.21:
 * Write a function that takes an int and a pointer to an int
 * and returns the larger of the int value or the value to which the pointer
 * points. What type should you use for the pointer?
 */
int larger(int v1, const int *v2)
{
    return (v1 < *v2) ? *v2 : v1;
}

/*
 * Exercise 6.22:
 * Write a function to swap two int pointers.
 */
void ptr_swap(int **a, int **b)
{
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * Exercise 6.23:
 * Write your own versions of each of the print functions
 * presented in this section. Call each of these functions to print i and j
 * defined as follows:
 * int i = 0, j[2] = {0, 1};
 */
void solve_6_23()
{
    int i = 0;
    int j[2] = {0, 1};

    print(std::begin(j), std::end(j));

    print(&i, 1);
    print(j, 2);

    print(j);
}

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

void print(const int *arr, size_t size)
{
    for (size_t i = 0; i != size; ++i)
        cout << arr[i] << endl;
}

void print(int (&arr)[2])
{
    for (auto i : arr)
        cout << i << endl;
}

/*
 * Exercise 6.24:
 * Explain the behavior of the following function. If there are
 * problems in the code, explain what they are and how you might fix them.
 */
void solve_6_24()
{
    int i[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(i);
}

void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}

/*
 * Exercise 6.25:
 * Write a main function that takes two arguments.
 * Concatenate the supplied arguments and print the resulting string.
 */
void solve_6_25(int argc, char **argv)
{
    cout << (string(argv[1]) + string(argv[2])) << endl;
}

/*
 * Exercise 6.26:
 * Write a program that accepts the options presented in this
 * section. Print the values of the arguments passed to main.
 */
void solve_6_26(int argc, char **argv)
{
    for (int i = 0; i != argc; ++i)
        cout << argv[i] << endl;
}

/*
 * Exercise 6.27:
 * Write a function that takes an initializer_list<int>
 * and produces the sum of the elements in the list.
 */
void solve_6_27()
{
    cout << sum( {1, 3, 5} ) << endl;
    cout << sum( {1, 6, 5, 7} ) << endl;
    cout << sum( {1, 6} ) << endl;
}

int sum(initializer_list<int> il)
{
    int total = 0;
    for (int i : il)
        total += i;
    return total;
}

/*
 * Exercise 6.33:
 * Write a recursive function to print the contents of a vector.
 */
void solve_6_33()
{
    vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15};
    print_rec(vec.cbegin(), vec.cend());
}

void print_rec(vector<int>::const_iterator begin, vector<int>::const_iterator end)
{
    if (begin != end) {
        cout << *begin << endl;
        print_rec(++begin, end);
    }
}

/*
 * Exercises Section 6.7
 */

enum Operation
{
    Plus,
    Minus,
    Multiply,
    Divide
};

int plus(int a, int b)
{
    return a + b;
}

int minus(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

typedef int(*FunctionPointer)(int, int);
//using FunctionPointer = int(*)(int, int);

void solve_section_6_7()
{
    vector<FunctionPointer> functionPointers;
    functionPointers.push_back(plus);
    functionPointers.push_back(minus);
    functionPointers.push_back(multiply);
    functionPointers.push_back(divide);

    cout << functionPointers[Plus](9, 15) << endl;
    cout << functionPointers[Minus](17, 3) << endl;
    cout << functionPointers[Multiply](4, 19) << endl;
    cout << functionPointers[Divide](46, 2) << endl;
}
