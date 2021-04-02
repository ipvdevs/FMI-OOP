#include <iostream>
#include "Stack.hpp"

int main() {
  Stack<int> sample;
  sample.push_back(1);
  sample.push_back(2);
  sample.push_back(3);
  Stack<int> sampleCpy = sample;

  while (sampleCpy.size() > 0) {
    std::cout << sampleCpy.pop_back() << '\n';
  }

  Stack<std::string> names;
  names.push_back("Ivan");
  names.push_back("George");
  names.push_back("Peter");

  std::cout << names.size() << '\n';

  std::cout << names.peek() << '\n';

  while (!names.isEmpty()) {
    std::cout << names.pop_back() << '\n';
  }

  return 0;
}
