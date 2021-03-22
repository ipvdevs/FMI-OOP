#include <iostream>
#include "IntStack.h"

using namespace std;

int main() {
  IntStack stack(3);
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.printElements();
  std::cout << "Elements count: " << stack.elementsCount() << '\n';
  std::cout << "Top (peek): " << stack.peek() << '\n';
  std::cout << "Try push another (stack is full):" << '\n';
  stack.push(4);
  std::cout << "Pop: " << stack.pop() << '\n';
  std::cout << "Elements after pop:" << '\n';
  stack.printElements();

  std::cout << "Predefined assignment operator (stack copy):" << '\n';
  IntStack operatorStackCpy = stack;
  operatorStackCpy.printElements();

  return 0;
}
