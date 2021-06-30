#include "VendingMachine.hpp"
#include <iostream>

int main() {
  VendingMachine coffeeMachine;
  // Try to remove drink that is not available
  coffeeMachine.remove_drink("Coffee");
  // Try to buy drink that is not available
  std::cout << coffeeMachine.buy_drink("Coffee", 1.50) << '\n'; // 2
  std::cout << coffeeMachine.get_income() << '\n'; //0
  coffeeMachine.add_drink(Drink("Cappuccino", 180, 0.120, 1.60));
  std::cout << coffeeMachine.buy_drink("Coffee", 1.50) << '\n'; // 2
  std::cout << coffeeMachine.buy_drink("Cappuccino", 1.50) << '\n'; // 1
  std::cout << coffeeMachine.get_income() << '\n'; //1.50
  std::cout << coffeeMachine.buy_drink("Cappuccino", 1.60) << '\n'; // 0
  std::cout << coffeeMachine.get_income() << '\n'; //3.10


  return 0;
}
