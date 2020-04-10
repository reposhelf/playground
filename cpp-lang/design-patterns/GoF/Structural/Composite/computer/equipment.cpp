#include "equipment.h"

#include <iostream>

Equipment::~Equipment() {
    // Empty
}

Equipment::Equipment(const char *name)
    : name_(name),
      power_(0.0),
      net_price_(0.0),
      discount_price_(0.0) {
    // Empty
}

void Equipment::add(Equipment */*equipment*/) {
    std::cerr << "Adding does not support by this type\n";
}

void Equipment::remove(Equipment */*equipment*/) {
    std::cerr << "Removing does not support by this type\n";
}
