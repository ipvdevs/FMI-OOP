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

#include <stdexcept>
#include "PendulumCard.hpp"

PendulumCard::PendulumCard(const std::string& name,
                           const std::string& effect,
                           unsigned int rarity,
                           unsigned int attackPoints,
                           unsigned int defensePoints,
                           MagicCard::Type type,
                           short pendulumScale)
    : Card(name, effect, rarity, CardType::PENDULUM),
      MonsterCard(name, effect, rarity, attackPoints, defensePoints),
      MagicCard(name, effect, rarity, type) {
  if (pendulumScale < MIN_PENDULUM_SCALE || pendulumScale > MAX_PENDULUM_SCALE) {
    throw std::invalid_argument("A pendulum scale must be in the range [1, 13]");
  }

  this->pendulumScale = pendulumScale;
}

short PendulumCard::getPendulumScale() const {
  return pendulumScale;
}

std::string PendulumCard::toString() {
  return MonsterCard::toString() + "|" + std::to_string(pendulumScale) + "|" + getTypeToString();
}


