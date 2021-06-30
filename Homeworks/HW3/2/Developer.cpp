#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(const std::string& name)
    : name(name), salary(0.0), leader(nullptr) {}

std::string Developer::getName() const {
  return name;
}

double Developer::getSalary() const {
  return salary;
}

TeamLead* Developer::getTeamLead() const {
  return leader;
}

void Developer::setTeamLead(TeamLead* teamLead) {
  this->leader = teamLead;
}

void Developer::setSalary(const double newSalary) {
  if (newSalary >= 0.0) {
    this->salary = newSalary;
  }
}

void Developer::setInitialSalary(double amount) {
  if (salary == 0.0 && amount >= 0.0) {
    salary = amount;
  }
}

void Developer::sendLeavingRequest() const {
  if (leader != nullptr) {
    leader->addLeavingRequest(LeavingRequest(name));
  }
}

void Developer::sendPromotionRequest(double amount) const {
  if (leader != nullptr) {
    leader->addPromotionRequest(PromotionRequest(name, amount));
  }
}


