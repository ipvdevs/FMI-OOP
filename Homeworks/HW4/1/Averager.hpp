#pragma once
#include <string>
#include <vector>

#include "Message.hpp"
#include "Subscriber.hpp"

// Averager is a type of Subscriber, which saves data and
// returns the average of the data when `read()` is called.
// Data is provided with the `signal()` method.
// Average of N numbers = sum(all numbers) / N
class Averager : public Subscriber
{
public:
  Averager(const std::string &id);

  // read calculates the average of all data points provided so far
  // returns 0 if there's no data points
  int read() const override;
};
