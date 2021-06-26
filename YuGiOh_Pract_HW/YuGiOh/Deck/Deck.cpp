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

#include <stdexcept>    // Error handling
#include <chrono>       // Generate seed
#include <algorithm>    // std::shuffle
#include <random>       // Rand engine
#include <iostream>
#include <sstream>

#include "Deck.hpp"

Deck::Deck(const std::string& name)
    : name(name) {}

Deck::Deck(const Deck& other) {
  copyDeck(other);
}

Deck& Deck::operator=(const Deck& other) {
  if (this != &other) {
    Deck::clear();
    copyDeck(other);
  }

  return *this;
}

Deck::~Deck() {
  Deck::clear();
}

std::string Deck::getName() const {
  return name;
}

void Deck::setName(const std::string& newName) {
  name = newName;
}

unsigned int Deck::cardsCount() const {
  return deck.size();
}

unsigned int Deck::monsterCount() const {
  return monsterCardsCount;
}

unsigned int Deck::magicCount() const {
  return magicCardsCount;
}

unsigned int Deck::pendulumCount() const {
  return pendulumCardsCount;
}

Card* Deck::getCardAt(int index) {
  if (index < 0 || index > (int) (deck.size() - 1)) {
    throw std::out_of_range("Index out of range");
  }

  return deck[index];
}

bool Deck::addCard(Card* card) {
  if (card == nullptr) {
    return false;
  }

  try {
    deck.push_back(copyCard(card));
  } catch (std::invalid_argument& exception) {
    std::cerr << exception.what() << '\n';
    return false;
  }

  if (card->getCardType() == Card::PENDULUM) {
    ++pendulumCardsCount;
  } else if (card->getCardType() == Card::MONSTER) {
    ++monsterCardsCount;
  } else if (card->getCardType() == Card::MAGIC) {
    ++magicCardsCount;
  }

  return true;
}

bool Deck::replaceCard(int index, Card* card) {
  if (index < 0 || index > (int) (deck.size() - 1)) {
    throw std::out_of_range("Index out of range");
  }

  if (card == nullptr || card->getCardType() != deck[index]->getCardType()) {
    return false;
  }

  try {
    Card* replaceCard = copyCard(card); // Exception if card is not valid type
    delete deck[index];
    deck[index] = replaceCard;
  } catch (std::invalid_argument& exception) {
    std::cerr << exception.what() << '\n';
    return false;
  }

  return true;
}

void Deck::shuffle() {
  // Obtain seed (based on epoch time):
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine randEngine(seed);
  std::shuffle(deck.begin(), deck.end(), randEngine);
}

void Deck::clear() {
  for (auto& card : deck) {
    delete card;
  }

  magicCardsCount = 0;
  monsterCardsCount = 0;
  pendulumCardsCount = 0;
  deck.clear();
}

std::ostream& operator<<(std::ostream& out, const Deck& deck) {
  for (Card* card : deck.deck) {
    out << card->toString();
    out << std::endl;
  }

  return out;
}

std::istream& operator>>(std::istream& in, Deck& deck) {
  // Clear junk tokens from the first line
  std::string line;
  std::getline(in, line);

  const char delimiter = '|';
  while (!in.eof()) {
    std::getline(in, line);

    if (line.empty()) {
      break;
    }

    std::string token;
    std::istringstream tokenStream(line);

    std::vector<std::string> tokens;
    while (std::getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
    }

    deck.addCardByTokens(tokens);
  }

  return in;
}

/* Helper functions */

void Deck::addCardByTokens(const std::vector<std::string>& tokens) {
  const short MAGIC_CARD_TOKENS = 4;
  const short MONSTER_CARD_TOKENS = 5;
  const short PENDULUM_CARD_TOKENS = 7;

  int tokensCount = (int) tokens.size();

  if (tokensCount == MONSTER_CARD_TOKENS) {
    MonsterCard monsterToAdd = MonsterCard(tokens[0],
                                           tokens[1],
                                           std::stoi(tokens[2]),
                                           std::stoi(tokens[3]),
                                           std::stoi(tokens[4]));

    addCard(&monsterToAdd);
  } else if (tokensCount == MAGIC_CARD_TOKENS) {
    MagicCard magicToAdd =
        MagicCard(tokens[0],
                  tokens[1],
                  std::stoi(tokens[2]),
                  MagicCard::convertStringToType(tokens[3]));

    addCard(&magicToAdd);
  } else if (tokensCount == PENDULUM_CARD_TOKENS) {
    PendulumCard pendulumToAdd =
        PendulumCard(tokens[0],
                     tokens[1],
                     std::stoi(tokens[2]),
                     std::stoi(tokens[3]),
                     std::stoi(tokens[4]),
                     MagicCard::convertStringToType(tokens[6]),
                     (short) std::stoi(tokens[5]));

    addCard(&pendulumToAdd);
  } else {
    throw std::invalid_argument("Invalid card type.");
  }
}

Card* Deck::copyCard(Card* card) {
  if (card->getCardType() == Card::PENDULUM) {
    auto pendulum = dynamic_cast<PendulumCard*>(card);

    if (pendulum != nullptr) {
      return new PendulumCard(*pendulum);
    }

  } else if (card->getCardType() == Card::MONSTER) {
    auto monster = dynamic_cast<MonsterCard*>(card);

    if (monster != nullptr) {
      return new MonsterCard(*monster);
    }

  } else if (card->getCardType() == Card::MAGIC) {
    auto magic = dynamic_cast<MagicCard*>(card);

    if (magic != nullptr) {
      return new MagicCard(*magic);
    }
  }

  throw std::invalid_argument("Not a valid card type");
}

void Deck::copyDeck(const Deck& other) {
  for (auto card : other.deck) {
    deck.push_back(copyCard(card));
  }

  name = other.name;
  monsterCardsCount = other.monsterCardsCount;
  magicCardsCount = other.magicCardsCount;
  pendulumCardsCount = other.pendulumCardsCount;
}