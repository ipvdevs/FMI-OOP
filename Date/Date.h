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

#ifndef DATE_H_GUARD
#define DATE_H_GUARD

#define DEFAULT_DAY 1
#define DEFAULT_MONTH 1
#define DEFAULT_YEAR 2000

class Date {
 public:

  Date();
  Date(unsigned short day, unsigned short month, unsigned int year);
  Date(const Date &);

  unsigned short getDay() const;
  unsigned short getMonth() const;
  unsigned int getYear() const;

  void addDays(unsigned int);
  void subtractDays(unsigned int);
  bool isLeapYear() const;
  bool isBeforeThan(const Date &) const;
  unsigned int daysToXmas() const;
  unsigned int daysToNewYear() const;
  unsigned int daysToDate(const Date &) const;

 private:
  // Useful utilities
  short daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  unsigned int getDaysOfMonth() const;
  unsigned int countLeapYears() const;

  unsigned short day;
  unsigned short month;
  unsigned int year;
};

#endif //DATE_H_GUARD
