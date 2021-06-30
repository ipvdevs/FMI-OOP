#pragma once

#include <string>

#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"

class Object : public Comparable, public Debug, public Serializable
{
public:
    Object(const std::string &name,
           const std::string &location,
           const std::string &extension);

    std::string to_string() const override;

    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;

    virtual Object *clone() const = 0;

    virtual ~Object() = default;

protected:
    std::string name;
    std::string location;
    std::string extension;
};