#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    multimap<string, string> authors;
    authors.insert({"Alain de Botton", "On Love"});
    authors.insert({"Alain de Botton", "Status Anxiety"});
    authors.insert({"Alain de Botton", "Art of Travel"});
    authors.insert({"Alain de Botton", "Architecture of Happiness"});

    string search_item("Alain de Botton");

    // 1st way:
    auto entries = authors.count(search_item);
    auto iter = authors.find(search_item);
    while (entries) {
	cout << iter->second << endl;
	++iter;
	--entries;
    }

    // 2nd way:
    auto beg = authors.lower_bound(search_item);
    auto end = authors.upper_bound(search_item);
    for (; beg != end; ++beg)
	cout << beg->second << endl;

    // 3rd way:
    auto range = authors.equal_range(search_item);
    for (; range.first != range.second; ++range.first)
	cout << range.first->second << endl;

    return 0;
}
