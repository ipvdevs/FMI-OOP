#ifndef VENDINGMACHINE__VENDINGMACHINE_HPP_
#define VENDINGMACHINE__VENDINGMACHINE_HPP_

#include "drink.hpp"
#define INIT_CAPACITY 1

class VendingMachine {
 public:
  VendingMachine();
  VendingMachine(const VendingMachine &from);
  VendingMachine &operator=(const VendingMachine &from);
  ~VendingMachine();

  bool add_drink(const Drink &to_add);
  void remove_drink(const char *drink_name);
  int buy_drink(const char *drink_name, const double money);

  double get_income() const;

 private:
  Drink *drinks;
  unsigned int drinksCount;
  unsigned int capacity;
  double income;

  enum BUY_CODES {
    BOUGHT_SUCCESSFULLY = 0,
    NOT_ENOUGH_MONEY = 1,
    DRINK_NOT_FOUND = 2
  };

  int findDrinkByName(const char *) const;
  void ExpandCapacity();
};

#endif //VENDINGMACHINE__VENDINGMACHINE_HPP_


