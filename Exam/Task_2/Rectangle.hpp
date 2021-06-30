/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#ifndef EXAM_2021__RECTANGLE_HPP_
#define EXAM_2021__RECTANGLE_HPP_

#include "Shape.hpp"

class Rectangle : public Shape {
 public:
  Rectangle() = default;
  Rectangle(const std::string& color, double width, double height);

  double getWidth() const;
  double getHeight() const;

  void setWidth(double newWidth);
  void setHeight(double newHeight);

  double calcArea() const override;

 private:
  double width = 0.0;
  double height = 0.0;
};

#endif //EXAM_2021__RECTANGLE_HPP_
