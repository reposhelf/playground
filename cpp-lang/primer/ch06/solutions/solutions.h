#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>
#include <initializer_list>
#include <vector>

/*
 * Exercise 6.3:
 * Write and test your own version of fact.
 */
int fact(int val);

/*
 * Exercise 6.4:
 * Write a function that interacts with the user, asking for a
 * number and generating the factorial of that number. Call this function from
 * main.
 */
void fact2();

/*
 * Exercise 6.5:
 * Write a function to return the absolute value of its argument.
 */
int abslt(int val);

/*
 * Exercise 6.7:
 * Write a function that returns 0 when it is first called and then
 * generates numbers in sequence each time it is called again.
 */
int count_calls();

/*
 * Exercise 6.10:
 * Using pointers, write a function to swap the values of two
 * ints. Test the function by calling it and printing the swapped values.
 */
void reset(int *a, int *b);

/*
 * Exercise 6.11:
 * Write and test your own version of reset that takes a
 * reference.
 */
void reset(int &a);

/*
 * Exercise 6.12:
 * Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210)
 * to use references instead of pointers to swap the value of two ints. Which
 * version do you think would be easier to use and why?
 */
void reset(int &a, int &b);

/*
 * Exercise 6.17:
 * Write a function to determine whether a string contains
 * any capital letters. Write a function to change a string to all lowercase. Do
 * the parameters you used in these functions have the same type? If so, why?
 * If not, why not?
 */
bool hasCapitalLetters(const std::string &s);
void toLowercase(std::string &s);

/*
 * Exercise 6.21:
 * Write a function that takes an int and a pointer to an int
 * and returns the larger of the int value or the value to which the pointer
 * points. What type should you use for the pointer?
 */
int larger(int v1, const int *v2);

/*
 * Exercise 6.22:
 * Write a function to swap two int pointers.
 */
void ptr_swap(int **a, int **b);

/*
 * Exercise 6.23:
 * Write your own versions of each of the print functions
 * presented in this section. Call each of these functions to print i and j
 * defined as follows:
 * int i = 0, j[2] = {0, 1};
 */
void solve_6_23();
void print(const int *beg, const int *end);
void print(const int *arr, size_t size);
void print(int (&arr)[2]);

/*
 * Exercise 6.24:
 * Explain the behavior of the following function. If there are
 * problems in the code, explain what they are and how you might fix them.
 */
void solve_6_24();
void print(const int ia[10]);

/*
 * Exercise 6.25:
 * Write a main function that takes two arguments.
 * Concatenate the supplied arguments and print the resulting string.
 */
void solve_6_25(int argc, char **argv);

/*
 * Exercise 6.26:
 * Write a program that accepts the options presented in this
 * section. Print the values of the arguments passed to main.
 */
void solve_6_26(int argc, char **argv);

/*
 * Exercise 6.27:
 * Write a function that takes an initializer_list<int>
 * and produces the sum of the elements in the list.
 */
void solve_6_27();
int sum(std::initializer_list<int> il);

/*
 * Exercise 6.33:
 * Write a recursive function to print the contents of a vector.
 */
void solve_6_33();
void print_rec(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

/*
 * Exercises Section 6.7
 */

 void solve_section_6_7();
 
#endif