#include "PromotionRequest.hpp"

PromotionRequest::PromotionRequest(const std::string& sender, double increaseAmount)
    : Request(PROMOTION_MESSAGE, sender), increaseAmount(increaseAmount) {}

double PromotionRequest::getAmount() const {
  return increaseAmount;
}
