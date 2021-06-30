/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#ifndef EXAM_2021__SHAPES_HPP_
#define EXAM_2021__SHAPES_HPP_

#include <vector>   // Container
// Error logging
#include <iostream>
#include <stdexcept>

#include "Circle.hpp"
#include "Rectangle.hpp"

class Shapes {
 public:
  Shapes() = default;
  Shapes(const Shapes&);
  Shapes& operator=(const Shapes&);
  ~Shapes();

  // Factory-like pattern
  void addCircle(const Circle* circle);
  void addRectangle(const Rectangle* rectangle);

  const Shape* getShapeAt(int index) const;

  double calcRectanglesArea() const;
  double calcCirclesArea() const;

 private:
  std::vector<Shape*> shapes;

  void copyFrom(const Shapes& shapes);
  void free();
};

#endif //EXAM_2021__SHAPES_HPP_
