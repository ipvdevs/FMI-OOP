#include "TeamLead.hpp"

TeamLead::TeamLead(const std::string& name, double salary)
    : Developer(name) {
  this->setInitialSalary(salary);
}

std::vector<Developer*> TeamLead::getTeam() const {
  return team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary) {
  if (developer != nullptr && developer != this) {
    developer->setInitialSalary(salary);
    developer->setTeamLead(this);
    this->team.push_back(developer);
  }
}

void TeamLead::removeDeveloperFromTeam(const std::string& name) {
  int index = -1;
  int devCount = team.size();
  for (int i = devCount - 1; i >= 0; --i) {
    if (team[i]->getName() == name) {
      index = i;
      break;
    }
  }

  if (index != -1) {
    team[index]->setTeamLead(nullptr);
    team[index]->setSalary(0.0);
    team.erase(team.begin() + index);
  }
}

void TeamLead::increaseTeamSalariesBy(double amount) {
  for (Developer* dev : team) {
    double currentSalary = dev->getSalary();
    dev->setSalary(currentSalary + amount);
  }
}

void TeamLead::decreaseTeamSalariesBy(double amount) {
  for (Developer* dev : team) {
    double currentSalary = dev->getSalary();
    if (currentSalary - amount >= 0) {
      dev->setSalary(currentSalary - amount);
    }
  }
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest) {
  this->leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest) {
  this->promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests() {
  for (const LeavingRequest& request : leavingRequests) {
    removeDeveloperFromTeam(request.getSender());
  }

  leavingRequests.clear();
}

void TeamLead::fulfillPromotionRequests() {
  for (const PromotionRequest& request : promotionRequests) {
    increaseSalary(request.getSender(), request.getAmount());
  }

  promotionRequests.clear();
}

void TeamLead::increaseSalary(const std::string& name, double amount) {
  int index = -1;
  int devsCount = team.size();
  for (int i = devsCount - 1; i >= 0; --i) {
    std::string devName = team[i]->getName();
    if (devName == name) {
      index = i;
      break;
    }
  }

  if (index != -1) {
    double currentSalary = team[index]->getSalary();
    team[index]->setSalary(currentSalary + amount);
  }
}
