#ifndef TEAM__PROMOTIONREQUEST_HPP_
#define TEAM__PROMOTIONREQUEST_HPP_

#include "Request.hpp"

#define PROMOTION_MESSAGE "I want a raise!"

class PromotionRequest : public Request {
 public:
  PromotionRequest(const std::string& sender = "", double increaseAmount = 0.0);

  double getAmount() const;

 private:
  double increaseAmount;
};

#endif //TEAM__PROMOTIONREQUEST_HPP_
