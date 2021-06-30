/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#include "Shapes.hpp"

void Shapes::addCircle(const Circle* circle) {
  if (circle == nullptr) {
    std::cerr << "Cannot add nullptr" << std::endl;
    return;
  }

  Shape* clone = new Circle(*circle);

  shapes.push_back(clone);
}

void Shapes::addRectangle(const Rectangle* rectangle) {
  if (rectangle == nullptr) {
    std::cerr << "Cannot add nullptr" << std::endl;
    return;
  }

  Shape* clone = new Rectangle(*rectangle);

  shapes.push_back(clone);
}

Shapes::Shapes(const Shapes& other) {
  copyFrom(other);
}

Shapes& Shapes::operator=(const Shapes& other) {
  if (this != &other) {
    free();
    copyFrom(other);
  }

  return *this;
}

Shapes::~Shapes() {
  free();
}

void Shapes::copyFrom(const Shapes& other) {
  unsigned int shapesCount = other.shapes.size();
  for (int i = 0; i < shapesCount; ++i) {
    auto obj = other.shapes[i];

    if (dynamic_cast<Circle*>(obj)) {
      this->addCircle(dynamic_cast<Circle*>(obj));
    }

    if (dynamic_cast<Rectangle*>(obj)) {
      this->addRectangle(dynamic_cast<Rectangle*>(obj));
    }
  }
}

void Shapes::free() {
  unsigned int shapesCount = shapes.size();

  for (int i = 0; i < shapesCount; ++i) {
    delete shapes[i];
  }
  shapes.clear();
}

double Shapes::calcRectanglesArea() const {
  double rectanglesArea = 0.0;

  for (auto shape : shapes) {
    // Check if it's a rectangle
    if (dynamic_cast<Rectangle*> (shape)) {
      rectanglesArea += shape->calcArea();
    }
  }
  return rectanglesArea;
}

double Shapes::calcCirclesArea() const {
  double circlesArea = 0.0;

  for (auto shape : shapes) {
    // Check if it's a rectangle
    if (dynamic_cast<Circle*> (shape)) {
      circlesArea += shape->calcArea();
    }
  }

  return circlesArea;
}

const Shape* Shapes::getShapeAt(int index) const {
  if (index < 0 || index >= shapes.size()) {
    throw std::out_of_range("Out of range");
  }

  return shapes[index];
}
