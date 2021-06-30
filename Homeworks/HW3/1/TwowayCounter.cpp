#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter(int initial, unsigned int step)
    : Counter(initial, step) {}

void TwowayCounter::decrement() {
  Counter::counter -= Counter::step;
}
