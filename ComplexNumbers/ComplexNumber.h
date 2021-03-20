#ifndef COMPLEXNUMBER_H_GUARD
#define COMPLEXNUMBER_H_GUARD

#include <iostream>
#define IMAGINARY_UNIT 'i'

class ComplexNumber {
 public:
  ComplexNumber(double realPart = 0.0, double imaginaryPart = 0.0);
  ComplexNumber(const ComplexNumber &);

  double getRealPart() const;
  double getImaginaryPart() const;

  ComplexNumber &operator=(const ComplexNumber &);
  bool operator==(const ComplexNumber &) const;
  ComplexNumber &operator+=(const ComplexNumber &);
  ComplexNumber operator+(const ComplexNumber &) const;
  ComplexNumber &operator*=(const ComplexNumber &);
  ComplexNumber operator*(const ComplexNumber &) const;

  void print() const;
  void conjugateComplex();

 private:
  double realPart;
  double imaginaryPart;
};

#endif //COMPLEXNUMBER_H_GUARD
