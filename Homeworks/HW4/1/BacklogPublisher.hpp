#pragma once

#include <vector>

#include "SimplePublisher.hpp"

// BacklogPublisher is a Publisher, which can have one
// or more subscribers and upon receiving a message
// via `signal()`, it replays that message to all the
// subscribers
// Also it keeps a backlog of previous messages so when a new
// Subscriber subscribes, the Publisher replays all
// backlogged messages to the new Subscriber
class BacklogPublisher : public SimplePublisher
{
public:
  BacklogPublisher() = default;

  // Registers a Subscriber to start receiving messages
  // The new subscriber should receive all previous messages
  void subscribe(Subscriber *) override;

  // signal receives a message from an external source
  // and replays that message to all the current subscribers
  void signal(const Message &) override;

private:
  std::vector<Message> backlog;

  void sendOldSignals(Subscriber *);
};
