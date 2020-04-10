/*
 * Exercise 9.49:
 * A letter has an ascender if, as with d or f, part of the letter extends
 * above the middle of the line. A letter has a descender if, as with p or
 * g, part of the letter extends below the line. Write a program that reads a
 * file containing words and reports the longest word that contains neither
 * ascenders nor descenders.
 */

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

bool has_ascender_letter(const string &word)
{
    static const string ascender = "bdfk";
    return (word.find_first_of(ascender) != string::npos);
}

bool has_descender_letter(const string &word)
{
    static const string descender = "gjpy";
    return (word.find_first_of(descender) != string::npos);
}

inline void error(const char *msg)
{
    cerr << msg << endl;
    exit(1);
}

int main()
{
    ifstream in("sol_9_49_data");
    if (!in.is_open())
	error("Error: cannot open file.");

    string buf;
    string word;
    while (in >> word) {
	if (!(has_ascender_letter(word) || has_descender_letter(word)))
	    buf = word.size() > buf.size() ? word : buf;
    }

    cout << buf << " has size of " << buf.size() << endl;
    return 0;
}
