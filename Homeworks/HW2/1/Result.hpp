#pragma once

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>
class Result {
 public:
  Result();
  Result(const T& result);
  Result(const std::string& error_message);

  bool operator==(const T&);
  bool operator==(const Error&);

  Optional<T> get_result() const;
  Optional<Error> get_error() const;

 private:
  T result;
  std::string error_message;
  bool is_error;
};

template<typename T>
Result<T>::Result()
    : result(), error_message(), is_error(true) {}

template<typename T>
Result<T>::Result(const T& result)
    : result(result), error_message(), is_error(false) {}

template<typename T>
Result<T>::Result(const std::string& error_message)
    : result(), error_message(error_message), is_error(true) {}

template<typename T>
bool Result<T>::operator==(const T&) {
  return !is_error;
}

template<typename T>
bool Result<T>::operator==(const Error&) {
  return is_error;
}

template<typename T>
Optional<T> Result<T>::get_result() const {
  return Optional<T>(result);
}

template<typename T>
Optional<Error> Result<T>::get_error() const {
  return Optional<Error>(error_message);
}


