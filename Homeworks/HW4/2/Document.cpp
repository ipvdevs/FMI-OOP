#include "Document.hpp"
#include <cstring>
#include <stdexcept>
#include <sstream> // std::stringstream

Document::Document(const std::string &name,
                   const std::string &location,
                   const std::string &extension)
    : Object(name, location, extension){};

void Document::write_line(const std::string &line)
{
    lines.push_back(line);
}

std::string Document::read_line()
{
    return read_line(lineIndex);
}

std::string Document::read_line(const unsigned line)
{
    if (line > lines.size() || line == 0)
    {
        throw std::out_of_range("Out of range");
    }

    lineIndex = line;
    std::string lastLine = lines[lineIndex - 1];
    ++lineIndex;
    return lastLine;
};

bool Document::operator==(const Comparable *other) const
{
    auto otherCasted = dynamic_cast<Document *>(const_cast<Comparable *>(other));

    if (otherCasted == nullptr)
    {
        return false;
    }

    if (this->lines.size() != otherCasted->lines.size())
    {
        return false;
    }

    size_t linesCount = lines.size();

    for (size_t i = 0; i < linesCount; i++)
    {
        if (lines[i] != otherCasted->lines[i])
        {
            return false;
        }
    }

    return true;
}

bool Document::operator!=(const Comparable *other) const
{
    return !this->operator==(other);
}

Object *Document::clone() const
{
    return new Document(*this);
}

std::string Document::debug_print() const
{
    std::string debugInfo = "";

    size_t totalLines = lines.size();
    for (size_t i = 1; i <= totalLines; i++)
    {
        debugInfo += "Line " + std::to_string(i) + ":" + lines[i - 1] + "\n";
    }

    return debugInfo;
}

std::string Document::to_string() const
{
    std::string header = Object::to_string();

    std::string lines = "";
    for (const auto& line : this->lines)
    {
        lines += line + "\n";
    }

    return header + lines;
}

void Document::from_string(const std::string &info)
{
    std::stringstream ss(info);
    ss >> name >> location >> extension;

    ss.ignore(); // Ignore emprty line

    std::string line;
    while (std::getline(ss, line))
    {
        write_line(line);
    }
}
