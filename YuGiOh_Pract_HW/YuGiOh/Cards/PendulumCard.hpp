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

#ifndef YUGIOH_PENDULUMCARD_HPP_
#define YUGIOH_PENDULUMCARD_HPP_

#include "MonsterCard.hpp"
#include "MagicCard.hpp"

#define MIN_PENDULUM_SCALE 1
#define MAX_PENDULUM_SCALE 13

class PendulumCard : public MagicCard, public MonsterCard {
 public:
  explicit PendulumCard(const std::string& name = "",
                        const std::string& effect = "",
                        unsigned int rarity = 0,
                        unsigned int attackPoints = 0,
                        unsigned int defensePoints = 0,
                        Type type = NO_TYPE,
                        short pendulumScale = 1);

  short getPendulumScale() const;
  std::string toString() override;

 private:
  short pendulumScale;
};

#endif //YUGIOH_PENDULUMCARD_HPP_
