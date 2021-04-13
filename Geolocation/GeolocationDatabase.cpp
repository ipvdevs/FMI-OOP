#include "GeolocationDatabase.hpp"

std::istream& operator>>(std::istream& input, GeolocationDatabase& database) {
  Geolocation location;
  while (input >> location) {
    database.add(location);
  }
  return input;
}

bool GeolocationDatabase::read(const char* filepath) {
  std::ifstream inputFile;
  inputFile.open(filepath);

  if (!inputFile.is_open()) {
    std::cerr << "Cannot open current file." << std::endl;
    return false;
  }

  inputFile >> *this;

  inputFile.close();
  return true;
}

std::ostream& operator<<(std::ostream& output, GeolocationDatabase& database) {
  output << std::fixed << std::setprecision(5);
  for (Geolocation geolocation : database.locations) {
    double latitude = geolocation.latitude;
    double longitude = geolocation.longitude;
    output << '[' << latitude << ", " << longitude << ']' << '\n';
  }

  output << std::endl;

  return output;
}

void GeolocationDatabase::add(const Geolocation& location) {
  this->locations.push_back(location);
}

unsigned int GeolocationDatabase::size() const {
  return this->locations.size();
}
