#ifndef VECTOR__VECTOR_HPP_
#define VECTOR__VECTOR_HPP_

#include "cassert"

#define INIT_SIZE 10

template<typename T>
class Vector {
 public:
  Vector();
  Vector(const Vector& other);
  ~Vector();

  Vector& operator=(const Vector& other);
  T& operator[](unsigned int);
  Vector& operator+=(const Vector& rhs);
  Vector operator+(const Vector& other);

  unsigned int length() const;
  void push_back(const T& element);
  int pop_back();
  int find_first(const T& element) const;
  bool insert(unsigned int index, const T& element);
  bool erase(unsigned int index);
  bool isEmpty() const;
  void clear();

 private:
  T* array;
  unsigned int elementsCount;
  unsigned int arraySize;

  bool isFull() const;
  void growArray();
};

template<typename T>
Vector<T>::Vector() {
  array = nullptr;
  elementsCount = 0;
  arraySize = 0;
}

template<typename T>
Vector<T>::Vector(const Vector& other)
    : elementsCount(0), arraySize(0) {
  this->arraySize = other.arraySize;
  this->elementsCount = other.elementsCount;
  this->array = new T[arraySize];
  for (int element_i = 0; element_i < elementsCount; ++element_i) {
    this->array[element_i] = other.array[element_i];
  }
}

template<typename T>
Vector<T>::~Vector() {
  delete[] array;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
  if (this != &other) {
    this->arraySize = other.arraySize;
    this->elementsCount = other.elementsCount;

    delete[] array;
    this->array = new T[arraySize];
    for (int element_i = 0; element_i < elementsCount; ++element_i) {
      this->array[element_i] = other.array[element_i];
    }
  }

  return *this;
}

template<typename T>
T& Vector<T>::operator[](const unsigned int index) {
  // Access Violation exception placeholder
  assert(index < elementsCount || index >= 0);
  return array[index];
}

template<typename T>
Vector<T>& Vector<T>::operator+=(const Vector& rhs) {
  int i = 0;
  while (i < rhs.elementsCount) {
    this->push_back(rhs.array[i++]);
  }

  return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector& other) {
  Vector result = *this;
  result += other;
  return result;
}

template<typename T>
bool Vector<T>::isFull() const {
  return elementsCount >= arraySize;
}

template<typename T>
void Vector<T>::growArray() {
  unsigned int newArraySize = arraySize ? arraySize * 2 : INIT_SIZE;
  T* newArray = new T[newArraySize];

  for (int element_i = 0; element_i < elementsCount; ++element_i) {
    newArray[element_i] = array[element_i];
  }

  delete[] array;
  arraySize = newArraySize;
  array = newArray;
}

template<typename T>
unsigned int Vector<T>::length() const {
  return elementsCount;
}

template<typename T>
void Vector<T>::push_back(const T& element) {
  if (isFull()) {
    growArray();
  }

  array[elementsCount] = element;
  ++elementsCount;
}

template<typename T>
int Vector<T>::pop_back() {
  // Underflow behaviour exception placeholder
  assert(elementsCount > 0);

  T topValue = array[elementsCount - 1];
  array[elementsCount - 1] = 0;
  --elementsCount;
  return topValue;
}

template<typename T>
int Vector<T>::find_first(const T& element) const {
  for (int element_i = 0; element_i < elementsCount; ++element_i) {
    if (array[element_i] == element) {
      return element_i;
    }
  }

  return -1;
}

template<typename T>
bool Vector<T>::insert(const unsigned int index, const T& element) {
  if (index >= elementsCount || index < 0) {
    // Access Violation
    return false;
  }

  T lastElement = array[elementsCount - 1];
  push_back(lastElement);
  for (unsigned int i = elementsCount - 1; i > index; --i) {
    array[i] = array[i - 1];
  }
  array[index] = element;
  return true;
}

template<typename T>
bool Vector<T>::erase(const unsigned int index) {
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

template<typename T>
void Vector<T>::clear() {
  delete[] array;
  this->array = new T[INIT_SIZE];
  arraySize = 0;
  elementsCount = 0;
}

template<typename T>
bool Vector<T>::isEmpty() const {
  return elementsCount == 0;
}

#endif //VECTOR__VECTOR_HPP_
