/*
 * Exercise 9.26:
 * Using the following definition of ia, copy ia into a vector and into a list.
 * Use the single-iterator form of erase to remove the elements with odd values
 * from your list and the even values from your vector.
 */

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iostream>
using std::cout;
using std::endl;

template<class T> void print(T first, T last) {
    for (; first != last; ++first)
	cout << *first << " ";
    cout << endl;
}

int main() {
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    vector<int> ivec(std::begin(ia), std::end(ia));
    auto it_vec = ivec.begin();
    while (it_vec != ivec.end()) {
	if (!(*it_vec % 2))
	    it_vec = ivec.erase(it_vec);
	else
	    ++it_vec;
    }
    print(ivec.cbegin(), ivec.cend());

    list<int> ilst(std::begin(ia), std::end(ia));
    auto it_lst = ilst.begin();
    auto it_lst_end = ilst.end();
    while (it_lst != it_lst_end) {
	if (*it_lst % 2)
	    it_lst = ilst.erase(it_lst);
	else
	    ++it_lst;
    }
    print(ilst.cbegin(), ilst.cend());

    return 0;
}
