#pragma once

#include <vector>

#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"

// SimplePublisher is a Publisher, which can have one
// or more subscribers and upon receiving a message
// via `signal()`, it replays that message to all the
// subscribers
class SimplePublisher
{
public:
  SimplePublisher() = default;

  // Registers a Subscriber to start receiving messages
  virtual void subscribe(Subscriber *);

  // Removes a Subscriber from the Publisher
  // Subscribers are removed based on their `id`
  // id's is guranteed to be unique
  virtual void unsubscribe(Subscriber *);

  // Signal receives a message from an external source
  // and replays that message to all the current subscribers
  virtual void signal(const Message &);

  unsigned count() const;

  virtual ~SimplePublisher() = default;

private:
  std::vector<Subscriber *> subscribers;
};
