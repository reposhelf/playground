/*
 * Listing 2.6.
 * scoped_thread and example usage.
 */

#include <thread>
#include <iostream>

class scoped_thread
{
  std::thread t;
public:
  explicit scoped_thread(std::thread t_) : t(std::move(t_))
    {
      if (!t.joinable())
        throw std::logic_error("No thread");
    }
  ~scoped_thread()
    {
      t.join();
    }
  scoped_thread(const scoped_thread&) = delete;
  scoped_thread &operator=(const scoped_thread&) = delete;
};

struct func
{
  int &i;
  explicit func(int &i_) :i(i_) { std::cout << __func__ << std::endl; }
  void operator()()
    {
      for (unsigned j = 0; j < 100000; ++j)
	std::cout << j << std::endl;
    }
};

int main()
{
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread t(my_func);
  scoped_thread st(std::move(t));
  return 0;
}
