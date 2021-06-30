#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name)
    : name(name) {}

void TestSuite::add(const TestCase &test) {
  tests.push_back(test);
}

std::vector<TestCase> TestSuite::filterPassing() const {
  std::vector<TestCase> passingTests;

  unsigned int totalTests = this->tests.size();
  for (unsigned int i = 0; i < totalTests; ++i) {
    if (this->tests[i].isPassing()) {
      passingTests.push_back(this->tests[i]);
    }
  }

  return passingTests;
}

std::vector<TestCase> TestSuite::filterFailing() const {
  std::vector<TestCase> failingTests;

  unsigned int totalTests = this->tests.size();
  for (unsigned int i = 0; i < totalTests; ++i) {
    if (!(this->tests[i].isPassing())) {
      failingTests.push_back(this->tests[i]);
    }
  }

  return failingTests;
}
std::vector<TestCase> TestSuite::filterByErrorType(ErrorType error) const {
  std::vector<TestCase> filteredByError;

  unsigned int totalTests = this->tests.size();
  for (unsigned int i = 0; i < totalTests; ++i) {
    if (this->tests[i].getErrorType() == error) {
      filteredByError.push_back(this->tests[i]);
    }
  }

  return filteredByError;
}

void TestSuite::removeByErrorType(ErrorType error) {
  for (unsigned int i = 0; i < this->tests.size(); ++i) {
    if (this->tests[i].getErrorType() == error) {
      this->tests.erase(tests.begin() + i);
    }
  }
}

std::string TestSuite::getName() const {
  return this->name;
}

void TestSuite::setName(const std::string &nameToSet) {
  this->name = nameToSet;
}


