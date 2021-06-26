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

#ifndef YUGIOH_MONSTERCARD_HPP_
#define YUGIOH_MONSTERCARD_HPP_

#include "Card.hpp"

class MonsterCard : virtual public Card {
 public:
  explicit MonsterCard(const std::string& name = "",
                       const std::string& effect = "",
                       unsigned int rarity = 0,
                       unsigned int attackPoints = 0,
                       unsigned int defensePoints = 0);

  unsigned int getAttackPoints() const;
  unsigned int getDefensePoints() const;

  std::string toString() override;

  ~MonsterCard() override = default;
 private:
  unsigned int attackPoints;
  unsigned int defensePoints;
};

#endif //YUGIOH_MONSTERCARD_HPP_
