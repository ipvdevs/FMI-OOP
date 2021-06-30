#pragma once

#include <string>

#include "Message.hpp"
#include "Subscriber.hpp"

// PeriodicSampler is a type of Subscriber, which saves every
// period-th data point starting from the first data point provided.
// Data is provided with the `signal()` method.
//
// e.g if the period = 2, we save every 2nd data point provided
// so if we have
// signal(1), read(), signal(2), read(), signal(3), read(), signal(4), read()
// the output will be 1,1,3,3 as we skip every 2nd data point,
// which in our case is 2 and 4
class PeriodicSampler : public Subscriber
{
public:
  const size_t period;

  PeriodicSampler(const std::string &id, size_t period);

  // signal adds a new data point and saves only every period-th
  // data point, the data points inbetween are ignored
  void signal(const Message &) override;

  // read returns the latest period-th data point if such exists
  // 0 otherwise
  int read() const override;

private:
  // Signal attempts counter
  int signalsCount = 0;
};
