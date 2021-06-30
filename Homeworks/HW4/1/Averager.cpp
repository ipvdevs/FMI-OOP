#include "Averager.hpp"

Averager::Averager(const std::string &id) : Subscriber(id){};

int Averager::read() const
{
  // If there isn't any data -> return 0
  if (Subscriber::signals.empty())
  {
    return 0;
  }

  // Calculate the average
  int totalSignals = signals.size();

  int sum = 0;
  for (const Message &signal : signals)
  {
    sum += signal.data;
  }

  // remainder is discarded
  return sum / totalSignals;
}
