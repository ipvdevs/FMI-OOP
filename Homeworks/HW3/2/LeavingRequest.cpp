#include "LeavingRequest.hpp"

LeavingRequest::LeavingRequest(const std::string& sender)
    : Request(LEAVING_MESSAGE, sender) {}
