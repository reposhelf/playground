#include "template_function.h"
#include "Sales_data.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>

int main()
{
  std::cout << compare(3, 3) << std::endl;
  std::cout << compare(10.7, 21.3) << std::endl;
  std::cout << compare(22.7, 22.3) << std::endl;

  std::string s1 = "hi";
  std::string s2 = "hello";
  std::cout << compare(s1, s2) << std::endl;
  std::cout << compare(s2, s1) << std::endl;

  std::cout << compare("good bye", "bye") << std::endl;

  Sales_data sd1("ALLB-4567-98754-GF2675");
  Sales_data sd2;
  std::cout << compare(sd1, sd2) << std::endl;

  std::vector<int> v{1, 2, 3, 4, 5, 6, 7};
  std::cout << *(find(v.cbegin(), v.cend(), 3)) << std::endl;

  std::list<std::string> l{"Hello", "Cruel", "World", "!"};
  std::cout << *(find(l.cbegin(), l.cend(), std::string("Cruel"))) << std::endl;

  int i_arr[5] = {0, 1, 2, 3, 4};
  printa(i_arr);

  std::cout << *(begin(i_arr)) << std::endl;
  std::cout << *(end(i_arr) - 1) << std::endl;
  std::cout << sizea(i_arr) << std::endl;

  printa("char array");

  std::vector<std::string> svec = {"foo", "bar", "baz", "qux"};
  printc(svec);
  printc_2(svec);

  return 0;
}
