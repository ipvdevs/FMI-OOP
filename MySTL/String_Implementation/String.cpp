#include <iostream>
#include "String.hpp"

String::String() : array(new char[1]), arraySize(1) {
  array[0] = '\0';
}

String::String(const char *str) : array(nullptr), arraySize(0) {
  setStr(str);
}

String::String(const String &other) : array(nullptr), arraySize(0) {
  setStr(other.array);
}

String &String::operator=(const String &other) {
  if (this != &other) {
    delete[] array;
    setStr(other.array);
  }
  return *this;
}

String::~String() {
  delete[] array;
}

char &String::operator[](unsigned int index) {
  return array[index];
}

String String::operator+(const String &other) const {
  String result = *this;
  result += other;
  return result;
}

String &String::operator+=(const String &other) {
  // Expanding the size of current array storage for string
  // Both sizes include NULL. Therefore we subtract 1.
  arraySize = arraySize + other.arraySize - 1;
  char *buffer = new char[arraySize];
  strCopy(array, buffer, arraySize - other.arraySize + 1);

  delete[] array;

  // s - index for string, o - index for other string
  for (unsigned int s = strLength(buffer), o = 0; s < arraySize - 1; ++s, ++o) {
    buffer[s] = other.array[o];
  }
  buffer[arraySize - 1] = '\0';

  array = buffer;

  return *this;
}

bool String::operator==(const String &other) const {
  return strComparator(array, other.array) == 0;
}

bool String::operator!=(const String &other) const {
  return strComparator(array, other.array) != 0;
}

bool String::operator<(const String &other) const {
  return strComparator(array, other.array) < 0;
}

bool String::operator>(const String &other) const {
  return strComparator(array, other.array) > 0;
}

bool String::operator<=(const String &other) const {
  return strComparator(array, other.array) <= 0;
}

bool String::operator>=(const String &other) const {
  return strComparator(array, other.array) >= 0;
}

std::ostream &operator<<(std::ostream &output, const String &str) {
  output << str.cString();
  return output;
}

std::istream &operator>>(std::istream &input, String &str) {
  char ch;
  while ((ch = input.get()) && (!String::isCharTerminating(ch))) {
    str.append_char(ch);
  }
  return input;
}

unsigned int String::length() const {
  return arraySize - 1;
}

void String::append_char(char ch) {
  // Add +1 memory space for ch
  unsigned int newSize = arraySize + 1;
  char *buffer = new char[newSize];
  strCopy(array, buffer, newSize - 1);
  buffer[newSize - 2] = ch;
  buffer[newSize - 1] = '\0';
  delete[] array;
  array = buffer;
  arraySize = newSize;
}

void String::setStr(const char *str) {
  arraySize = strLength(str) + 1;
  array = new char[arraySize];
  strCopy(str, array, arraySize);
}

bool String::isEmpty() const {
  return (arraySize == 1);
}

void String::clear() {
  delete[] array;
  array = new char[1]{'\0'};
  arraySize = 1;
}

const char *String::cString() const {
  return array;
}

void String::strCopy(const char *src, char *dest, const unsigned int destLength) {
  if (src == nullptr) {
    // Exception placeholder
    return;
  }

  for (int char_i = 0; char_i < destLength - 1; ++char_i) {
    dest[char_i] = src[char_i];
  }
  dest[destLength - 1] = '\0';
}

unsigned int String::strLength(const char *src) {
  if (src == nullptr) {
    // Exception placeholder
    return 0;
  }
  unsigned length = 0;
  while (src[length] != '\0') {
    ++length;
  }
  return length;
}

/* Two strings are lexicographically equal if they are
 * the same length and contain the same characters in the same positions.
 * If both strings are lexicographically same result is 0.
 * Otherwise result would be a positive or negative number
 * depending on the lexicographical order
*/
int String::strComparator(const char *str1, const char *str2) {
  while ((*str1 != '\0' && *str2 != '\0') && (*str1 == *str2)) {
    ++str1;
    ++str2;
  }

  return *str1 - *str2;
}

bool String::isCharTerminating(const char &ch) {
  return ch == '\n' || ch == '\r' || ch == ' ' || ch == '\t';
}



