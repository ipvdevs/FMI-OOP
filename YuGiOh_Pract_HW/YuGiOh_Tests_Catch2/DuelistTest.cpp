#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../YuGiOh/Duelist.hpp"

// Duel codes
#define LOSE_CODE -1
#define DRAW_CODE 0
#define WIN_CODE 1

TEST_CASE("DUELIST_CONSTRUCTOR_GET_SET_NAME",
          "[CONSTRUCTORS][GETTERS][SETTERS]") {
  std::string name = "Seto Kaiba";
  std::string opponentName = "Yugi Muto";
  Duelist duelist1(name);
  Duelist duelist2;

  duelist2.setName(opponentName);

  REQUIRE(duelist1.getName() == name);
  REQUIRE(duelist2.getName() == opponentName);
}

TEST_CASE("DUELIST_ACCESS_DECK", "[DECK]") {
  std::string duelistName = "Kaiba";
  Duelist duelist(duelistName);
  std::string deckName = "Kaiba's Deck";

  duelist.getDeck().setName(deckName);

  CHECK(duelist.getDeck().getName() == deckName);
  REQUIRE(duelist.getDeck().cardsCount() == 0);
  REQUIRE(duelist.getDeck().monsterCount() == 0);
  REQUIRE(duelist.getDeck().magicCount() == 0);
  REQUIRE(duelist.getDeck().pendulumCount() == 0);
}

TEST_CASE("DUEL_1", "[DUEL]") {
  Duelist host("Host");
  Duelist opponent("Opponent");

  PendulumCard hostPendulumCard("PendulumName", "PendulumEffect", 101, 20, 30,
                                MagicCard::TRAP, 8);
  MagicCard hostMagicCard("MagicName", "MagicEffect", 102, MagicCard::BUFF);
  MonsterCard hostMonsterCard("MonsterName", "MonsterEffect", 103, 20, 30);

  PendulumCard opponentPendulumCard("PendulumName", "PendulumEffect", 50, 20,
                                    30, MagicCard::TRAP, 8);
  MagicCard opponentMagicCard("MagicName", "MagicEffect", 51, MagicCard::BUFF);
  MonsterCard opponentMonsterCard("MonsterName", "MonsterEffect", 52, 20, 30);

  host.getDeck().addCard(&hostPendulumCard);
  host.getDeck().addCard(&hostMagicCard);
  host.getDeck().addCard(&hostMonsterCard);

  opponent.getDeck().addCard(&opponentPendulumCard);
  opponent.getDeck().addCard(&opponentMagicCard);
  opponent.getDeck().addCard(&opponentMonsterCard);

  REQUIRE(host.duel(opponent) == WIN_CODE);
}

TEST_CASE("DUEL_2", "[DUEL]") {
  Duelist host("Host");
  Duelist opponent("Opponent");

  PendulumCard hostPendulumCard("PendulumName", "PendulumEffect", 101, 20, 30,
                                MagicCard::TRAP, 8);
  MagicCard hostMagicCard("MagicName", "MagicEffect", 102, MagicCard::BUFF);
  MonsterCard hostMonsterCard("MonsterName", "MonsterEffect", 103, 20, 30);

  PendulumCard opponentPendulumCard("PendulumName", "PendulumEffect", 50, 20,
                                    30, MagicCard::TRAP, 8);
  MagicCard opponentMagicCard("MagicName", "MagicEffect", 51, MagicCard::BUFF);
  MonsterCard opponentMonsterCard("MonsterName", "MonsterEffect", 52, 20, 30);

  host.getDeck().addCard(&hostPendulumCard);
  host.getDeck().addCard(&hostMagicCard);
  host.getDeck().addCard(&hostMonsterCard);

  opponent.getDeck().addCard(&opponentPendulumCard);
  opponent.getDeck().addCard(&opponentMagicCard);
  opponent.getDeck().addCard(&opponentMonsterCard);

  REQUIRE(opponent.duel(host) == LOSE_CODE);
  REQUIRE(host.duel(opponent) == WIN_CODE);
  REQUIRE_FALSE(host.duel(opponent) == DRAW_CODE);
  REQUIRE_FALSE(opponent.duel(host) == DRAW_CODE);
}

TEST_CASE("DUEL_DRAW", "[DUEL]") {
  Duelist host("Host");
  Duelist opponent("Opponent");

  PendulumCard hostPendulumCard("PendulumName", "PendulumEffect", 555, 20, 30,
                                MagicCard::TRAP, 8);
  MagicCard hostMagicCard("MagicName", "MagicEffect", 555, MagicCard::BUFF);
  MonsterCard hostMonsterCard("MonsterName", "MonsterEffect", 555, 20, 30);

  PendulumCard opponentPendulumCard("PendulumName", "PendulumEffect", 555, 20,
                                    30, MagicCard::TRAP, 8);
  MagicCard opponentMagicCard("MagicName", "MagicEffect", 555, MagicCard::BUFF);
  MonsterCard opponentMonsterCard("MonsterName", "MonsterEffect", 555, 20, 30);

  host.getDeck().addCard(&hostPendulumCard);
  host.getDeck().addCard(&hostMagicCard);
  host.getDeck().addCard(&hostMonsterCard);

  opponent.getDeck().addCard(&opponentPendulumCard);
  opponent.getDeck().addCard(&opponentMagicCard);
  opponent.getDeck().addCard(&opponentMonsterCard);

  REQUIRE(opponent.duel(host) == DRAW_CODE);
  REQUIRE(host.duel(opponent) == DRAW_CODE);
  REQUIRE_FALSE(opponent.duel(host) == WIN_CODE);
  REQUIRE_FALSE(opponent.duel(host) == LOSE_CODE);
  REQUIRE_FALSE(host.duel(opponent) == WIN_CODE);
  REQUIRE_FALSE(host.duel(opponent) == LOSE_CODE);
}
