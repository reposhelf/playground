#ifndef SOLUTIONS_H
#define SOLUTIONS_H

/*
 * Exercise 3.55.
 * Write a program that takes a string as argument,
 * and that prints out a table giving, for each character
 * that occurs in the string, the character and its 
 * frequency of occurrence.
 */
void solve_3_55(char *line);

/*
 * Exercise 3.56.
 * Write a program that check whether a given string is a palindrome
 * (reads the same backward or forward), ignoring blancks. For example,
 * your program should report success for the string 'if i had hifi'
 */
void solve_3_56();

/*
 * Exercise 3.57.
 * Suppose that memory for strings is individually allocated.
 * Write versions of 'strcpy' and 'strcat' that allocate memory 
 * and return a pointer to the new string for the result.
 */
void solve_3_57();
char *strcpy(const char *str);
char *strcat(const char *str1, const char *str2);

/*
 * Exercise 3.58.
 * Write a program that takes a string as argument and reads
 * a sequence of words (sequences of characters separated by
 * blank space) from standard input, printing out those that
 * appear as substrings somwhere in the argument string.
 */
void solve_3_58(const char *str);

/*
 * Exercise 3.59.
 * Write a program that replaces substring of more than one blank
 * in a given string by exactly one blank.
 */
void solve_3_59();

/*
 * Exercise 3.60.
 * Implement a pointer version of string_search.cpp
 */
void solve_3_60(char *str);

/*
 * Exercise 3.61.
 * Write an efficient program that finds the length of the
 * longest sequence of blanks in a given string, examining \
 * as few characters in the string as possible. Hint: Your
 * program should become faster as the length of the sequences
 * of blanks increases.
 */
void solve_3_61();

#endif