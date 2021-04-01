#ifndef STACKDYNAMIC_HPP_
#define STACKDYNAMIC_HPP_

#include <iostream>

#define INIT_SIZE 1

//LIFO
class StackDynamic {
 public:
  StackDynamic();
  StackDynamic(const StackDynamic&);
  ~StackDynamic();

  StackDynamic& operator=(const StackDynamic&);

  int size() const;
  void push_back(int);
  int pop_back();
  bool isEmpty() const;
  int peek() const;
  void printElements() const;

 private:
  int* arr;
  unsigned int arrSize;
  int top;

  void grow();
};

#endif //STACKDYNAMIC_HPP_
