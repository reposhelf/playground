/*
 * Exercise 9.44:
 * Rewrite the program 9.44 using an index and replace.
 */

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

bool canReplace(const string &s, string::size_type pos, const string &val) {
    for (string::size_type i = 0; i < val.size(); ++i) {
	if (s[pos++] != val[i])
	    return false;
    }
    return !isalpha(s[pos]);
}

string &replaceAll(string &s, const string &oldVal, const string &newVal) {
    for (string::size_type i = 0; i < s.size(); ++i) {
	if (s[i] == oldVal[0]) {
	    if (canReplace(s, i, oldVal)) {
		s.replace(i, oldVal.size(), newVal);
		i += newVal.size();
	    }
	}
    }
    return s;
}

int main() {
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
