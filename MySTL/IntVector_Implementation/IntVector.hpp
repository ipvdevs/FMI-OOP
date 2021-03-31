#ifndef VECTOR__INTVECTOR_HPP_
#define VECTOR__INTVECTOR_HPP_

#include "cassert"

#define INIT_SIZE 10

class IntVector {
 public:
  IntVector();
  IntVector(const IntVector& other);
  ~IntVector();

  IntVector& operator=(const IntVector& other);
  int& operator[](unsigned int);
  IntVector& operator+=(const IntVector& rhs);
  IntVector operator+(const IntVector& other);

  unsigned int length() const;
  void push_back(int element);
  int pop_back();
  int find_first(unsigned int element) const;
  bool insert(unsigned int index, int element);
  bool erase(unsigned int index);
  bool isEmpty() const;
  void clear();

 private:
  int* array;
  unsigned int elementsCount;
  unsigned int arraySize;

  bool isFull() const;
  void growArray();
};

#endif //VECTOR__INTVECTOR_HPP_
