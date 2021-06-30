/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#ifndef EXAM_2021__NAMEDOBJECT_HPP_
#define EXAM_2021__NAMEDOBJECT_HPP_

#include <cstring>

template<class T>
class NamedObject {
 public:
  NamedObject();
  NamedObject(unsigned int id, const char* name);
  NamedObject(const NamedObject& other);
  NamedObject& operator=(const NamedObject& other);
  ~NamedObject();

  void setObject(const T& obj);
  void setName(const char*);

  const char* getName() const;
  unsigned int getId() const;
  T getObject() const;

 private:
  unsigned int id;
  char* name;
  T object;

  void copyFrom(const NamedObject& src);
  void free();
  void changeName(const char*); // Change but does not free
};

template<class T>
NamedObject<T>::NamedObject() : id(0), name(nullptr) {
  object = T();
}

template<class T>
NamedObject<T>::NamedObject(unsigned int id, const char* name) : id(id) {
  changeName(name);
}

template<class T>
NamedObject<T>::NamedObject(const NamedObject& other) {
  copyFrom(other);
}

template<class T>
NamedObject<T>& NamedObject<T>::operator=(const NamedObject& other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

template<class T>
void NamedObject<T>::copyFrom(const NamedObject& src) {
  this->id = src.id;
  this->object = src.object;

  changeName(src.name);
}

template<class T>
void NamedObject<T>::changeName(const char* name) {
  unsigned int len = strlen(name) + 1; // +1 for '\0'
  this->name = new char[len];
  strcpy(this->name, name);
}

template<class T>
void NamedObject<T>::free() {
  this->id = 0;
  delete[] this->name;
}

template<class T>
void NamedObject<T>::setObject(const T& obj) {
  this->object = obj;
}

template<class T>
const char* NamedObject<T>::getName() const {
  return name;
}

template<class T>
unsigned int NamedObject<T>::getId() const {
  return id;
}

template<class T>
T NamedObject<T>::getObject() const {
  return object;
}

template<class T>
void NamedObject<T>::setName(const char* newName) {
  delete[] name;
  changeName(newName);
}

template<class T>
NamedObject<T>::~NamedObject() {
  free();
}

#endif //EXAM_2021__NAMEDOBJECT_HPP_
