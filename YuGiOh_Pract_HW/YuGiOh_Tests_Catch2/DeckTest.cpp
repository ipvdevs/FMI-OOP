#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../YuGiOh/Deck.hpp"

TEST_CASE("DECK_CONSTRUCTORS", "[DECK]") {
  std::string name = "DeckName";
  Deck deck(name);
  Deck def;

  REQUIRE(deck.getName() == name);
  REQUIRE(def.getName() == "");
}

TEST_CASE("ADD_CARD", "[DECK]") {
  Deck deck;

  auto monster_card = MonsterCard("Spider", "Venomous", 3, 300, 100);
  auto magic_card =
      MagicCard("Dark Magician", "Debug magic effect", 7, MagicCard::SPELL);
  auto pendulum_card = PendulumCard("Hope Pendulum", "Pendulum effect", 10,
                                    2000, 2500, MagicCard::SPELL, 10);

  CHECK(deck.addCard(&monster_card));
  CHECK(deck.addCard(&magic_card));
  CHECK(deck.addCard(&pendulum_card));

  REQUIRE(deck.cardsCount() == 3);
  REQUIRE(deck.magicCount() == 1);
  REQUIRE(deck.monsterCount() == 1);
  REQUIRE(deck.pendulumCount() == 1);

  REQUIRE_FALSE(deck.getCardAt(0) == &monster_card);
  REQUIRE_FALSE(deck.getCardAt(1) == &magic_card);
  REQUIRE_FALSE(deck.getCardAt(2) == &pendulum_card);
}

TEST_CASE("ADD_CARD_NULLPTR", "[DECK]") {
  Deck deck;

  REQUIRE_FALSE(deck.addCard(nullptr));
}

TEST_CASE("COPY_OPERATOR=", "[DECK]") {
  std::string initName = "initName";
  Deck deck(initName);
  auto monster_card = MonsterCard("Spider", "Venomous", 3, 300, 100);
  auto magic_card =
      MagicCard("Dark Magician", "Debug magic effect", 7, MagicCard::SPELL);
  auto pendulum_card = PendulumCard("Hope Pendulum", "Pendulum effect", 10,
                                    2000, 2500, MagicCard::SPELL, 10);

  deck.addCard(&monster_card);
  deck.addCard(&magic_card);
  deck.addCard(&pendulum_card);
  Deck copy(deck);
  Deck assignedCopy;
  assignedCopy = copy;

  REQUIRE(copy.getName() == initName);
  REQUIRE(assignedCopy.getName() == initName);

  REQUIRE(deck.cardsCount() == copy.cardsCount());
  REQUIRE(deck.monsterCount() == copy.monsterCount());
  REQUIRE(deck.magicCount() == copy.magicCount());
  REQUIRE(deck.pendulumCount() == copy.pendulumCount());
  REQUIRE(deck.cardsCount() == assignedCopy.cardsCount());
  REQUIRE(deck.monsterCount() == assignedCopy.monsterCount());
  REQUIRE(deck.magicCount() == assignedCopy.magicCount());
  REQUIRE(deck.pendulumCount() == assignedCopy.pendulumCount());

  REQUIRE_FALSE(copy.getCardAt(0) == &monster_card);
  REQUIRE_FALSE(copy.getCardAt(1) == &magic_card);
  REQUIRE_FALSE(copy.getCardAt(2) == &pendulum_card);

  REQUIRE_FALSE(assignedCopy.getCardAt(0) == &monster_card);
  REQUIRE_FALSE(assignedCopy.getCardAt(1) == &magic_card);
  REQUIRE_FALSE(assignedCopy.getCardAt(2) == &pendulum_card);
}

TEST_CASE("REPLACE", "[DECK]") {
  Deck def;

  PendulumCard pendulumCard("PendulumName", "PendulumEffect", 20, 20, 30,
                            MagicCard::TRAP, 8);
  MagicCard magicCard("MagicName", "MagicEffect", 10, MagicCard::BUFF);
  MonsterCard monsterCard("MonsterName", "MonsterEffect", 25, 20, 30);

  def.addCard(&pendulumCard);
  def.addCard(&magicCard);
  def.addCard(&monsterCard);

  MonsterCard newMonster("New Monster", "New effect", 10, 10, 10);
  MagicCard newMagic("New Magic", "New effect", 10, MagicCard::TRAP);
  PendulumCard newPendulum("New PendulumCard", "New effect", 10, 10, 10,
                           MagicCard::BUFF, 5);

  REQUIRE(def.replaceCard(2, &newMonster));
  REQUIRE(def.replaceCard(1, &newMagic));
  REQUIRE(def.replaceCard(0, &newPendulum));
}

TEST_CASE("REPLACE_INVALID_TYPE", "[DECK]") {
  Deck def;

  PendulumCard pendulumCard("PendulumName", "PendulumEffect", 20, 20, 30,
                            MagicCard::TRAP, 8);
  MagicCard magicCard("MagicName", "MagicEffect", 10, MagicCard::BUFF);
  MonsterCard monsterCard("MonsterName", "MonsterEffect", 25, 20, 30);

  def.addCard(&pendulumCard);
  def.addCard(&magicCard);
  def.addCard(&monsterCard);

  MonsterCard newMonster("New Monster", "New effect", 10, 10, 10);
  MagicCard newMagic("New Magic", "New effect", 10, MagicCard::TRAP);
  PendulumCard newPendulum("New PendulumCard", "New effect", 10, 10, 10,
                           MagicCard::BUFF, 5);

  REQUIRE_FALSE(def.replaceCard(0, &newMonster));
  REQUIRE_FALSE(def.replaceCard(2, &newMagic));
  REQUIRE_FALSE(def.replaceCard(1, &newPendulum));
}

TEST_CASE("REPLACE_AT_INVALID_INDEX", "[DECK]") {
  Deck def;

  MonsterCard monsterCard("MonsterName", "MonsterEffect", 25, 20, 30);

  def.addCard(&monsterCard);

  MonsterCard newMonster("New Monster", "New effect", 10, 10, 10);

  REQUIRE_THROWS(def.replaceCard(-1, &newMonster));
  REQUIRE_THROWS(def.replaceCard(1, &newMonster));
  REQUIRE_THROWS(def.replaceCard(2, &newMonster));
}

TEST_CASE("CLEAR_DECK", "[DECK]") {
  Deck def;

  PendulumCard pendulumCard("PendulumName", "PendulumEffect", 20, 20, 30,
                            MagicCard::TRAP, 8);
  MagicCard magicCard("MagicName", "MagicEffect", 10, MagicCard::BUFF);
  MonsterCard monsterCard("MonsterName", "MonsterEffect", 25, 20, 30);

  def.addCard(&pendulumCard);
  def.addCard(&magicCard);
  def.addCard(&monsterCard);

  def.clear();

  REQUIRE(def.cardsCount() == 0);
  REQUIRE(def.monsterCount() == 0);
  REQUIRE(def.magicCount() == 0);
  REQUIRE(def.pendulumCount() == 0);
  REQUIRE_THROWS(def.getCardAt(0));
}
