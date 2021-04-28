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

Date::Date() : day(DEFAULT_DAY), month(DEFAULT_MONTH), year(DEFAULT_YEAR) {}
Date::Date(unsigned short day, unsigned short month, unsigned int year) {
  this->day = day;
  this->month = month;
  this->year = year;
}
Date::Date(const Date& date) : day(date.day), month(date.month), year(date.year) {}

unsigned short Date::getDay() const {
  return day;
}

unsigned short Date::getMonth() const {
  return month;
}

unsigned int Date::getYear() const {
  return year;
}

void Date::addDays(const unsigned int days) {
  this->daysInMonth[1] = this->isLeapYear() ? 29 : 28;

  unsigned int newDay = this->day + days;
  while (newDay > this->daysInMonth[this->month - 1]) {
    newDay = newDay - this->daysInMonth[this->month - 1];

    if (this->month == 12) {
      ++(this->year);
      this->daysInMonth[1] = this->isLeapYear() ? 29 : 28;
      this->month = 1;
    } else {
      ++(this->month);
    }
  }

  this->day = newDay;
}

void Date::subtractDays(const unsigned int days) {
  this->daysInMonth[1] = this->isLeapYear() ? 29 : 28;

  int newDay = (int) (this->day - days);
  while (newDay <= 0) {
    if (this->month == 1) {
      --(this->year);
      this->daysInMonth[1] = this->isLeapYear() ? 29 : 28;
      this->month = 12;
    } else {
      --(this->month);
    }
    newDay = newDay + this->daysInMonth[this->month - 1];
  }

  this->day = newDay;
}

bool Date::isLeapYear() const {
  return ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
}

unsigned int Date::daysToDate(const Date& nextDate) const {
  if (!isBeforeThan(nextDate)) {
    // Error placeholder
    return 0;
  }
  // Calculate total days passed until the fixed moment
  unsigned int currentDateDaysOfYear =
      this->year * 365 + this->day + this->getDaysOfMonth();
  unsigned int nextDateDaysOfYear =
      nextDate.year * 365 + nextDate.day + nextDate.getDaysOfMonth();

  // Leap years calibration
  currentDateDaysOfYear += this->countLeapYears();
  nextDateDaysOfYear += nextDate.countLeapYears();

  return nextDateDaysOfYear - currentDateDaysOfYear;
}

unsigned int Date::daysToXmas() const {
  if (this->month == 12 && this->day > 25) {
    return this->daysToDate(Date(25, 12, this->year + 1));
  }
  return this->daysToDate(Date(25, 12, this->year));
}

unsigned int Date::daysToNewYear() const {
  return this->daysToDate(Date(1, 1, this->year + 1));
}

bool Date::isBeforeThan(const Date& nextDate) const {
  if (this->year < nextDate.year) {
    return true;
  } else if (this->year == nextDate.year) {
    if (this->month < nextDate.month) {
      return true;
    } else if (this->month == nextDate.month) {
      if (this->day < nextDate.day) {
        return true;
      }
    }
  }

  return false;
}

unsigned int Date::getDaysOfMonth() const {
  unsigned int totalDays = 0;
  for (int month_i = 0; month_i < this->month - 1; ++month_i) {
    totalDays += daysInMonth[month_i];
  }

  return totalDays;
}

// Analytic approach O(N) of calculating leap years between (1, year) instead of
// using loop
unsigned int Date::countLeapYears() const {
  unsigned int years = this->year;

  if (this->month <= 2) {
    years--;
  }

  return (years / 4) - (years / 100) + (years / 400);
}
