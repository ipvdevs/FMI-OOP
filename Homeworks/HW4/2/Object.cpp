#include "Object.hpp"

Object::Object(const std::string &name,
               const std::string &location,
               const std::string &extension)
    : name(name), location(location), extension(extension){};

std::string Object::get_name() const
{
    return name;
}

std::string Object::get_location() const
{
    return location;
}

std::string Object::get_extension() const
{
    return extension;
}

std::string Object::get_fullpath() const
{
    return location + "/" + name + "." + extension;
}

std::string Object::to_string() const
{
    return get_name() + "\n" +
           get_location() + "\n" +
           get_extension() + "\n";
};