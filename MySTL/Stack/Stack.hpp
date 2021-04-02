#ifndef STACKDYNAMIC_HPP_
#define STACKDYNAMIC_HPP_

#include <iostream>

#define INIT_SIZE 1

//LIFO
template<typename T>
class Stack {
 public:
  Stack();
  Stack(const Stack&);
  ~Stack();

  Stack& operator=(const Stack&);

  int size() const;
  void push_back(const T&);
  T pop_back();
  bool isEmpty() const;
  T peek() const;

 private:
  T* arr;
  unsigned int arrSize;
  int top;

  void reserve();
};

#endif //STACKDYNAMIC_HPP_

template<typename T>
Stack<T>::Stack()
    : arr(nullptr), arrSize(0), top(-1) {}

template<typename T>
Stack<T>::Stack(const Stack& other) {
  this->arrSize = other.arrSize;
  this->top = other.top;
  this->arr = new T[arrSize];
  for (int i = 0; i <= top; ++i) {
    this->arr[i] = other.arr[i];
  }
}

template<typename T>
Stack<T>::~Stack() {
  delete[] arr;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
  if (this != &other) {
    this->arrSize = other.arrSize;
    this->top = other.top;

    delete[] this->arr;
    this->arr = new T[arrSize];
    for (int i = 0; i <= top; ++i) {
      this->arr[i] = other.arr[i];
    }
  }
  return *this;
}

template<typename T>
int Stack<T>::size() const {
  return top + 1;
}

template<typename T>
void Stack<T>::reserve() {
  if (this->arr == nullptr) {
    this->arr = new T[INIT_SIZE];
    this->arrSize = INIT_SIZE;
    return;
  }

  unsigned int newSize = this->arrSize * 2;
  T* reserveBuffer = new T[newSize];

  for (int i = 0; i < this->arrSize; ++i) {
    reserveBuffer[i] = this->arr[i];
  }

  delete[] this->arr;
  this->arr = reserveBuffer;
  this->arrSize = newSize;
}

template<typename T>
void Stack<T>::push_back(const T& element) {
  if (this->size() >= arrSize) {
    reserve();
  }

  ++top;
  arr[top] = element;
}

template<typename T>
T Stack<T>::pop_back() {
  if (this->size() == 0) {
    // Exception placeholder - underflow
    return 0;
  }

  T peek = arr[top];
  --top;

  return peek;
}

template<typename T>
bool Stack<T>::isEmpty() const {
  return (this->size() == 0);
}

template<typename T>
T Stack<T>::peek() const {
  if (this->size() <= 0) {
    // Exception placeholder - underflow
    return 0;
  }

  return this->arr[top];
}

