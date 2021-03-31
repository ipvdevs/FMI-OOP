#include <iostream>
#include "IntVector.hpp"

int main() {
  IntVector sample;

  sample.push_back(1);
  sample.push_back(2);
  sample.push_back(3);

  for (int i = 0; i < sample.length(); ++i) {
    std::cout << sample[i] << ' ';
  }
  std::cout << std::endl;
  std::cout << "Is successful: " << (sample.erase(-1) ? "Yes" : "No") << '\n';

  for (int i = 0; i < sample.length(); ++i) {
    std::cout << sample[i] << ' ';
  }
  std::cout << std::endl;

  std::cout << sample.length() << '\n';
  return 0;
}
