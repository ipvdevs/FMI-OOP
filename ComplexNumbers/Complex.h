
#ifndef COMPLEX_H_GUARD
#define COMPLEX_H_GUARD

class Complex {

 public:
  // Constructor - takes a real and imaginary part - default values 0.0
  Complex(double realPart = 0.0, double imaginaryPart = 0.0);
  Complex(const Complex &);

  // Getters
  double getReal() const { return realPart; };
  double getImaginary() const { return imaginaryPart; };

  void print() const;
  bool isEqualTo(const Complex &) const;
  void conjugateComplex();
  void addComplexTo(const Complex &);
  void multiplyComplexTo(const Complex &);
  

 private:
  // Representation: a + b*i
  double realPart; // a
  double imaginaryPart; // b
  char imaginaryUnit = 'i';
};

#endif //COMPLEX_H_GUARD
