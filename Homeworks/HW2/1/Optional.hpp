#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

template<typename T>
class Optional {
 public:
  Optional();
  Optional(const T& value);

  bool is_none() const;
  T get_value() const;

 public:
  T value_type;
  bool none;
};

template<typename T>
Optional<T>::Optional()
    : none(true), value_type() {}

template<typename T>
Optional<T>::Optional(const T& value)
    : none(false), value_type(value) {}

template<typename T>
bool Optional<T>::is_none() const {
  return none;
}

template<typename T>
T Optional<T>::get_value() const {
  return value_type;
}

