/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Ivan Penev
* @idnumber
* @task 1
* @compiler GCC
*/

#include "Date.h"
#include <iostream>

#define PRINT_LEADING_ZERO std::cout << '0';

void printDate(const Date &date);
void testDate();

int main() {
  
  // Some simple tests to check Date class functionality
  testDate();

  return 0;
}

void printDate(const Date &date) {
  if (date.getDay() < 10) {
    PRINT_LEADING_ZERO
  }
  std::cout << date.getDay() << '.';

  if (date.getMonth() < 10) {
    PRINT_LEADING_ZERO
  }
  std::cout << date.getMonth() << '.' << date.getYear();
  std::cout << std::endl;
}

void testDate() {
  // Using constructors
  Date def;
  printDate(def);
  Date userSetDate = Date(12, 12, 2012);
  printDate(userSetDate);

  // Add and subtract days to date
  userSetDate.addDays(24);
  std::cout << "12.12.2012 + 24 days: ";
  printDate(userSetDate);
  userSetDate.subtractDays(366);
  std::cout << "05.01.2013 - 366 days (2012 is Leap year): ";
  printDate(userSetDate);

  std::cout << "Is 2012 leap: " << (userSetDate.isLeapYear() ? "true" : "false") << '\n';
  std::cout << "05.01.2012 days to Xmas: " << userSetDate.daysToXmas() << '\n';

  Date beginningOfYear2012(1, 1, 2012);
  std::cout << "From 01.01.2012 days to New Year: " << beginningOfYear2012.daysToNewYear() << '\n';

  Date libearationDay(3, 3, 2012);
  std::cout << "From 01.01.2012 days to "
               "Liberation Day: " << beginningOfYear2012.daysToDate(libearationDay) << '\n';

  //31.3.2014 . isBeforeThan(1.1.2000) false
  bool d1_Before_d2 = Date(31, 3, 2014).isBeforeThan(Date(01, 01, 2000));
  std::cout << (d1_Before_d2 ? "31.03.2014 is before 01.01.2000" : "31.03.2014 is not before 01.01.2000");

  std::cout << std::endl;
}

