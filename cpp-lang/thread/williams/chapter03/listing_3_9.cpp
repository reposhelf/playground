/*
 * Listing 3.9
 * Using std::lock() and std::unique_lock in a swap operation
 */
#include <mutex>

class some_big_data {};

void swap(some_big_data &lhs, some_big_data &rhs) {}

class test {
 public:
  explicit test(const some_big_data &sd)
      : some_detail_(sd) {}

  friend void swap(test &lhs, test &rhs) {
    if (&lhs == &rhs)
      return;
    std::unique_lock<std::mutex> lock_a(lhs.m_, std::defer_lock);
    std::unique_lock<std::mutex> lock_b(rhs.m_, std::defer_lock);
    std::lock(lock_a, lock_b);
    swap(lhs.some_detail_, rhs.some_detail_);
  }

 private:
  some_big_data some_detail_;
  std::mutex m_;
};

int main() {
  return 0;
}
