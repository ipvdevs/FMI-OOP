#include <iostream>
#include "String.hpp"

void sample() {
  String example = "Test Str";
  std::cout << example;
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
  std::cout << example << " - " << "length: " << example.length() << '\n';
  example = "End";
  std::cout << example << std::endl;
}

int main() {

  // Show sample class functionality
  sample();

  return 0;
}
