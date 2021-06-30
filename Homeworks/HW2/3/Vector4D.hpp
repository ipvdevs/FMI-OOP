#pragma once

#define SIZE 4

class Vector4D {

 public:
  Vector4D();
  Vector4D(double, double, double, double);

  double& operator[](int index);
  Vector4D operator+(const Vector4D&) const;
  Vector4D& operator+=(const Vector4D&);

  Vector4D operator-(const Vector4D&) const;
  Vector4D& operator-=(const Vector4D&);

  Vector4D operator*(double) const;
  Vector4D& operator*=(double);

  Vector4D operator*(const Vector4D&) const;
  Vector4D& operator*=(const Vector4D&);

  Vector4D operator/(const Vector4D&) const;
  Vector4D& operator/=(const Vector4D&);

  bool operator==(const Vector4D&) const;
  bool operator!=(const Vector4D&) const;

  bool operator<(const Vector4D&) const;
  bool operator>(const Vector4D&) const;

  bool operator>=(const Vector4D&) const;
  bool operator<=(const Vector4D&) const;

  bool operator!() const;
  Vector4D operator-() const;

 private:
  double vector4D[SIZE];
};