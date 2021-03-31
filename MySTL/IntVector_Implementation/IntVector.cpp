#include "IntVector.hpp"

IntVector::IntVector() {
  array = nullptr;
  elementsCount = 0;
  arraySize = 0;
}

IntVector::IntVector(const IntVector& other) {
  this->arraySize = other.arraySize;
  this->elementsCount = other.elementsCount;
  this->array = new int[arraySize];
  for (int element_i = 0; element_i < elementsCount; ++element_i) {
    this->array[element_i] = other.array[element_i];
  }
}

IntVector::~IntVector() {
  delete[] array;
}

IntVector& IntVector::operator=(const IntVector& other) {
  if (this != &other) {
    this->arraySize = other.arraySize;
    this->elementsCount = other.elementsCount;

    delete[] array;
    this->array = new int[arraySize];
    for (int element_i = 0; element_i < elementsCount; ++element_i) {
      this->array[element_i] = other.array[element_i];
    }
  }

  return *this;
}

int& IntVector::operator[](const unsigned int index) {
  // Access Violation exception placeholder
  assert(index < elementsCount || index >= 0);
  return array[index];
}

IntVector& IntVector::operator+=(const IntVector& rhs) {
  int i = 0;
  while (i < rhs.elementsCount) {
    this->push_back(rhs.array[i++]);
  }

  return *this;
}

IntVector IntVector::operator+(const IntVector& other) {
  IntVector result = *this;
  result += other;
  return result;
}

bool IntVector::isFull() const {
  return elementsCount >= arraySize;
}

void IntVector::growArray() {
  unsigned int newArraySize = arraySize ? arraySize * 2 : INIT_SIZE;
  int* newArray = new int[newArraySize];

  for (int element_i = 0; element_i < elementsCount; ++element_i) {
    newArray[element_i] = array[element_i];
  }

  delete[] array;
  arraySize = newArraySize;
  array = newArray;
}

unsigned int IntVector::length() const {
  return elementsCount;
}

void IntVector::push_back(const int x) {
  if (isFull()) {
    growArray();
  }

  array[elementsCount] = x;
  ++elementsCount;
}

int IntVector::pop_back() {
  // Underflow behaviour exception placeholder
  assert(elementsCount > 0);

  int topValue = array[elementsCount - 1];
  array[elementsCount - 1] = 0;
  --elementsCount;
  return topValue;
}

int IntVector::find_first(const unsigned int element) const {
  for (int element_i = 0; element_i < elementsCount; ++element_i) {
    if (array[element_i] == element) {
      return element_i;
    }
  }

  return -1;
}

bool IntVector::insert(const unsigned int index, const int element) {
  if (index >= elementsCount || index < 0) {
    // Access Violation
    return false;
  }

  int lastElement = array[elementsCount - 1];
  push_back(lastElement);
  for (unsigned int i = elementsCount - 1; i > index; --i) {
    array[i] = array[i - 1];
  }
  array[index] = element;
  return true;
}

bool IntVector::erase(const unsigned int index) {
  if (index >= elementsCount || index < 0) {
    // Access Violation
    return false;
  }

  for (unsigned int i = index; i < elementsCount - 1; ++i) {
    array[i] = array[i + 1];
  }
  array[elementsCount - 1] = 0;
  --elementsCount;
  return true;
}

void IntVector::clear() {
  delete[] array;
  arraySize = 0;
  elementsCount = 0;
}

bool IntVector::isEmpty() const {
  return elementsCount == 0;
}



