#include "ComplexNumber.h"
#include <iostream>

int main() {
  // Some Samples
  ComplexNumber z = ComplexNumber(1, 2);
  ComplexNumber zOther(2, 1);
  zOther.print();
  std::cout << ((z == zOther) ? "Equal" : "Not Equal") << std::endl;
  ComplexNumber zSum = z + zOther;
  ComplexNumber zProduct = z * zOther;
  zSum.print();
  zProduct.print();
  ComplexNumber imUnit(0, 1);
  imUnit.print();
  imUnit *= imUnit;
  imUnit.print();
  ComplexNumber Sample(1, 9);
  Sample.conjugateComplex();
  Sample.print();

  return 0;
}
