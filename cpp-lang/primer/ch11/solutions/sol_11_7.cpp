/*
 * Exercise 11.7:
 * Define a map for which the key is the family’s last name and
 * the value is a vector of the children’s names. Write code to add new
 * families and to add new children to an existing family.
 */

#include "chapter11.h"

using namespace std;

void add_family(const string &family_last_name,
		const vector<string> &children,
		map<string, vector<string>> &family)
{
    family[family_last_name] = children;
}

void add_child(const string &family_last_name,
	       const string &child_name,
	       map<string, vector<string>> &family)
{
    family[family_last_name].push_back(child_name);
}

void sol_11_7()
{
    map<string, vector<string>> family;

    add_family("Jacksons", vector<string>(), family);
    add_child("Jacksons", "Veronica", family);
    add_child("Jacksons", "Matt", family);

    vector<string> abrams_children = {"Daniel", "Chloe"};
    add_family("Abrams", abrams_children, family);

    for (const auto &f : family) {
	cout << f.first << ": ";
	for (const auto &c : f.second)
	    cout << c << ", ";
	cout << endl;
    }
}
