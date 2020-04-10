#include "hierarchical_mutex.h"

#include <iostream>

class HierarchicalMutexTest {
 public:
  HierarchicalMutexTest(unsigned long main_level_value,
                        unsigned long high_level_value,
                        unsigned long mid_level_value,
                        unsigned long low_level_value)
      : main_level_mutex_(main_level_value),
        high_level_mutex_(high_level_value),
        mid_level_mutex_(mid_level_value),
        low_level_mutex_(low_level_value) {}
  
  void DoJob() {
    unsigned long level_value = main_level_mutex_.GetLevelValue();
    std::cout << "DoJob(): Mutex Level Value = " << level_value << std::endl;
    std::lock_guard<HierarchicalMutex> lg(main_level_mutex_);
    DoHighLevelJob();
  }

 private:
  void DoHighLevelJob() {
    unsigned long level_value = high_level_mutex_.GetLevelValue();
    std::cout << "DoHighLevelJob(): Mutex Level Value = " << level_value << std::endl;
    std::lock_guard<HierarchicalMutex> lg(high_level_mutex_);
    DoMidLevelJob();
  }

  void DoMidLevelJob() {
    unsigned long level_value = mid_level_mutex_.GetLevelValue();
    std::cout << "DoMidLevelJob(): Mutex Level Value = " << level_value << std::endl;
    std::lock_guard<HierarchicalMutex> lg(mid_level_mutex_);
    DoLowLevelJob();
  }

  void DoLowLevelJob() {
    unsigned long level_value = low_level_mutex_.GetLevelValue();
    std::cout << "DoLowLevelJob(): Mutex Level Value = " << level_value << std::endl;
    std::lock_guard<HierarchicalMutex> lg(low_level_mutex_);
  }

  HierarchicalMutex main_level_mutex_;
  HierarchicalMutex high_level_mutex_;
  HierarchicalMutex mid_level_mutex_;
  HierarchicalMutex low_level_mutex_;
};

class PotentialDeadlockScope {};

int main() {
  HierarchicalMutexTest correct(10000, 1000, 100, 10);
  correct.DoJob();

  HierarchicalMutexTest bad(10000, 1000, 10, 100);
  bad.DoJob();
  return 0;
}

