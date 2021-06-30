/*
 * FMI_OOP_EXAM_2021
 * Ivan Penev
 * 62535
 * Compiler: GCC (IDE: Clion)
 */

#include <iostream>

#include "NamedObject.hpp"
#include "NamedObjectArray.hpp"

void testNamedObject();
void testNamedObjectArray();

int main() {
  testNamedObject();
  testNamedObjectArray();
  return 0;
}

void testNamedObjectArray() {
  std::cout << " -------- NAMED OBJECT ARRAY EXAMPLES --------" << std::endl;
  // Array of double Named objects
  NamedObjectArray<double> array;

  NamedObject<double> named_object1(1, "Double Object1");
  named_object1.setObject(3.14);
  NamedObject<double> named_object2(2, "Double Object2");
  named_object2.setObject(2.72);
  NamedObject<double> named_object3(3, "Double Object3");
  named_object3.setObject(123);

  array.addNamedObject(named_object1);
  array.addNamedObject(named_object2);
  array.addNamedObject(named_object3);

  std::cout << "Total objects added: " << array.size() << std::endl;

  std::cout << "Value of object at index 0: " << array[0].getObject() << std::endl;
}

void testNamedObject() {
  std::cout << " -------- NAMED OBJECT EXAMPLES --------" << std::endl;

  NamedObject<int> def;
  NamedObject<double> named_object(2, "Double Object");

  NamedObject<double> cpy = named_object;
  NamedObject<double> assignmentOperator;
  assignmentOperator = cpy;

  def.setName("Default");
  def.setObject(10);

  std::cout << "Obj name: " << def.getName() << std::endl;
  std::cout << "Obj id: " << def.getId() << std::endl;
  std::cout << "Obj value: " << def.getObject() << std::endl;
}
