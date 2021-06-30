/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#include "Shape.hpp"

Shape::Shape(const std::string& color) : color(color) {}

void Shape::setColor(const std::string& newColor) {
  this->color = newColor;
}

std::string Shape::getColor() const {
  return color;
}
