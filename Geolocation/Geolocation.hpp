#ifndef GEOLOCATION__GEOLOCATION_HPP_
#define GEOLOCATION__GEOLOCATION_HPP_

#include <iostream>

struct Geolocation {
  double latitude;
  double longitude;

  explicit Geolocation(double latitude = 0, double longitude = 0);
};

std::istream& operator>>(std::istream&, Geolocation&);
std::ostream& operator<<(std::ostream&, const Geolocation&);

#endif //GEOLOCATION__GEOLOCATION_HPP_
