#include "solutions.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::getline;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <stdexcept>
using std::runtime_error;

/*
 * Exercise 5.9:
 * Write a program using a series of if statements to count the
 * number of vowels in text read from cin.
 */
void solve_5_9()
{
    string text;
    getline(cin, text);
    int aCount = 0;
    int eCount = 0;
    int iCount = 0;
    int oCount = 0;
    int uCount = 0;

    for (char ch : text) {
        if (ch == 'a')
            ++aCount;
        else if (ch == 'e')
            ++eCount;
        else if (ch == 'i')
            ++iCount;
        else if (ch == 'o')
            ++oCount;
        else if (ch == 'u')
            ++uCount;
    }

    cout << "Number of vowel a: \t" << aCount << '\n'
         << "Number of vowel e: \t" << eCount << '\n'
         << "Number of vowel i: \t" << iCount << '\n'
         << "Number of vowel o: \t" << oCount << '\n'
         << "Number of vowel u: \t" << uCount << endl;
}

/*
 * Exercise 5.10:
 * There is one problem with our vowel-counting program as
 * we’ve implemented it: It doesn’t count capital letters as vowels. Write a
 * program that counts both lower- and uppercase letters as the appropriate
 * vowel—that is, your program should count both 'a' and 'A' as part of
 * aCnt, and so forth.
 */
void solve_5_10()
{
    string text;
    getline(cin, text);
    int aCount = 0;
    int eCount = 0;
    int iCount = 0;
    int oCount = 0;
    int uCount = 0;

    for (char ch : text) {
        switch (ch) {
            case 'a': case 'A': ++aCount;
                break;
            case 'e': case 'E': ++eCount;
                break;
            case 'i': case 'I': ++iCount;
                break;
            case 'o': case 'O': ++oCount;
                break;
            case 'u': case 'U': ++uCount;
                break;
            default:
                break;
        }
    }

    cout << "Number of vowel a: \t" << aCount << '\n'
         << "Number of vowel e: \t" << eCount << '\n'
         << "Number of vowel i: \t" << iCount << '\n'
         << "Number of vowel o: \t" << oCount << '\n'
         << "Number of vowel u: \t" << uCount << endl;
}

/*
 * Exercise 5.11:
 * Modify our vowel-counting program so that it also counts the
 * number of blank spaces, tabs, and newlines read.
 */
void solve_5_11()
{
    string text;
    getline(cin, text);
    int aCount = 0;
    int eCount = 0;
    int iCount = 0;
    int oCount = 0;
    int uCount = 0;
    int spaceCount = 0;
    int tabCount = 0;
    int newLineCount = 0;

    for (char ch : text) {
        switch (ch) {
            // fall through
            case 'a':
            case 'A':
                ++aCount;
                break;
            // fall through
            case 'e':
            case 'E':
                ++eCount;
                break;
            // fall through
            case 'i':
            case 'I':
                ++iCount;
                break;
            // fall through
            case 'o':
            case 'O':
                ++oCount;
                break;
            // fall through
            case 'u':
            case 'U':
                ++uCount;
                break;
            case ' ':
                ++spaceCount;
                break;
            case '\t':
                ++tabCount;
                break;
            case '\n':
                ++newLineCount;
                break;
            default:
                break;
        }
    }

    cout << "Number of vowel a: \t" << aCount << '\n'
         << "Number of vowel e: \t" << eCount << '\n'
         << "Number of vowel i: \t" << iCount << '\n'
         << "Number of vowel o: \t" << oCount << '\n'
         << "Number of vowel u: \t" << uCount << '\n'
         << "Number of spaces: \t" << spaceCount << '\n'
         << "Number of tabs: \t" << tabCount << '\n'
         << "Number of new lines: \t" << newLineCount << endl;
}

/*
 * Exercise 5.12:
 * Modify our vowel-counting program so that it counts the
 * number of occurrences of the following two-character sequences: ff, fl,
 * and fi.
 */
void solve_5_12()
{
    string text;
    getline(cin, text);
    int ffCount = 0;
    int flCount = 0;
    int fiCount = 0;

    for (string::const_iterator it = text.cbegin(); it != text.cend(); ++it) {
        if (*it == 'f') {
            if (*(it + 1) == 'f')
                ++ffCount;
            else if (*(it + 1) == 'l')
                ++flCount;
            else if (*(it + 1) == 'i')
                ++fiCount;
        }
    }

    cout << "Number of ff sequnce: \t"  << ffCount << '\n'
         << "Number of fl sequnce: \t"  << flCount << '\n'
         << "Number of fi sequnce: \t"  << fiCount << endl;
}

/*
 * Exercise 5.14:
 * Write a program to read strings from standard input
 * looking for duplicated words. The program should find places in the input
 * where one word is followed immediately by itself. Keep track of the largest
 * number of times a single repetition occurs and which word is repeated. Print
 * the maximum number of duplicates, or else print a message saying that no
 * word was repeated. For example, if the input is
 * how now now now brown cow cow the output should indicate that the word now
 * occurred three times
 */
