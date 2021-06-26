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

#ifndef YUGIOH_DECK_HPP_
#define YUGIOH_DECK_HPP_

#include "../Cards/Card.hpp"
#include "../Cards/MonsterCard.hpp"
#include "../Cards/MagicCard.hpp"
#include "../Cards/PendulumCard.hpp"

#include <string>
#include <vector>

class Deck {
 public:
  explicit Deck(const std::string& name = "");
  Deck(const Deck& other);
  Deck& operator=(const Deck& other);
  ~Deck();

  std::string getName() const;
  void setName(const std::string& newName);

  unsigned int cardsCount() const;
  unsigned int monsterCount() const;
  unsigned int magicCount() const;
  unsigned int pendulumCount() const;

  Card* getCardAt(int index);

  bool addCard(Card* card);
  bool replaceCard(int index, Card* card);
  void shuffle();
  void clear();

  friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
  friend std::istream& operator>>(std::istream& in, Deck& deck);

 private:
  std::string name;
  std::vector<Card*> deck;
  unsigned int monsterCardsCount = 0;
  unsigned int magicCardsCount = 0;
  unsigned int pendulumCardsCount = 0;

  /* Helper functions */
  void addCardByTokens(const std::vector<std::string>& tokens);
  void copyDeck(const Deck& other);
  static Card* copyCard(Card* card);
};

#endif //YUGIOH_DECK_HPP_
