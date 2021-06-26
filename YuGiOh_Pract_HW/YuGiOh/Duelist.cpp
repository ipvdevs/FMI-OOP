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

#include "Duelist.hpp"
#include <fstream>
#include <iostream>

Duelist::Duelist(const std::string& name, const Deck& deck)
    : name(name), deck(deck) {}

void Duelist::setName(const std::string& newName) {
  name = newName;
}

std::string Duelist::getName() const {
  return name;
}

Deck& Duelist::getDeck() {
  return deck;
}

int Duelist::duel(Duelist& opponent) {
  if (this->deck.cardsCount() != opponent.deck.cardsCount()) {
    std::cerr << "Duel cannot be held. Cards count is different!" << '\n';
    return 0;
  }

  this->deck.shuffle();
  opponent.deck.shuffle();

  size_t cardsCount = this->deck.cardsCount();

  int hostPoints = 0, opponentPoints = 0;
  for (size_t i = 0; i < cardsCount; ++i) {
    Card* lhs = this->deck.getCardAt((int) i);
    Card* rhs = opponent.deck.getCardAt((int) i);

    if (*lhs > *rhs) {
      ++hostPoints;
    } else if (*lhs < *rhs) {
      ++opponentPoints;
    }
  }

  if (hostPoints > opponentPoints) {
    std::cout << this->name << " is winner with " << std::to_string(hostPoints) << " points!" << "\n";
    return 1;
  } else if (hostPoints < opponentPoints) {
    std::cout << opponent.name << " is winner with " << std::to_string(opponentPoints) << " points!" << "\n";
    return -1;
  }

  std::cout << "Draw!" << "\n";
  return 0;
}

std::ostream& operator<<(std::ostream& out, const Duelist& duelist) {
  std::string heading = duelist.deck.getName() + "|"
      + std::to_string(duelist.deck.cardsCount()) + "|"
      + std::to_string(duelist.deck.monsterCount()) + "|"
      + std::to_string(duelist.deck.magicCount()) + "|"
      + std::to_string(duelist.deck.pendulumCount()) + "|";

  out << heading << std::endl;
  out << duelist.deck;

  return out;
}

bool Duelist::saveDeck(const std::string& fileName) const {
  std::ofstream writeFile(fileName, std::ios::out);

  if (!writeFile.is_open()) {
    return false;
  }

  writeFile << *this;

  writeFile.close();
  return true;
}

bool Duelist::loadDeck(const std::string& fileName) {
  std::ifstream readFile(fileName);

  if (!readFile.is_open()) {
    return false;
  }

  std::string headingLine;
  std::getline(readFile, headingLine, '|');
  if (headingLine.empty()) {
    std::cerr << "File is empty!" << std::endl;
    return false;
  }

  deck.setName(headingLine);
  readFile >> deck;
  readFile.close();
  return true;
}



