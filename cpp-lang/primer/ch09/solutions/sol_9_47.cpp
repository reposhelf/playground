/*
 * Exercise 9.47:
 * Write a program that finds each numeric character and then each alphabetic
 * character in the string "ab2c3d7R4E6". Write two versions of the program.
 * The first should use find_first_of, and the second find_first_not_of.
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

static const char *numbers = "0123456789";
static const char *letters =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void use_find_first_of(const string &str,
		       const string &search,
		       const string &out_text)
{
    string::size_type pos = 0;
    while ((pos = str.find_first_of(search, pos)) != string::npos) {
	cout << out_text << pos << " element is " << str[pos] << endl;
	++pos;
    }
}

void use_find_first_of(const string &str)
{
    use_find_first_of(str, numbers, "found number at index: ");
    use_find_first_of(str, letters, "fount letter at index: ");
}

void use_find_first_not_of(const string &str,
			   const string &search,
			   const string &out_text)
{
    string::size_type pos = 0;
    while ((pos = str.find_first_not_of(search, pos)) != string::npos) {
	cout << out_text << pos << " element is " << str[pos] << endl;
	++pos;
    }
}

void use_find_first_not_of(const string &str)
{
    use_find_first_not_of(str, letters, "found number at index: ");
    use_find_first_not_of(str, numbers, "fount letter at index: ");
}

int main()
{
    string str = "ab2c3d7R4E6";
    use_find_first_of(str);
    use_find_first_not_of(str);
    return 0;
}
