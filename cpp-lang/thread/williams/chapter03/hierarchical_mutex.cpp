#include "hierarchical_mutex.h"

#include <stdexcept>
#include <climits>

thread_local unsigned long HierarchicalMutex::this_thread_hierarchy_value_(ULONG_MAX);

HierarchicalMutex::HierarchicalMutex(unsigned long value)
  : hierarchy_value_(value),
    prev_hierarchy_value_(0) {}

void HierarchicalMutex::lock() {
  CheckHierarchyViolation();
  internal_mutex_.lock();
  UpdateHierarchyValue();
}

void HierarchicalMutex::unlock() {
  this_thread_hierarchy_value_ = prev_hierarchy_value_;
  internal_mutex_.unlock();
}

bool HierarchicalMutex::try_lock() {
  CheckHierarchyViolation();
  if (!internal_mutex_.try_lock())
    return false;
  UpdateHierarchyValue();
  return true;
}

void HierarchicalMutex::CheckHierarchyViolation() {
  if (this_thread_hierarchy_value_ <= hierarchy_value_)
    throw std::logic_error("mutext hierarchy violated");
}

void HierarchicalMutex::UpdateHierarchyValue() {
  prev_hierarchy_value_ = this_thread_hierarchy_value_;
  this_thread_hierarchy_value_ = hierarchy_value_;
}
