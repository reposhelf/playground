#include <thread>
#include <iostream>

void some_function()
{
  std::cout << __func__ << std::endl;
}

std::thread f()
{
  return std::thread(some_function);
}

std::thread g()
{
  std::thread t(some_function);
  return t;
}

int main()
{
  std::thread a = f();
  std::thread b = g();

  a.join();
  b.join();

  return 0;
}
