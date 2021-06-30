#include "VendingMachine.hpp"

VendingMachine::VendingMachine()
    : drinks(nullptr), drinksCount(0), capacity(0), income(0.0) {}

VendingMachine::VendingMachine(const VendingMachine &from) {
  this->capacity = from.capacity;
  this->drinksCount = from.drinksCount;
  this->income = from.income;

  this->drinks = new Drink[capacity];
  for (int i = 0; i < drinksCount; ++i) {
    drinks[i] = from.drinks[i];
  }
}

VendingMachine &VendingMachine::operator=(const VendingMachine &from) {
  if (&from != this) {
    this->capacity = from.capacity;
    this->drinksCount = from.drinksCount;
    this->income = from.income;

    delete[] this->drinks;
    this->drinks = new Drink[capacity];

    for (int i = 0; i < drinksCount; ++i) {
      drinks[i] = from.drinks[i];
    }
  }

  return *this;
}

VendingMachine::~VendingMachine() {
  delete[] this->drinks;
}

double VendingMachine::get_income() const {
  return this->income;
}

bool VendingMachine::add_drink(const Drink &to_add) {
  bool isCapacityEnough = this->capacity > drinksCount;
  if (!isCapacityEnough) {
    ExpandCapacity();
  }

  if (findDrinkByName(to_add.get_name()) != -1) {
    // This drink has already been added
    return false;
  }

  this->drinks[drinksCount] = to_add;
  ++drinksCount;

  return true;
}

void VendingMachine::remove_drink(const char *drink_name) {
  int drinkIndex = findDrinkByName(drink_name);
  if (drinkIndex == -1) {
    // Error placeholder - cannot remove drink that don't exist
    return;
  }

  // Shift left
  for (int i = drinkIndex; i < this->drinksCount - 1; ++i) {
    drinks[i] = drinks[i + 1];
  }
  drinks[drinksCount - 1] = Drink();

  --(this->drinksCount);
}

int VendingMachine::buy_drink(const char *drink_name, const double money) {
  int drinkIndex = findDrinkByName(drink_name);
  if (drinkIndex == -1) {
    return DRINK_NOT_FOUND;
  }

  this->income += money;

  bool moneyEnough = money >= this->drinks[drinkIndex].get_price();
  if (moneyEnough) {
    remove_drink(drink_name);
    return BOUGHT_SUCCESSFULLY;
  }

  return NOT_ENOUGH_MONEY;
}

// Return drink index if found and -1 otherwise
int VendingMachine::findDrinkByName(const char *drinkName) const {
  int index = 0;
  while (index < this->drinksCount) {
    bool areDrinkNamesSame = strCompare(drinks[index].get_name(), drinkName) == 0;
    if (areDrinkNamesSame) {
      return index;
    }
    ++index;
  }

  return -1;
}

void VendingMachine::ExpandCapacity() {
  unsigned int newCapacity = (capacity > 0) ? 2 * capacity : INIT_CAPACITY;
  Drink *tempStorage = new Drink[newCapacity];

  for (int i = 0; i < this->capacity; ++i) {
    tempStorage[i] = this->drinks[i];
  }

  delete[] this->drinks;
  this->drinks = new Drink[newCapacity];

  for (int i = 0; i < this->capacity; ++i) {
    this->drinks[i] = tempStorage[i];
  }

  this->capacity = newCapacity;

  delete[] tempStorage;
}

