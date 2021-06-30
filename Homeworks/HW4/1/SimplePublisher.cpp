#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Subscriber *subscriber)
{
  if (subscriber == nullptr)
  {
    return;
  }

  subscribers.push_back(subscriber);
}

void SimplePublisher::unsubscribe(Subscriber *subscriber)
{
  if (subscriber == nullptr)
  {
    return;
  }

  int removeIndex = -1;

  size_t totalSubscribers = subscribers.size();
  for (size_t i = 0; i < totalSubscribers; i++)
  {
    if (subscribers[i]->id == subscriber->id)
    {
      removeIndex = i;
      break;
    }
  }

  if (removeIndex != -1)
  {
    subscribers.erase(subscribers.begin() + removeIndex);
  }
}

void SimplePublisher::signal(const Message &message)
{
  for (Subscriber *sub : subscribers)
  {
    if (sub != nullptr)
    {
      sub->signal(message);
    }
  }
}

unsigned SimplePublisher::count() const
{
  return subscribers.size();
}