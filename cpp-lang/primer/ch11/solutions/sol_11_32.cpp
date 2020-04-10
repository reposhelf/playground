/*
 * Exercise 11.32:
 * Using the multimap from the previous exercise, write a
 * program to print the list of authors and their works alphabetically.
 */

#include "chapter11.h"

#include <set>

using namespace std;

void sol_11_32()
{
    multimap<string, string> authors;
    // Stephen King
    authors.insert({"King, Stephen", "Carrie"});
    authors.insert({"King, Stephen", "The Shining"});
    authors.insert({"King, Stephen", "Rage"});
    authors.insert({"King, Stephen", "The Stand"});
    authors.insert({"King, Stephen", "The Long Walk"});
    // Leo Tolstoy
    authors.insert({"Tolstoy, Leo", "Childhood"});
    authors.insert({"Tolstoy, Leo", "Boyhood"});
    authors.insert({"Tolstoy, Leo", "Youth"});
    // Nikolai Gogol
    authors.insert({"Gogol, Nikolai", "Taras Bulba"});
    authors.insert({"Gogol, Nikolai", "Viy"});
    // Fyodor Dostoyevsky
    authors.insert({"Dostoyevsky, Fyodor", "The Idiot"});
    authors.insert({"Dostoyevsky, Fyodor", "Demons"});
    authors.insert({"Dostoyevsky, Fyodor", "The Brothers Karamazov"});
    authors.insert({"Dostoyevsky, Fyodor", "Crime and Punishment"});

    // Print alphabetically
    auto it = authors.cbegin();
    while (it != authors.cend()) {
	cout << it->first << ": " << endl;
	set<string> works;
	for (auto i = authors.count(it->first); i > 0; ++it, --i)
	    works.insert(it->second);
	for (const auto &w : works)
	    cout << string(4, ' ') << w << endl;
    }

    /*
    auto it = authors.cbegin();
    while (it != authors.cend()) {
	cout << it->first << ": " << endl;
	auto range = authors.equal_range(it->first);
	set<string> works;
	while (range.first != range.second) {
	    works.insert(range.first->second);
	    ++range.first;
	}
	for (const auto &w : works)
	    cout << string(4, ' ') << w << endl;
	it = range.second;
    }
    */
}
