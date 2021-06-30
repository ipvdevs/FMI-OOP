/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#ifndef EXAM_2021__CIRCLE_HPP_
#define EXAM_2021__CIRCLE_HPP_

#include "Shape.hpp"

#define MATH_PI 3.14156

class Circle : public Shape {
 public:
  Circle() = default;

  double getRadius() const;
  void setRadius(double radius);

  double calcArea() const override;

 private:
  double radius = 0.0;
};

#endif //EXAM_2021__CIRCLE_HPP_
