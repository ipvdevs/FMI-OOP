#include "Subscriber.hpp"

Subscriber::Subscriber(const std::string &id) : id(id){};

void Subscriber::signal(const Message &message)
{
    signals.push_back(message);
}
