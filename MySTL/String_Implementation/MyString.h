#ifndef MYSTRING_H_
#define MYSTRING_H_

class MyString {
 public:
  MyString();
  MyString(const char *);
  MyString(const MyString &);
  MyString &operator=(const MyString &);
  ~MyString();

  char &operator[](unsigned int index);
  MyString operator+(const MyString &) const;
  MyString &operator+=(const MyString &);
  bool operator==(const MyString &) const;
  bool operator!=(const MyString &) const;
  bool operator<(const MyString &) const;
  bool operator>(const MyString &) const;
  bool operator<=(const MyString &) const;
  bool operator>=(const MyString &) const;

  unsigned int length() const;
  void append_char(char);
  bool isEmpty() const;
  void clear();
  const char *cString() const;

 private:
  char *array;
  unsigned int arraySize;

  void setStr(const char *str);

  // Useful utilities
  static int strComparator(const char *str1, const char *str2);
  static void strCopy(const char *src, char *dest, unsigned int destLength);
  static unsigned int strLength(const char *src);
};

#endif //MYSTRING_H_
