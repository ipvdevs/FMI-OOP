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

#include "Card.hpp"

Card::Card(const std::string& name,
           const std::string& effect,
           unsigned int rarity,
           CardType cardType)
    : name(name), effect(effect), rarity(rarity), cardType(cardType) {}

std::string Card::getName() const {
  return name;
}

std::string Card::getEffect() const {
  return effect;
}

unsigned int Card::getRarity() const {
  return rarity;
}

Card::CardType Card::getCardType() const {
  return cardType;
}

bool Card::operator<(const Card& card) const {
  return this->rarity < card.rarity;
}

bool Card::operator>(const Card& card) const {
  return this->rarity > card.rarity;
}

std::string Card::toString() {
  return std::string(name + "|" + effect + "|" + std::to_string(rarity) + "|");
}
