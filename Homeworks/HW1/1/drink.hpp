#ifndef VENDINGMACHINE__DRINK_HPP_
#define VENDINGMACHINE__DRINK_HPP_

// Used for cstrings length and copy operations
#include "StrUtils.hpp"

class Drink {
 public:
  Drink();
  Drink(const char *init_name, const int init_calories, const double &init_quantity, const double &init_price);
  Drink(const Drink &);
  Drink &operator=(const Drink &);
  ~Drink();

  const char *get_name() const;
  int get_calories() const;
  double get_quantity() const;
  double get_price() const;

  void set_name(const char *new_name);

 private:
  char *name;
  int calories;
  double liters;
  double price;
};

#endif // VENDINGMACHINE__DRINK_HPP_