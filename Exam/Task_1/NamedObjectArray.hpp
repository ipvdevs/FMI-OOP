/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#ifndef EXAM_2021__NAMEDOBJECTARRAY_HPP_
#define EXAM_2021__NAMEDOBJECTARRAY_HPP_

#include "NamedObject.hpp"

#include <stdexcept>

#define INIT_CAPACITY 10

template<class T>
class NamedObjectArray {
 public:
  NamedObjectArray();
  NamedObjectArray(const NamedObjectArray<T>&);
  NamedObjectArray& operator=(const NamedObjectArray<T>& other);
  ~NamedObjectArray();

  void addNamedObject(NamedObject<T>&);
  unsigned int size() const;
  NamedObject<T> operator[](int index) const;

 private:
  NamedObject<T>* array;
  unsigned int count = 0;
  unsigned int capacity = INIT_CAPACITY;

  void copyFrom(const NamedObjectArray<T>& src);
  void free();
  void grow();
};

template<class T>
NamedObjectArray<T>::NamedObjectArray() : capacity(INIT_CAPACITY) {
  array = new NamedObject<T>[INIT_CAPACITY];
}

template<class T>
NamedObjectArray<T>::NamedObjectArray(const NamedObjectArray<T>& other) {
  copyFrom(other);
}

template<class T>
NamedObjectArray<T>& NamedObjectArray<T>::operator=(const NamedObjectArray<T>& other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

template<class T>
NamedObjectArray<T>::~NamedObjectArray() {
  free();
}

template<class T>
void NamedObjectArray<T>::copyFrom(const NamedObjectArray<T>& src) {
  this->count = src.count;
  this->capacity = src.capacity;

  for (int i = 0; i < count; ++i) {
    this->array[i] = src[i];
  }
}

template<class T>
void NamedObjectArray<T>::free() {
  this->count = 0;
  this->capacity = 0;
  delete[] array;
}

template<class T>
void NamedObjectArray<T>::addNamedObject(NamedObject<T>& object) {
  if (count + 1 >= capacity) {
    grow();
  }

  this->array[count] = object;
  ++count;
}

template<class T>
void NamedObjectArray<T>::grow() {
  unsigned int newCapacity = 2 * capacity;
  auto* reserve = new NamedObject<T>[newCapacity];

  for (int i = 0; i < count; ++i) {
    reserve[i] = array[i];
  }

  delete[] array;
  capacity = newCapacity;
  array = reserve;
}

template<class T>
unsigned int NamedObjectArray<T>::size() const {
  return count;
}

template<class T>
NamedObject<T> NamedObjectArray<T>::operator[](const int index) const {
  if (index < 0 || index >= count) {
    throw std::out_of_range("Out of range");
  }

  return array[index];
}

#endif //EXAM_2021__NAMEDOBJECTARRAY_HPP_
