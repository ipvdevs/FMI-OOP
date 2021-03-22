#include "IntStack.hpp"

// Default value for size is 0
IntStack::IntStack(const int size)
    : stackSize(size), top(-1), stack(new int[size]) {}

IntStack::~IntStack() {
  delete[] stack;
}

IntStack::IntStack(const IntStack &other) {
  this->stackSize = other.stackSize;
  this->top = other.top;
  this->stack = new int[stackSize];
  for (int i = 0; i <= top; ++i) {
    this->stack[i] = other.stack[i];
  }
}

IntStack &IntStack::operator=(const IntStack &other) {
  if (this != &other) {
    this->stackSize = other.stackSize;
    this->top = other.top;

    delete[] this->stack;
    this->stack = new int[stackSize];

    for (int i = 0; i <= top; ++i) {
      this->stack[i] = other.stack[i];
    }
  }
  return *this;
}

void IntStack::push(int element) {
  if (this->isFull()) {
    std::cout << "Stack Overflow!" << std::endl;
    return;
  }

  ++top;
  stack[top] = element;
}

int IntStack::pop() {
  if (this->isEmpty()) {
    std::cout << "Stack is empty: cannot pop an element!" << std::endl;
    return -1;
  }

  int popElement = stack[top];
  --top;
  return popElement;
}

int IntStack::peek() const {
  if (this->isEmpty()) {
    std::cout << "Stack is empty: there is nothing on the top!" << std::endl;
    return -1;
  }
  return stack[top];
}

unsigned int IntStack::size() const {
  return (top + 1);
}

bool IntStack::isEmpty() const {
  return (top == -1);
}

void IntStack::printElements() const {
  if (this->isEmpty()) {
    std::cout << "Stack is empty!" << '\n';
    return;
  }

  for (unsigned int i = 0; i <= top; ++i) {
    std::cout << stack[i] << ' ';
  }
  std::cout << std::endl;
}

// Private functions

bool IntStack::isFull() const {
  return (top + 1 == stackSize);
}