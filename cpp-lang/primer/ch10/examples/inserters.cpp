#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

void print(const std::string &label, const std::list<int> lst)
{
    std::cout << label << std::endl;
    for (auto iter : lst) 
        std::cout << iter << ' ';
    std::cout << std::endl;
}

int main()
{
    std::list<int> lst = {1, 2, 3, 4};
    print("lst", lst);

    std::list<int> lst2, lst3;
    std::copy(lst.begin(), lst.end(), std::front_inserter(lst2));

    std::copy(lst.begin(), lst.end(), std::inserter(lst3, lst3.begin()));

    print("lst2", lst2);
    print("lst3", lst3);

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::list<int> new_lst = {6, 7, 8, 9};
    auto it = new_lst.begin();
    std::copy(v.begin(), v.end(), std::inserter(new_lst, it));
    print("new_lst", new_lst);

    return 0;
}