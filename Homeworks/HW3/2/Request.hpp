#ifndef TEAM__REQUEST_HPP_
#define TEAM__REQUEST_HPP_

#include <string>

class Request {
 public:
  Request(const std::string& message = "", const std::string& sender = "");

  std::string getMessage() const;
  std::string getSender() const;
  static int getCount();
  int getID() const;

 private:
  std::string message;
  std::string sender;
  static int counter;
  int id;
};

#endif //TEAM__REQUEST_HPP_
