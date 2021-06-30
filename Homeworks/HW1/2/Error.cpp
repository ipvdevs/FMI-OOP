#include "Error.hpp"

Error::Error() : type(ErrorType::None), message(nullptr) {}

Error Error::newNone() {
  return Error();
}

Error Error::newBuildFailed(const char *message) {
  Error temp;
  temp.setType(ErrorType::BuildFailed);
  temp.setMessage(message);
  return temp;
}

Error Error::newWarning(const char *message) {
  Error temp;
  temp.setType(ErrorType::Warning);
  temp.setMessage(message);
  return temp;
}

Error Error::newFailedAssertion(const char *message) {
  Error temp;
  temp.setType(ErrorType::FailedAssertion);
  temp.setMessage(message);
  return temp;
}

Error::Error(const Error &other) {
  this->type = other.type;
  this->setMessage(other.message);
}

Error &Error::operator=(const Error &other) {
  if (this != &other) {
    this->type = other.type;
    delete[] message;
    this->setMessage(other.message);
  }

  return *this;
}

Error::~Error() {
  delete[] message;
}

void Error::setType(ErrorType typeToSet) {
  this->type = typeToSet;
}

void Error::setMessage(const char *messageToSet) {
  if (messageToSet == nullptr) {
    this->message = nullptr;
    return;
  }

  // Provide +1 space for terminating null
  unsigned int size = getStrLength(messageToSet) + 1;
  this->message = new char[size];
  strCopy(messageToSet, this->message);
}

ErrorType Error::getType() const {
  return this->type;
}

const char *Error::getMessage() const {
  return this->message;
}

bool Error::hasMessage() const {
  return this->message != nullptr;
}

