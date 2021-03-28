#include "StackDynamic.hpp"

StackDynamic::StackDynamic()
    : arr(nullptr), arrSize(0), top(-1) {}

StackDynamic::StackDynamic(const StackDynamic& other) {
  this->arrSize = other.arrSize;
  this->top = other.top;
  this->arr = new int[arrSize];
  for (int i = 0; i <= top; ++i) {
    this->arr[i] = other.arr[i];
  }
}

StackDynamic::~StackDynamic() {
  delete[] arr;
  arrSize = 0;
  top = 0;
}

StackDynamic& StackDynamic::operator=(const StackDynamic& other) {
  if (this != &other) {
    this->arrSize = other.arrSize;
    this->top = other.top;

    delete[] this->arr;
    this->arr = new int[arrSize];
    for (int i = 0; i <= top; ++i) {
      this->arr[i] = other.arr[i];
    }
  }
  return *this;
}

int StackDynamic::size() const {
  return top + 1;
}

void StackDynamic::grow() {
  if (this->arr == nullptr) {
    this->arr = new int[INIT_SIZE];
    this->arrSize = INIT_SIZE;
    return;
  }

  unsigned int newSize = this->arrSize * 2;
  int* stackBuffer = new int[newSize];

  for (int i = 0; i < this->arrSize; ++i) {
    stackBuffer[i] = this->arr[i];
  }

  delete[] this->arr;
  this->arr = new int[newSize];

  for (int i = 0; i < arrSize; ++i) {
    arr[i] = stackBuffer[i];
  }
  this->arrSize = newSize;

  delete[] stackBuffer;
}

void StackDynamic::push_back(int number) {
  if (this->size() >= arrSize) {
    grow();
  }

  ++top;
  arr[top] = number;
}

int StackDynamic::pop_back() {
  if (this->size() == 0) {
    // Exception placeholder - underflow
    return 0;
  }

  int peek = arr[top];
  this->arr[top] = 0;
  --top;

  return peek;
}

bool StackDynamic::isEmpty() const {
  return (this->size() == 0);
}

int StackDynamic::peek() const {
  if (this->size() <= 0) {
    // Exception placeholder - underflow
    return 0;
  }

  return this->arr[top];
}

void StackDynamic::printElements() const {
  if (this->isEmpty()) {
    // Exception placeholder - underflow
    return;
  }

  for (unsigned int i = 0; i < top; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << arr[top] << std::endl;
}


