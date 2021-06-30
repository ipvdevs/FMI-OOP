/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#include "Rectangle.hpp"

Rectangle::Rectangle(const std::string& color, double width, double height)
    : Shape(color), width(width), height(height) {}

double Rectangle::getWidth() const {
  return width;
}

double Rectangle::getHeight() const {
  return height;
}

void Rectangle::setWidth(double newWidth) {
  this->width = newWidth;
}

void Rectangle::setHeight(double newHeight) {
  this->height = newHeight;
}

double Rectangle::calcArea() const {
  return width * height;
}


