#pragma once

#include <string>

#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"

// MovingAverager is a type of Subscriber, which saves data
// and returns the average of the last `windowSize` number of
// data points when `read()` is called.
// Data is provided with the `signal()` method.
// Average of N numbers = sum(all numbers) / N
class MovingAverager : public Averager
{
public:
  // windowSize specifies how many most-recent data points
  // should be saved
  // Should never be changed once initialized
  const size_t windowSize;

  MovingAverager(const std::string &id, size_t windowSize);

  // signal adds a new data point
  // Only the last windowSize number of
  // data points are added, older data points should be ignored
  void signal(const Message &) override;

private:
  // Signal attempts counter
  int signalsCount = 0;
};
