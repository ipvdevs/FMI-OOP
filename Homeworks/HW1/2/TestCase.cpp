#include "TestCase.hpp"

TestCase::TestCase(const std::string &name, const Error &error) {
  this->name = name;
  this->error = error;
}

std::string TestCase::getName() const {
  return this->name;
}

bool TestCase::isPassing() const {
  return this->error.getType() == ErrorType::None
      || this->error.getType() == ErrorType::Warning;
}

bool TestCase::hasError() const {
  return this->error.getType() != ErrorType::None;
}

ErrorType TestCase::getErrorType() const {
  return this->error.getType();
}

std::string TestCase::getErrorMessage() const {
  return this->error.getMessage();
}