void solve_5_14()
{
    string word;
    vector<string> words;
    vector<int> repetitions;
    int maxValIndex = 0;
    while (cin >> word) {
        size_t i;
        for (i = 0; i < words.size(); ++i) {
            if (word == words[i]) {
                ++repetitions[i];
                if (repetitions[i] > repetitions[maxValIndex])
                    maxValIndex = i;
                break;
            }
        }
        if (i >= words.size()) {
            words.push_back(word);
            repetitions.push_back(1);
        }
    }
    (repetitions[maxValIndex] == 1) 
        ? cout << "No repetitions" << endl
        : cout << words[maxValIndex] << " occured " 
               << repetitions[maxValIndex] << " times." << endl;
}

/*
 * Exercise 5.16:
 * The while loop is particularly good at executing while some
 * condition holds; for example, when we need to read values until end-of-file.
 * The for loop is generally thought of as a step loop: An index steps through
 * a range of values in a collection. Write an idiomatic use of each loop and
 * then rewrite each using the other loop construct. If you could use only one
 * loop, which would you choose? Why?
 */
void solve_5_16()
{
    string word;
    while (cin >> word)
        cout << word << endl;
    for (int i = 1; i <= 10; ++i)
        cout << i << endl;

    int i = 1;
    while (i <= 10) {
        cout << i << endl;
        ++i;
    }
    for (; cin >> word;)
        cout << word << endl;
}

/*
 * Exercise 5.17:
 * Given two vectors of ints, write a program to determine
 * whether one vector is a prefix of the other. For vectors of unequal
 * length, compare the number of elements of the smaller vector. For
 * example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5,
 * 8, respectively your program should return true.
 */
void solve_5_17()
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};

    // bool (*isPrefix)(const vector<int> &less, const vector<int> &more) {}
    auto isPrefix = [](const vector<int> &less, const vector<int> &more) {
        for (size_t i = 0; i < less.size(); ++i) {
            if (less[i] != more[i])
                return false;
        }
        return true;
    };

    if (v1 < v2)
        cout << isPrefix(v1, v2) << endl;
    else if (v2 < v1)
        cout << isPrefix(v2, v1) << endl;
    else
        cout << false << endl;
}

/*
 * Exercise 5.19:
 * Write a program that uses a do while loop to repetitively
 * request two strings from the user and report which string is less than
 * the other.
 */
void solve_5_19()
{
    do {
        string str1;
        string str2;
        if (cin >> str1 >> str2) {
            if (str1 < str2)
                cout << "Second string is larger" << endl;
            else if (str1 > str2)
                cout << "First string is larger" << endl;
            else
                cout << "Strings are equal" << endl;
        }
    } while (cin);
}

/*
 * Exercise 5.20:
 * Write a program to read a sequence of strings from the
 * standard input until either the same word occurs twice in succession or all
 * the words have been read. Use a while loop to read the text one word at a
 * time. Use the break statement to terminate the loop if a word occurs twice
 * in succession. Print the word if it occurs twice in succession, or else print a
 * message saying that no word was repeated.
 */
void solve_5_20()
{
    auto repeated = [](const string &word, const vector<string> &words) {
        for (string w : words) {
            if (word == w) {
                return true;
            }
        }
        return false;
    };

    string word;
    vector<string> words;
    while (cin >> word) {
        if (repeated(word, words)) {
            cout << word << " was repeated" << endl;
            break;
        }
        words.push_back(word);
    }
    if (!cin)
        cout << "no word was repeated" << endl;
}

/*
 * Exercise 5.21:
 * Revise the program from the exercise 5.20 so
 * that it looks only for duplicated words that start with an uppercase letter.
 */
void solve_5_21()
{
    auto repeated = [](const string &word, const vector<string> &words) {
        for (string w : words) {
            if (word == w) {
                if (word[0] >= 'A' && word[0] <= 'Z')
                    return true;
            }
        }
        return false;
    };

    string word;
    vector<string> words;
    while (cin >> word && !word.empty()) {
        if (repeated(word, words)) {
            cout << word << " was repeated" << endl;
            break;
        }
        words.push_back(word);
    }
    if (!cin)
        cout << "no word was repeated" << endl;
}

/*
 * Exercise 5.23:
 * Write a program that reads two integers from the standard
 * input and prints the result of dividing the first number by the second.
 */
void solve_5_23()
{
    int first, second;
    while (cin >> first >> second)
        cout << (first / second) << endl;
}

/*
 * Exercise 5.24:
 * Revise your program to throw an exception if the second
 * number is zero. Test your program with a zero input to see what happens on
 * your system if you don’t catch an exception.
 */
void solve_5_24()
{
    int first, second;
    while (cin >> first >> second) {
        if (second == 0)
            throw runtime_error("Dividing by zero");
        cout << (first / second) << endl;
    }
}

/*
 * Exercise 5.25:
 * Revise your program from the previous exercise to use a
 * try block to catch the exception. The catch clause should print a message
 * to the user and ask them to supply a new number and repeat the code inside
 * the try.
 */
void solve_5_25()
{
    int first, second;
    while (cin >> first >> second) {
        try {
            if (second == 0)
                throw runtime_error("error: dividing by zero");
            cout << (first / second) << endl;
        } catch (runtime_error err) {
            cout << err.what() << endl;
        }
        cout << "Continue (y/n)?: ";
        char c;
        cin >>c;
        if (!cin || c == 'n')
            break;
    }
}