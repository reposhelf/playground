#include "blob.h"
#include "unique_pointer.h"

#include <iostream>
#include <vector>

int main()
{
  Blob<int> iblob{1 ,2, 3, 4, 5};
  
  for (auto it = iblob.begin(); it != iblob.end(); ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;

  iblob.push_back(6);
  iblob.push_back(7);
  iblob.pop_back();

  for (Blob<int>::size_type i = 0; i != iblob.size(); ++i)
    std::cout << iblob[i] << ' ';
  std::cout << std::endl;

  std::cout << "size: " << iblob.size() << std::endl;
  std::cout << "empty: " << (iblob.empty() ? "true" : "false") << std::endl;
  std::cout << "front: " << iblob.front() << std::endl;
  std::cout << "back: " << iblob.back() << std::endl;

  /////////////////////////////////////////////////////////////////////////////
  unique_pointer<std::vector<int>, debug_delete> up(new std::vector<int>{10, 20, 30, 40, 50}, debug_delete());
  std::cout << "up->back(): " << up->back() << std::endl;

  unique_pointer<std::vector<int>, debug_delete> up2(std::move(up));
  std::cout << "up2->back(): " << up2->back() << std::endl;

  return 0;
}
