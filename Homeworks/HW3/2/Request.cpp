#include "Request.hpp"

// Defining the static variable
int Request::counter = 0;

Request::Request(const std::string& message, const std::string& sender)
    : message(message), sender(sender) {
  ++counter;
  id = counter;
}

std::string Request::getMessage() const {
  return message;
}
std::string Request::getSender() const {
  return sender;
}

int Request::getCount() {
  return counter;
}

int Request::getID() const {
  return id;
}
