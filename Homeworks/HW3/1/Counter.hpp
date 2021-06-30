#ifndef COUNTER__COUNTER_HPP_
#define COUNTER__COUNTER_HPP_

#define DEF_INITIAL 0
#define DEF_STEP 1

class Counter {
 public:
  Counter(int initial = DEF_INITIAL, unsigned int step = DEF_STEP);
  void increment();
  int getTotal() const;
  unsigned int getStep() const;

 protected:
  int counter;
  unsigned int step;
};

#endif //COUNTER__COUNTER_HPP_
