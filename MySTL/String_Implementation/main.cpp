#include <iostream>
#include "MyString.h"

int main() {
  MyString example = "Test Str";
  std::cout << example.cString() << '\n';
  std::cout << "Length: ";
  std::cout << example.length() << '\n';
  std::cout << "Is empty: ";
  std::cout << (example.isEmpty() ? "true" : "false") << '\n';
  example.clear();
  std::cout << "Is empty (after clear): ";
  std::cout << (example.isEmpty() ? "true" : "false") << '\n';
  std::cout << "Length: ";
  std::cout << example.length() << '\n';
  example.append_char('@');
  std::cout << example.cString() << " - " << "length: " << example.length() << '\n';
  example = "End";
  std::cout << example.cString() << std::endl;
  return 0;
}
