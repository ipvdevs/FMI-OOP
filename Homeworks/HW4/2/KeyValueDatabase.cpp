#include "KeyValueDatabase.hpp"
#include <stdexcept>
#include <sstream> // std::stringstream

KeyValueDatabase::KeyValueDatabase(const std::string &name,
                                   const std::string &location,
                                   const std::string &extension)
    : Object(name, location, extension){};

void KeyValueDatabase::add_entry(const std::pair<std::string, int> &entry)
{
    for (const auto &availableEntry : entries)
    {
        if (availableEntry.first == entry.first)
        {
            throw std::invalid_argument("Key already exists!");
        }
    }

    entries.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string &key) const
{
    for (const auto &availableEntry : entries)
    {
        if (availableEntry.first == key)
        {
            return availableEntry.second;
        }
    }

    throw std::invalid_argument("Key not found!");
}

bool KeyValueDatabase::operator==(const Comparable *other) const
{
    auto otherCasted = dynamic_cast<KeyValueDatabase *>(const_cast<Comparable *>(other));

    if (otherCasted == nullptr)
    {
        return false;
    }

    if (this->entries.size() != otherCasted->entries.size())
    {
        return false;
    }

    size_t totalEntries = entries.size();

    for (size_t i = 0; i < totalEntries; i++)
    {
        bool keysDifferent = this->entries[i].first != otherCasted->entries[i].first;
        bool valuesDifferent = this->entries[i].second != otherCasted->entries[i].second;

        if (keysDifferent || valuesDifferent)
        {
            return false;
        }
    }

    return true;
}

bool KeyValueDatabase::operator!=(const Comparable *other) const
{
    return !this->operator==(other);
}

std::string KeyValueDatabase::debug_print() const
{
    std::string debugInfo = "";

    for (const auto &entry : entries)
    {
        debugInfo += "{" + entry.first + ":" + std::to_string(entry.second) + "}\n";
    }

    return debugInfo;
}

std::string KeyValueDatabase::to_string() const
{
    std::string header = Object::to_string();

    std::string entriesInfo = "";
    for (const auto &entry : entries)
    {
        entriesInfo += entry.first + ":" + std::to_string(entry.second) + "\n";
    }

    return header + entriesInfo;
}

void KeyValueDatabase::from_string(const std::string &info)
{
    std::stringstream ss(info);
    ss >> name >> location >> extension;

    ss.ignore(); // Ignore emprty line

    std::string key;
    int value;

    while (std::getline(ss, key, ':'))
    {
        ss >> value;

        std::pair<std::string, int> entry(key, value);
        entries.push_back(entry);

        ss.ignore(); // Ignore emprty line
    }
}

Object *KeyValueDatabase::clone() const
{
    return new KeyValueDatabase(*this);
};