#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double realPart, double imaginaryPart)
    : realPart(realPart), imaginaryPart(imaginaryPart) {}

ComplexNumber::ComplexNumber(const ComplexNumber &other) {
  this->realPart = other.realPart;
  this->imaginaryPart = other.imaginaryPart;
}

double ComplexNumber::getRealPart() const {
  return this->realPart;
}

double ComplexNumber::getImaginaryPart() const {
  return this->imaginaryPart;
}

ComplexNumber &ComplexNumber::operator=(const ComplexNumber &other) {
  if (this != &other) {
    this->realPart = other.realPart;
    this->imaginaryPart = other.imaginaryPart;
  }
  return *this;
}

bool ComplexNumber::operator==(const ComplexNumber &other) const {
  return (realPart == other.realPart) && (imaginaryPart == other.imaginaryPart);
}

ComplexNumber &ComplexNumber::operator+=(const ComplexNumber &other) {
  this->realPart += other.realPart;
  this->imaginaryPart += other.imaginaryPart;
  return *this;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &other) const {
  ComplexNumber result = *this;
  result += other;
  return result;
}

ComplexNumber &ComplexNumber::operator*=(const ComplexNumber &other) {
  // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
  double a = this->realPart, b = this->imaginaryPart;
  double c = other.realPart, d = other.imaginaryPart;
  this->realPart = (a * c - b * d);
  this->imaginaryPart = (a * d + b * c);
  return *this;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &other) const {
  ComplexNumber result = *this;
  result *= other;
  return result;
}

void ComplexNumber::print() const {
  // Print only the real part (imaginary might be equal to zero)
  std::cout << realPart;
  if (this->imaginaryPart > 0) {
    std::cout << " + " << imaginaryPart << IMAGINARY_UNIT;
  } else if (this->imaginaryPart < 0) {
    std::cout << " - " << -imaginaryPart << IMAGINARY_UNIT;
  }
  std::cout << std::endl;
}

void ComplexNumber::conjugateComplex() {
  this->imaginaryPart *= -1;
}









