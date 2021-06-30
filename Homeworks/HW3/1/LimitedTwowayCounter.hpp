#ifndef COUNTER__LIMITEDTWOWAYCOUNTER_HPP_
#define COUNTER__LIMITEDTWOWAYCOUNTER_HPP_

#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class LimitedTwowayCounter : public TwowayCounter, public LimitedCounter {
 public:
  LimitedTwowayCounter(int min, int max, int initial = DEF_INITIAL, unsigned int step = DEF_STEP);

  // Override
  void decrement();

  int getMin() const;

 private:
  int min;
};

#endif //COUNTER__LIMITEDTWOWAYCOUNTER_HPP_
