#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Subscriber *subscriber)
{
  SimplePublisher::subscribe(subscriber);

  if (subscriber != nullptr)
  {
    sendOldSignals(subscriber);
  }
}

void BacklogPublisher::signal(const Message& message) {
  SimplePublisher::signal(message);
  backlog.push_back(message);
}

void BacklogPublisher::sendOldSignals(Subscriber *subscriber)
{
  for (const Message msg : backlog)
  {
    subscriber->signal(msg);
  }
}