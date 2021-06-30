#pragma once

#include <string>
#include <vector>

#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"

// Repository is the single place where Subscribers will
// be stored. A Repository has ownership of the Subscribers
// stored inside it.
// The only way to access the available Subscribers in the
// repository is via the Subscriber's unique id.
// id's are guaranteed to be unique
class Repository
{
public:
    // Gang of three
    Repository() = default;
    Repository(const Repository &);
    Repository &operator=(const Repository &);

    // Registers a new Subscriber in the Repository
    void add(Subscriber *);

    // Returns a Subscriber in the Repository if a
    // Subscriber with the given id exists.
    // Returns nullptr otherwise
    Subscriber *get(const std::string &id);

    ~Repository();

private:
    std::vector<Subscriber *> subs;

    // Helpers
    Subscriber *cloneSub(Subscriber *);
    void copySubs(const Repository &src);
    void deleteRepository();
};
