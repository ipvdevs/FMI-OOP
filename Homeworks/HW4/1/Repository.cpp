#include "Repository.hpp"

void Repository::copySubs(const Repository &src)
{
    size_t subsCount = src.subs.size();

    for (size_t i = 0; i < subsCount; i++)
    {
        this->subs.push_back(cloneSub(src.subs[i]));
    }
}

void Repository::deleteRepository()
{
    for (auto sub : subs)
    {
        delete sub;
    }

    subs.clear();
}

Repository::Repository(const Repository &other)
{
    copySubs(other);
}

Repository &Repository::operator=(const Repository &other)
{
    if (this != &other)
    {
        deleteRepository();
        copySubs(other);
    }

    return *this;
}

Repository::~Repository()
{
    deleteRepository();
}

void Repository::add(Subscriber *sub)
{
    if (sub != nullptr)
    {
        subs.push_back(cloneSub(sub));
    }
}

Subscriber *Repository::get(const std::string &id)
{
    for (Subscriber *sub : subs)
    {
        if (sub->id == id)
        {
            return sub;
        }
    }

    return nullptr;
}

Subscriber *Repository::cloneSub(Subscriber *sub)
{
    auto movingAveragerClone = dynamic_cast<MovingAverager *>(sub);

    if (movingAveragerClone != nullptr)
    {
        return new MovingAverager(*movingAveragerClone);
    }

    auto averagerClone = dynamic_cast<Averager *>(sub);

    if (averagerClone != nullptr)
    {
        return new Averager(*averagerClone);
    }

    auto periodicSamplerClone = dynamic_cast<PeriodicSampler *>(sub);

    if (periodicSamplerClone != nullptr)
    {
        return new PeriodicSampler(*periodicSamplerClone);
    }

    return nullptr;
}
