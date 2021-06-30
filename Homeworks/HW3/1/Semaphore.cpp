#include "Semaphore.hpp"

Semaphore::Semaphore(bool available)
    : Counter((available ? 1 : 0), DEF_STEP),
      LimitedTwowayCounter(DEF_MIN, DEF_MAX) {}

bool Semaphore::isAvailable() const {
  return LimitedTwowayCounter::getTotal();
}

void Semaphore::wait() {
  LimitedTwowayCounter::decrement();
}

void Semaphore::signal() {
  LimitedTwowayCounter::increment();
}


