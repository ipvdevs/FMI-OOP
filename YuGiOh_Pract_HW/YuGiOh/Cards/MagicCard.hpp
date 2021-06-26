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

#ifndef YUGIOH_MAGICCARD_HPP_
#define YUGIOH_MAGICCARD_HPP_

#include "Card.hpp"
#include <string>

class MagicCard : virtual public Card {
 public:
  enum Type {
    TRAP,
    BUFF,
    SPELL,
    NO_TYPE
  };

  explicit MagicCard(const std::string& name = "",
                     const std::string& effect = "",
                     unsigned int rarity = 0,
                     Type type = NO_TYPE);

  Type getType() const;
  std::string getTypeToString() const;
  static Type convertStringToType(const std::string& strType);
  std::string toString() override;

  ~MagicCard() override = default;
 private:
  Type type;
};

#endif //YUGIOH_MAGICCARD_HPP_
