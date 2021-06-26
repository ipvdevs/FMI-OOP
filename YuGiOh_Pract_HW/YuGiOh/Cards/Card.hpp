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

#ifndef YUGIOH_CARD_HPP_
#define YUGIOH_CARD_HPP_

#include <string>

class Card {
 public:
  enum CardType { CARD, MONSTER, MAGIC, PENDULUM };
 
  explicit Card(const std::string& name = "",
                const std::string& effect = "",
                unsigned int rarity = 0,
                CardType cardType = CARD);

  std::string getName() const;
  std::string getEffect() const;
  unsigned int getRarity() const;
  CardType getCardType() const;

  virtual bool operator<(const Card& card) const;
  virtual bool operator>(const Card& card) const;

  virtual std::string toString() = 0;

  virtual ~Card() = default;
 private:
  std::string name;
  std::string effect;
  unsigned int rarity;
  CardType cardType;
};

#endif //YUGIOH_CARD_HPP_
