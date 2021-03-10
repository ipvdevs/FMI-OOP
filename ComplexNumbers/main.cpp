#include "Complex.h"
#include <iostream>

//Driver for testing ComplexNumbers
int main() {
  //Default constructor
  Complex def;
  def.print();

  //Copy constructor
  Complex oldComplex(3.6, -1.2);
  Complex newComplex(oldComplex);
  newComplex.print();

  //Positive and negative printing
  Complex positive(2.2, 7);
  positive.print();

  Complex negative(3.8, -4);
  negative.print();

  //Add method
  positive.addComplex(negative);
  positive.print();

  Complex imUnit(0, 1);
  imUnit.productComplex(imUnit);
  imUnit.print();

  std::cout << "Equal comparison: \n";
  std::cout << (positive.isEqualTo(negative) == 1 ? "true" : "false") << '\n';
  std::cout << (oldComplex.isEqualTo(newComplex) == 1 ? "true" : "false") << '\n';
  return 0;
}
