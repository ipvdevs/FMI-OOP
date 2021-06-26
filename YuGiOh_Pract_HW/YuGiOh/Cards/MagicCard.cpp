/**
 * Solution to homework assignment 4
 * Object Oriented Programming Course
 * Faculty of Mathematics and Informatics of Sofia University
 * Summer semester 2020/2021
 *
 * @author Ivan Penev
 * @idnumber 62535
 * @task 4
 * @compiler GCC
 */

#include "MagicCard.hpp"

MagicCard::MagicCard(const std::string& name,
                     const std::string& effect,
                     unsigned int rarity,
                     Type type)
    : Card(name, effect, rarity, CardType::MAGIC),
      type(type) {}

MagicCard::Type MagicCard::getType() const {
  return type;
}

std::string MagicCard::getTypeToString() const {
  switch (type) {
    case TRAP: return std::string("TRAP");
    case BUFF: return std::string("BUFF");
    case SPELL: return std::string("SPELL");
    default: return std::string("NO_TYPE");
  }
}

MagicCard::Type MagicCard::convertStringToType(const std::string& strType) {
  if (strType == "TRAP") {
    return Type::TRAP;
  } else if (strType == "BUFF") {
    return Type::BUFF;
  } else if (strType == "SPELL") {
    return Type::SPELL;
  }

  return Type::NO_TYPE;
}

std::string MagicCard::toString() {
  return Card::toString() + getTypeToString();
}

