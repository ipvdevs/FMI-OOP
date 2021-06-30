#pragma once

#include <string>
#include <deque>

#include "Message.hpp"

class Subscriber
{
public:
  // id is a unique identifier for a Subscriber
  // Should never be changed once initialized
  const std::string id;

  // Construct a subscriber with an unique identifier
  Subscriber(const std::string &id);

  // Adds a new data point
  virtual void signal(const Message &);

  // Read is based on the specific type of subscriber
  // returns 0 if there's no data points
  // Pure virtual
  virtual int read() const = 0;

  virtual ~Subscriber() = default;

protected:
  std::deque<Message> signals;
};