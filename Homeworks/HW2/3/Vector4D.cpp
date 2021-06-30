#include "Vector4D.hpp"

Vector4D::Vector4D() {
  for (double& element : vector4D) {
    element = 0;
  }
}

Vector4D::Vector4D(double a, double b, double c, double d)
    : vector4D{a, b, c, d} {}

double& Vector4D::operator[](const int index) {
  if (index < 0 || index > SIZE - 1) {
    // Exception - index out of bound - Basic exception safety
    return vector4D[0];
  }

  return vector4D[index];
}

Vector4D& Vector4D::operator+=(const Vector4D& other) {
  for (int i = 0; i < SIZE; ++i) {
    this->vector4D[i] += other.vector4D[i];
  }

  return *this;
}

Vector4D Vector4D::operator+(const Vector4D& other) const {
  Vector4D result(*this);
  result += other;
  return result;
}

Vector4D& Vector4D::operator-=(const Vector4D& other) {
  for (int i = 0; i < SIZE; ++i) {
    this->vector4D[i] -= other.vector4D[i];
  }

  return *this;
}

Vector4D Vector4D::operator-(const Vector4D& other) const {
  Vector4D result(*this);
  result -= other;
  return result;
}

Vector4D& Vector4D::operator*=(const double scalar) {
  for (double& element : this->vector4D) {
    element *= scalar;
  }

  return *this;
}

Vector4D Vector4D::operator*(const double scalar) const {
  Vector4D result(*this);
  result *= scalar;
  return result;
}

Vector4D& Vector4D::operator*=(const Vector4D& other) {
  for (int i = 0; i < SIZE; ++i) {
    this->vector4D[i] *= other.vector4D[i];
  }

  return *this;
}

Vector4D Vector4D::operator*(const Vector4D& other) const {
  Vector4D result(*this);
  result *= other;
  return result;
}

Vector4D& Vector4D::operator/=(const Vector4D& other) {
  for (int i = 0; i < SIZE; ++i) {
    this->vector4D[i] /= other.vector4D[i];
  }
  return *this;
}

Vector4D Vector4D::operator/(const Vector4D& other) const {
  Vector4D result(*this);
  result /= other;
  return result;
}

bool Vector4D::operator==(const Vector4D& other) const {
  for (int i = 0; i < SIZE; ++i) {
    if (this->vector4D[i] != other.vector4D[i]) {
      return false;
    }
  }
  return true;
}

bool Vector4D::operator!=(const Vector4D& other) const {
  for (int i = 0; i < SIZE; ++i) {
    if (this->vector4D[i] != other.vector4D[i]) {
      return true;
    }
  }
  return false;
}

bool Vector4D::operator<(const Vector4D& other) const {
  for (int i = 0; i < SIZE; ++i) {
    if (this->vector4D[i] < other.vector4D[i]) {
      return true;
    }
  }
  return false;
}

bool Vector4D::operator>(const Vector4D& other) const {
  for (int i = 0; i < SIZE; ++i) {
    if (this->vector4D[i] > other.vector4D[i]) {
      return true;
    }
  }
  return false;
}

bool Vector4D::operator>=(const Vector4D& other) const {
  for (int i = 0; i < SIZE; ++i) {
    if (this->vector4D[i] < other.vector4D[i]) {
      return false;
    }
  }
  return true;
}

bool Vector4D::operator<=(const Vector4D& other) const {
  for (int i = 0; i < SIZE; ++i) {
    if (this->vector4D[i] > other.vector4D[i]) {
      return false;
    }
  }
  return true;
}

bool Vector4D::operator!() const {
  for (double element : this->vector4D) {
    if (element != 0) {
      return false;
    }
  }
  return true;
}

Vector4D Vector4D::operator-() const {
  return Vector4D(
      -this->vector4D[0],
      -this->vector4D[1],
      -this->vector4D[2],
      -this->vector4D[3]
  );
}



