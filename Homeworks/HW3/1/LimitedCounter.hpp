#ifndef COUNTER__LIMITEDCOUNTER_HPP_
#define COUNTER__LIMITEDCOUNTER_HPP_

#include "Counter.hpp"

class LimitedCounter : virtual public Counter {
 public:
  LimitedCounter(int max, int initial = DEF_INITIAL, unsigned int step = DEF_STEP);

  // Override
  void increment();

  int getMax() const;

 private:
  int max;
};

#endif //COUNTER__LIMITEDCOUNTER_HPP_
