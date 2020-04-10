#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iostream>
using std::cout;
using std::endl;

int main() {
    list<int> int_list{1, 3, 7, 5};
    vector<int> int_vec{9, 11, 31};

    vector<double> d_vec_from_list(int_list.cbegin(), int_list.cend());
    vector<double> d_vec_from_vec(int_vec.cbegin(), int_vec.cend());

    for (double d : d_vec_from_list)
	cout << d << " ";
    cout << endl;

    for (double d : d_vec_from_vec)
	cout << d << " ";
    cout << endl;

    return 0;
}
