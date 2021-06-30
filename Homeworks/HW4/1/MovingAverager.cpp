#include "MovingAverager.hpp"

MovingAverager::MovingAverager(const std::string &id, size_t windowSize)
    : Averager(id), windowSize(windowSize){};

void MovingAverager::signal(const Message &message)
{
  Subscriber::signal(message);

  if (signals.size() > windowSize)
  {
    signals.pop_front();
  }
}
