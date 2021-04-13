#include <iostream>
#include "GeolocationDatabase.hpp"

int main() {
  GeolocationDatabase geoData;
  geoData.read("../locations.txt");

  std::cout << "Count of read geolocations: " << geoData.size() << '\n';
  std::cout << geoData << std::endl;
  return 0;
}
