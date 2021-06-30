#include "drink.hpp"

Drink::Drink()
    : name(nullptr), calories(0), price(0.0), liters(0.0) {}

Drink::Drink(const char *init_name, const int init_calories, const double &init_quantity, const double &init_price)
    : name(nullptr), calories(init_calories), liters(init_quantity), price(init_price) {
  set_name(init_name);
}

Drink::Drink(const Drink &other) {
  this->price = other.price;
  this->liters = other.liters;
  this->calories = other.calories;

  this->name = nullptr;
  set_name(other.name);
}

Drink &Drink::operator=(const Drink &other) {
  if (this != &other) {
    this->price = other.price;
    this->liters = other.liters;
    this->calories = other.calories;

    delete[] name;
    set_name(other.name);
  }

  return *this;
}

Drink::~Drink() {
  delete[] name;
}

const char *Drink::get_name() const {
  return this->name;
}

int Drink::get_calories() const {
  return this->calories;
}

double Drink::get_quantity() const {
  return this->liters;
}

double Drink::get_price() const {
  return this->price;
}

void Drink::set_name(const char *new_name) {
  unsigned int nameSize = getStrLength(new_name);
  // Provide +1 space for terminating null
  this->name = new char[nameSize + 1];
  strCopy(new_name, name);
}

