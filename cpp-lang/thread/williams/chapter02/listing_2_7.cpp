/*
 * Listing 2.7.
 * Spawn some threads and wait for them to finish
 */

#include <thread>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

void do_work(int i)
{
  std::cout << i << std::endl;
}

int main()
{
  std::vector<std::thread> threads;
  for (size_t i = 0; i != 20; ++i)
    threads.push_back(std::thread(do_work, i));
  std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
  return 0;
}
