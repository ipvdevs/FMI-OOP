#ifndef COUNTER__SEMAPHORE_HPP_
#define COUNTER__SEMAPHORE_HPP_

#include "LimitedTwowayCounter.hpp"

#define DEF_MIN 0
#define DEF_MAX 1

class Semaphore : protected LimitedTwowayCounter {
 public:
  Semaphore(bool available = false);

  bool isAvailable() const;
  void wait();
  void signal();
};

#endif //COUNTER__SEMAPHORE_HPP_
