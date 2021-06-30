/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#include "Circle.hpp"

double Circle::getRadius() const {
  return radius;
}

void Circle::setRadius(const double newRadius) {
  this->radius = newRadius;
}

double Circle::calcArea() const {
  return MATH_PI * radius * radius;
}
