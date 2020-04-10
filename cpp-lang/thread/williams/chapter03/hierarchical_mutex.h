#ifndef HIERARCHICAL_MUTEX_H
#define HIERARCHICAL_MUTEX_H

#include <mutex>

class HierarchicalMutex {
 public:
  explicit HierarchicalMutex(unsigned long value);
  
  void lock();
  void unlock();
  bool try_lock();

  unsigned long GetLevelValue() const { return hierarchy_value_; }

 private:
  void CheckHierarchyViolation();
  void UpdateHierarchyValue();

  std::mutex internal_mutex_;
  const unsigned long hierarchy_value_;
  unsigned long prev_hierarchy_value_;
  static thread_local unsigned long this_thread_hierarchy_value_;
};

#endif
