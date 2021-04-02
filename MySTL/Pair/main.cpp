#include "Pair.hpp"
#include <iostream>

int main() {
  Pair<int, std::string> person(1, "Name");
  Pair<int, std::string> anotherPerson(2, "Nombre");

  std::cout << person.getFirstType() << ' ' << person.getSecondType() << '\n';

  swap(person, anotherPerson);

  std::cout << person.getFirstType() << ' ' << person.getSecondType() << '\n';

  std::cout << "Equal: " << (person == anotherPerson ? "true" : "false") << '\n';
  std::cout << "Assignment." << '\n';
  anotherPerson = person;
  std::cout << "Equal: " << (person == anotherPerson ? "true" : "false") << '\n';

  return 0;
}
