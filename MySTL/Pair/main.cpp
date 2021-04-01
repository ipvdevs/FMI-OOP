#include "Pair.hpp"
#include <iostream>

int main() {
  Pair<int, std::string> person(1, "Name");
  Pair<int, std::string> anotherPerson(2, "Nombre");

  std::cout << person.getFirstType() << '\n';
  std::cout << person.getSecondType() << '\n';

  std::cout << (person == anotherPerson) << '\n';
  anotherPerson = person;
  std::cout << (person == anotherPerson) << '\n';

  return 0;
}
