#ifndef STRING_HPP_
#define STRING_HPP_

class String {
 public:
  String();
  String(const char *);
  String(const String &);
  String &operator=(const String &);
  ~String();

  char &operator[](unsigned int index);
  String operator+(const String &) const;
  String &operator+=(const String &);
  bool operator==(const String &) const;
  bool operator!=(const String &) const;
  bool operator<(const String &) const;
  bool operator>(const String &) const;
  bool operator<=(const String &) const;
  bool operator>=(const String &) const;

  friend std::ostream &operator<<(std::ostream &, const String &);
  friend std::istream &operator>>(std::istream &, String &);

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
  static bool isCharTerminating(const char &ch);
};

#endif //STRING_HPP_
