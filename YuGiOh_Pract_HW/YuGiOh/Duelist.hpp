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

#ifndef YUGIOH_DUELIST_HPP_
#define YUGIOH_DUELIST_HPP_

#include <string>
#include "Deck/Deck.hpp"

class Duelist {
 public:
  explicit Duelist(const std::string& name = "", const Deck& deck = Deck());

  void setName(const std::string& newName);
  std::string getName() const;

  Deck& getDeck();

  int duel(Duelist& opponent);

  friend std::ostream& operator<<(std::ostream& out, const Duelist& duelist);

  bool saveDeck(const std::string& fileName) const;
  bool loadDeck(const std::string& fileName);

 private:
  std::string name;
  Deck deck;
};

#endif //YUGIOH_DUELIST_HPP_
