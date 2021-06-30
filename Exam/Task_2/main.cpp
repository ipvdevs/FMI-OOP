/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#include <iostream>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shapes.hpp"

int main() {
  Circle defCircle;
  Rectangle defRectangle;

  defCircle.setColor("BLUE");
  defCircle.setRadius(10);

  defRectangle.setHeight(10.5);
  defRectangle.setWidth(20.5);
  defRectangle.setColor("GREEN");

  std::cout << "Circle\n"
            << "Color: " << defCircle.getColor() << "\n"
            << "Radius: " << defCircle.getRadius() << "\n"
            << "Area: " << defCircle.calcArea() << std::endl;

  std::cout << "------------------" << std::endl;

  std::cout << "Rectangle\n"
            << "Color: " << defRectangle.getColor() << "\n"
            << "Width: " << defRectangle.getWidth() << "\n"
            << "Height: " << defRectangle.getHeight() << "\n"
            << "Area: " << defRectangle.calcArea() << std::endl;

  std::cout << "------------------" << std::endl;

  Shapes shapes;

  shapes.addCircle(&defCircle);
  shapes.addCircle(&defCircle);
  shapes.addCircle(&defCircle);

  shapes.addRectangle(&defRectangle);
  shapes.addRectangle(&defRectangle);
  shapes.addRectangle(&defRectangle);

  std::cout << "Rectangles area: " << shapes.calcRectanglesArea() << std::endl;
  std::cout << "Circles area: " << shapes.calcCirclesArea() << std::endl;

  std::cout << "Color of Shape at index 2: " << shapes.getShapeAt(2)->getColor() << std::endl;

  Shapes cpy = shapes;
  Shapes assignment;
  assignment = cpy;

  return 0;
}

