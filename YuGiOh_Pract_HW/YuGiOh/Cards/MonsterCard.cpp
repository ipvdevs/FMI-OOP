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

#include "MonsterCard.hpp"

MonsterCard::MonsterCard(const std::string& name,
                         const std::string& effect,
                         unsigned int rarity,
                         unsigned int attackPoints,
                         unsigned int defensePoints)
    : Card(name, effect, rarity, CardType::MONSTER),
      attackPoints(attackPoints),
      defensePoints(defensePoints) {}

unsigned int MonsterCard::getAttackPoints() const {
  return attackPoints;
}

unsigned int MonsterCard::getDefensePoints() const {
  return defensePoints;
}

std::string MonsterCard::toString() {
  return Card::toString()
      + std::to_string(attackPoints) + "|"
      + std::to_string(defensePoints);
}