#ifndef TEAM__DEVELOPER_HPP_
#define TEAM__DEVELOPER_HPP_

#include <string>

class TeamLead;

class Developer {
 public:
  Developer(const std::string& name = "");

  std::string getName() const;
  double getSalary() const;
  TeamLead* getTeamLead() const;
  void setInitialSalary(double amount);
  void setTeamLead(TeamLead* teamLead);
  void sendLeavingRequest() const;
  void sendPromotionRequest(double amount) const;

  void setSalary(double salary);

 private:
  std::string name;
  double salary;
  TeamLead* leader;
};

#endif //TEAM__DEVELOPER_HPP_
