#include "Complex.h"
#include <iostream>

Complex::Complex(double re, double im) : realPart(re), imaginaryPart(im) {};

/* void Complex::makeComplex(const double real, const double imaginary)
/ {
/     this->real = real;
/     this->imaginary = imaginary;
/ }
*/

Complex::Complex(const Complex &complexNum) {
  this->realPart = complexNum.realPart;
  this->imaginaryPart = complexNum.imaginaryPart;
}

void Complex::print() const {
  // Print only the real part (imaginary might be equal to zero)
  std::cout << realPart;
  if (this->imaginaryPart > 0) {
    std::cout << " + " << imaginaryPart << imaginaryUnit;
  } else if (this->imaginaryPart < 0) {
    std::cout << " - " << -imaginaryPart << imaginaryUnit;
  }
  std::cout << std::endl;
};

bool Complex::isEqualTo(const Complex &other) const {
  return (this->realPart == other.realPart) && (this->imaginaryPart == other.imaginaryPart);
}

void Complex::conjugateComplex(){
  this->imaginaryPart *= -1;
}

// Add another number to the current one
void Complex::addComplexTo(const Complex &other) {
  this->realPart += other.realPart;
  this->imaginaryPart += other.imaginaryPart;
}

void Complex::multiplyComplexTo(const Complex &other) {
  // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
  double a = this->realPart, b = this->imaginaryPart;
  double c = other.realPart, d = other.imaginaryPart;
  this->realPart = (a * c - b * d);
  this->imaginaryPart = (a * d + b * c);
}
