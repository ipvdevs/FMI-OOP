#include <iostream>
#include "StackDynamic.hpp"

int main() {
  StackDynamic stk;
  stk.pop_back();

  std::cout << stk.size() << std::endl;
  stk.push_back(10);
  std::cout << stk.peek() << '\n';
  std::cout << stk.size() << std::endl;
  std::cout << stk.pop_back() << std::endl;
  std::cout << stk.peek() << '\n';
  std::cout << stk.size() << std::endl;

  stk.push_back(1);
  std::cout << stk.peek() << '\n';

  stk.push_back(2);
  std::cout << stk.peek() << '\n';

  stk.push_back(3);
  std::cout << stk.peek() << '\n';

  stk.push_back(4);
  std::cout << stk.peek() << '\n';

  std::cout << stk.size() << std::endl;

  StackDynamic stkCpy;

  stkCpy = stk;

  stk.printElements();
  stkCpy.printElements();
  return 0;
}
