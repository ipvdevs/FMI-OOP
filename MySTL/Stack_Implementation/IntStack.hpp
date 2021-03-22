#ifndef INTSTACK_H_
#define INTSTACK_H_

#include <iostream>

class IntStack {
 public:
  IntStack(int size = 0);
  IntStack(const IntStack &);
  ~IntStack();

  IntStack &operator=(const IntStack &);

  // Add element to the top of the stack
  void push(int);
  // Remove the first element of the stack and return it's value
  int pop();
  // Fetch the first element of the stack
  int peek() const;
  unsigned int size() const;
  bool isEmpty() const;
  void printElements() const;

 private:
  int *stack;
  unsigned int stackSize;
  int top;
  bool isFull() const;
};

#endif //INTSTACK_H_
