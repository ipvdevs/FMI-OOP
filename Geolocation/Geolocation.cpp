#include "Geolocation.hpp"

/* Default set to 0 */
Geolocation::Geolocation(double latitude, double longitude)
    : latitude(latitude), longitude(longitude) {}

std::istream& operator>>(std::istream& input, Geolocation& location) {
  double latitude = 0, longitude = 0;
  input >> latitude >> longitude;
  location = Geolocation(latitude, longitude);
  return input;
}

std::ostream& operator<<(std::ostream& out, const Geolocation& location) {
  out << '[' << location.latitude << ", " << location.longitude << ']';
  return out;
}