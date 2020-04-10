/*
 * Exercise 9.43:
 * Write a function that takes three strings, s, oldVal, and newVal. Using
 * iterators, and the insert and erase functions replace all instances of
 * oldVal that appear in s by newVal. Test your function by using it to
 * replace common abbreviations, such as “tho” by “though” and “thru” by
 * “through”.
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

bool canReplace(const string &s, string::iterator it, const string &oldVal) {
    for (auto i = oldVal.begin(); i != oldVal.end(); ++i) {
	if (*(it++) != *i)
	    return false;
    }
    return !isalpha(*it);
}

string &replaceAll(string &s, const string &oldVal, const string &newVal) {
    for (auto it = s.begin(); it != s.end(); ++it) {
	if (*it == *(oldVal.begin())) {
	    if (canReplace(s, it, oldVal)) {
		auto pos = it - s.begin();
		it = s.erase(it, it + oldVal.size());
		s.insert(it, newVal.begin(), newVal.end());
		it = s.begin() + pos + newVal.size() - 1;
	    }
	}
    }
    return s;
}

int main()
{
  string s = "Even tho, bla-bla-bla..., tho bla-bla-bla tho";
  string oldVal = "tho";
  string newVal = "though";

  cout << s << endl;
  s = replaceAll(s, oldVal, newVal);
  cout << s << endl;

  s = "thru bla-bla-bla thrugh thru.";
  oldVal = "thru";
  newVal = "through";

  cout << s << endl;
  s = replaceAll(s, oldVal, newVal);
  cout << s << endl;

  return 0;
}
