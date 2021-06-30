#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(const std::string &id, size_t period)
    : Subscriber(id), period(period){};

void PeriodicSampler::signal(const Message &message)
{
  ++signalsCount;
  if (signalsCount % period == 1)
  {
    Subscriber::signal(message);
  }
}

int PeriodicSampler::read() const
{
  if (Subscriber::signals.empty())
  {
    return 0;
  }

  return signals[signals.size() - 1].data;
}
