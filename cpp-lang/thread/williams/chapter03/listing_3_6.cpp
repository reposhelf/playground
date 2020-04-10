/*
 * Listing 3.6
 * Using std::lock and std::lock_guard in a swap operation
 */
#include <mutex>

class some_big_data
{
};

void swap(some_big_data &lhs, some_big_data &rhs)
{
}

class test
{
public:
  explicit test(const some_big_data &sd)
    : _some_details(sd)
    {
    }

  friend void swap(test &lhs, test &rhs)
    {
      if (&lhs == &rhs)
        return;
      std::lock(lhs._m, rhs._m);
      std::lock_guard<std::mutex> lock_a(lhs._m, std::adopt_lock);
      std::lock_guard<std::mutex> lock_b(rhs._m, std::adopt_lock);
      swap(lhs._some_details, rhs._some_details);
    }

private:
  some_big_data _some_details;
  std::mutex _m;
};

int main()
{
  return 0;
}
