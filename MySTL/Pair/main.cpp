#include "Pair.hpp"
#include <iostream>

int main() {
  auto person = Pair<int, std::string>(1, "Name");
  std::cout << person.getFirstType() << ' ' << person.getSecondType() << std::endl;
  auto swapped = person.swapPairTypes();
  std::cout << swapped.getFirstType() << ' ' << swapped.getSecondType() << std::endl;

  return 0;
}
