#include "solutions.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <vector>
using std::vector;

#include <cstring>

/*
 * Exercise 3.55.
 * Write a program that takes a string as argument,
 * and that prints out a table giving, for each character
 * that occurs in the string, the character and its 
 * frequency of occurrence.
 */
void solve_3_55(char *line)
{
    constexpr size_t reg_size = 256;
    unsigned unique_reg[reg_size] = {};  // initialize whole array by zero

    // handling
    for (char *i = line; *i != '\0'; ++i)
        ++unique_reg[(int)*i];

    // display
    for (size_t i = 0; i < reg_size; ++i) {
        if (unique_reg[i] != 0) {
            cout << '\'' << (char)i << '\'' << ": " << unique_reg[i] << " occurs" << endl;
        }
    }
}

/*
 * Exercise 3.56.
 * Write a program that check whether a given string is a palindrome
 * (reads the same backward or forward), ignoring blancks. For example,
 * your program should report success for the string 'if i had hifi'
 */
void solve_3_56()
{
    // read line
    cout << "Type a string:" << endl;
    char text[256];
    cin.getline(text, 256);
    // handle
    size_t size = strlen(text);
    bool isPalindrome = true;
    for (char *begin = text, *end = text + size - 1; (end - begin) > 0; ++begin, --end) {
        while (*begin == ' ') ++begin;
        while (*end == ' ') --end;
        if (*begin != *end) {
            isPalindrome = false;
            break;
        }
    }
    // display result
    isPalindrome ? cout << "It's palindrome" << endl
                 : cout << "It's not palindrome" << endl;
}

/*
 * Exercise 3.57.
 * Suppose that memory for strings is individually allocated.
 * Write versions of 'strcpy' and 'strcat' that allocate memory 
 * and return a pointer to the new string for the result.
 */
void solve_3_57()
{
    char *copy = strcpy("Hello, world!");
    cout << copy << endl;
    delete[] copy;

    copy = strcat("Hello, ", "Mars!");
    cout << copy << endl;
    delete[] copy;
}

char *strcpy(const char *str)
{
    size_t size = strlen(str) + 1;
    char *copy = new char[size];
    if (!copy) return nullptr;
    memcpy(copy, str, size);
    return copy;
}

char *strcat(const char *str1, const char *str2)
{
    size_t str1_sz = strlen(str1);
    size_t str2_sz = strlen(str2);
    char *copy = new char[str1_sz + str2_sz + 1];
    if (!copy) return nullptr;
    memcpy(copy, str1, str1_sz);
    memcpy(copy + str1_sz, str2, str1_sz + 1);
    return copy;
}

/*
 * Exercise 3.58.
 * Write a program that takes a string as argument and reads
 * a sequence of words (sequences of characters separated by
 * blank space) from standard input, printing out those that
 * appear as substrings somwhere in the argument string.
 */
void solve_3_58(const char *str)
{
    vector<char *> words;
    char c[25];
    // get words
    while (cin >> c)
        words.push_back(strdup(c));
    // print
    for (char *word : words) {
        if (strstr(str, word))
            cout << word << endl;
    }
    // free memeory
    for (char *word : words)
        free(word);
}

/*
 * Exercise 3.59.
 * Write a program that replaces substring of more than one blank
 * in a given string by exactly one blank.
 */
void solve_3_59()
{
    // read line
    char text[256];
    if (!cin.getline(text, 256)) return;
    cout << text << endl;

    // make copy of origin without blanks    
    char copy[256];
    char *t = text;
    char *c = copy;
    while (*t != '\0') {
        if (*t == ' ') {
            *c++ = *t++;
            while (*t == ' ') ++t;
        }
        *c++ = *t++;
    }
    strcpy(text, copy);
    cout << text << endl;
}

/*
 * Exercise 3.60.
 * Implement a pointer version of string_search.cpp
 */
void solve_3_60(char *str)
{
    const int N = 10000;

    char t;
    int a[N];
    int *i;
    char *p = str;
    for (i = a; i != a + N; *i = t, ++i) {
        if (!cin.get(t))
            break;
    }
    *i = 0;

    int l;
    for (i = a, l = 0; *i != 0; ++i, ++l) {
        char *j;
        int k;
        for (j = p, k = 0; *j != 0; ++j, ++k) {
            if (*(i + k) != *j)
                break;
        }
        if (*j == 0)
            cout << l << " ";
    }
    cout << endl;
}

/*
 * Exercise 3.61.
 * Write an efficient program that finds the length of the
 * longest sequence of blanks in a given string, examining \
 * as few characters in the string as possible. Hint: Your
 * program should become faster as the length of the sequences
 * of blanks increases.
 */
void solve_3_61()
{
    constexpr unsigned size = 5000000;
    char text[size];
    cin.getline(text, size);
    unsigned count = 0;
    char blanks[256] = {' '};
    while (strstr(text, blanks)) {
        ++count;
        strcat(blanks, " ");
    }
    cout << count << endl;
}
