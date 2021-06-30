#ifndef COUNTER__TWOWAYCOUNTER_HPP_
#define COUNTER__TWOWAYCOUNTER_HPP_

#include "Counter.hpp"

class TwowayCounter : virtual public Counter {
 public:
  TwowayCounter(int initial = DEF_INITIAL, unsigned int step = DEF_STEP);

  void decrement();
};

#endif //COUNTER__TWOWAYCOUNTER_HPP_
