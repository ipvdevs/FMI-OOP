#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned int step)
    : Counter(initial, step), LimitedCounter(max), min(min) {}

void LimitedTwowayCounter::decrement() {
  if ((int) (counter - step) >= min) {
    TwowayCounter::decrement();
  }
}

int LimitedTwowayCounter::getMin() const {
  return min;
}
