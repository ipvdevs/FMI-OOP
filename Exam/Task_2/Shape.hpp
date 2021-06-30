/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#ifndef EXAM_2021__SHAPE_HPP_
#define EXAM_2021__SHAPE_HPP_

#include <string>

#define DEFAULT_COLOR "WHITE"

class Shape {
 public:
  explicit Shape(const std::string& color = DEFAULT_COLOR);

  void setColor(const std::string& newColor);
  std::string getColor() const;

  virtual double calcArea() const = 0;

  virtual ~Shape() = default;
 protected:
  std::string color;
};

#endif //EXAM_2021__SHAPE_HPP_
