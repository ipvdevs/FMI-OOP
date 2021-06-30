#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max, int initial, unsigned int step)
    : Counter(initial, step), max(max) {}

void LimitedCounter::increment() {
  if ((int) (counter + step) <= max) {
    Counter::increment();
  }
}

int LimitedCounter::getMax() const {
  return max;
}


