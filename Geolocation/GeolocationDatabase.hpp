#ifndef GEOLOCATION__GEOLOCATIONDATABASE_HPP_
#define GEOLOCATION__GEOLOCATIONDATABASE_HPP_

#include <vector>
#include <fstream>
#include <iomanip>
#include "Geolocation.hpp"

class GeolocationDatabase {
 private:
  std::vector<Geolocation> locations;

 public:
  GeolocationDatabase() = default;

  friend std::istream& operator>>(std::istream&, GeolocationDatabase&);
  friend std::ostream& operator<<(std::ostream&, GeolocationDatabase&);

  void add(const Geolocation&);
  bool read(const char* filename);
  unsigned int size() const;
};

#endif //GEOLOCATION__GEOLOCATIONDATABASE_HPP_
