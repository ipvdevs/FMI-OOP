#include <iostream>
#include "Vector.hpp"

template<typename T>
void SampleWithNumbers(Vector<T>& sample) {

  // Implicit cast if it's double
  sample.push_back(1.3);
  sample.push_back(2);
  sample.push_back(3);

  for (int i = 0; i < sample.length(); ++i) {
    std::cout << sample[i] << ' ';
  }
  std::cout << std::endl;
  std::cout << "Is successful: " << (sample.erase(-1) ? "Yes" : "No") << '\n';

  for (int i = 0; i < sample.length(); ++i) {
    std::cout << sample[i] << ' ';
  }
  std::cout << std::endl;

  std::cout << sample.length() << '\n';
}

int main() {
  Vector<int> intVector;
  SampleWithNumbers(intVector);

  std::cout << std::endl;

  Vector<double> doubleVector;
  SampleWithNumbers(doubleVector);
  return 0;
}
