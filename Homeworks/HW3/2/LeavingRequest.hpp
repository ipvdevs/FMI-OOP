#ifndef TEAM__LEAVINGREQUEST_HPP_
#define TEAM__LEAVINGREQUEST_HPP_
#include "Request.hpp"

#define LEAVING_MESSAGE "I want to leave!"

class LeavingRequest : public Request {
 public:
  LeavingRequest(const std::string& sender = "");
};

#endif //TEAM__LEAVINGREQUEST_HPP_
