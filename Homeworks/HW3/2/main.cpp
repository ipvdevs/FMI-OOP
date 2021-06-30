#include <iostream>
#include "Request.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include "Developer.hpp"
#include "TeamLead.hpp"

void testRequest();
void testLeavingRequest();
void testPromotionRequest();
void testDeveloper();

int main() {
//   testRequest();
//   testLeavingRequest();
//   testPromotionRequest();
//  testDeveloper();


  TeamLead tim = TeamLead("Tim", 4000);
  Developer dev1 = Developer("Dev1");
  dev1.setInitialSalary(1001);
  Developer dev2 = Developer("Dev2");
  dev2.setInitialSalary(1002);
  Developer dev3 = Developer("Dev3");
  dev3.setInitialSalary(1003);

  PromotionRequest dev1prom = PromotionRequest(dev1.getName(), 100);
  PromotionRequest dev2prom = PromotionRequest(dev2.getName(), 100);
  PromotionRequest dev3prom = PromotionRequest(dev3.getName(), 100);

  tim.addDeveloperToTeam(&dev1, 2001);
  tim.addDeveloperToTeam(&dev2, 2002);
  tim.addDeveloperToTeam(&dev3, 2003);

  tim.addPromotionRequest(dev1prom);
  tim.addPromotionRequest(dev2prom);
  tim.addPromotionRequest(dev3prom);

  tim.fulfillPromotionRequests();

  LeavingRequest dev1leave = LeavingRequest(dev1.getName());
  LeavingRequest dev2leave = LeavingRequest(dev2.getName());
  LeavingRequest dev3leave = LeavingRequest(dev3.getName());

  tim.addLeavingRequest(dev1leave);
  tim.addLeavingRequest(dev2leave);
  tim.addLeavingRequest(dev3leave);

  tim.fulfillLeavingRequests();
  return 0;
}

void testDeveloper() {
  Developer dev1 = Developer("Samuel");
  Developer dev2 = Developer("Samuel");
  Developer dev3 = Developer("Samuel");
  TeamLead manager = TeamLead("Edward", 2500);

  manager.addDeveloperToTeam(&dev1, 1600);
  manager.addDeveloperToTeam(&dev2, 2600);
  manager.addDeveloperToTeam(&dev3, 4000);

  manager.increaseTeamSalariesBy(1000);
  manager.decreaseTeamSalariesBy(3600);

  dev3.sendPromotionRequest(1000);
  dev3.sendLeavingRequest();

  manager.fulfillPromotionRequests();
  manager.fulfillLeavingRequests();
  std::cout << "Debug" << '\n';
}

void testPromotionRequest() {
  std::cout << "ReqCount: " << PromotionRequest::getCount() << '\n';

  auto promoRequest1 = PromotionRequest("Sam", 200);
  auto promoRequest2 = PromotionRequest("Tim", 150);

  std::cout << "ReqCount: " << PromotionRequest::getCount() << '\n';

  std::cout << promoRequest1.getID() << '\n';
  std::cout << promoRequest1.getSender() << '\n';
  std::cout << promoRequest1.getMessage() << '\n';
  std::cout << promoRequest1.getAmount() << '\n';

  std::cout << promoRequest2.getID() << '\n';
  std::cout << promoRequest2.getSender() << '\n';
  std::cout << promoRequest2.getMessage() << '\n';
  std::cout << promoRequest2.getAmount() << '\n';
}

void testLeavingRequest() {
  std::cout << "ReqCount: " << LeavingRequest::getCount() << '\n';

  LeavingRequest leaveReq1 = LeavingRequest("George");
  LeavingRequest leaveReq2 = LeavingRequest("Joey");

  std::cout << "ReqCount: " << LeavingRequest::getCount() << '\n';

  std::cout << leaveReq1.getID() << '\n';
  std::cout << leaveReq1.getSender() << '\n';
  std::cout << leaveReq1.getMessage() << '\n';

  std::cout << leaveReq2.getID() << '\n';
  std::cout << leaveReq2.getSender() << '\n';
  std::cout << leaveReq2.getMessage() << '\n';

}

void testRequest() {
  Request req1 = Request("Test request1", "Sender");
  Request req2 = Request("Test request2", "Sender");
  Request req3 = Request("Test request3", "Sender");

  std::cout << req3.getID() << '\n';
  std::cout << req3.getSender() << '\n';
  std::cout << req3.getMessage() << '\n';

  std::cout << Request::getCount() << '\n';
}
