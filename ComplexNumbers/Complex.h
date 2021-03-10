
#ifndef COMPLEX_H_
#define COMPLEX_H_

class Complex {

 public:
  //Constructor - takes a real and imaginary part - default values 0.0
  Complex(double realPart = 0.0, double imaginaryPart = 0.0);
  Complex(const Complex &obj);

  //Getters
  double getReal() const { return realPart; };
  double getImaginary() const { return imaginaryPart; };

  void print() const;
  bool isEqualTo(const Complex &) const;
  void addComplex(const Complex &);
  void productComplex(const Complex &);

 private:
  //Representation: a + b*i
  double realPart; //a
  double imaginaryPart; //b
  char imaginaryUnit = 'i'; //i
};

#endif //COMPLEX_H_
