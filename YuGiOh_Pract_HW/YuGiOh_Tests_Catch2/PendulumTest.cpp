#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../YuGiOh/PendulumCard.hpp"

// DEFAULT TEST PENDULUM
std::string cardName = "PendulumName";
std::string cardEffect = "PendulumEffect";
unsigned int rarity = 20;
unsigned int attackPoints = 100;
unsigned int defensePoints = 200;
MagicCard::Type type = MagicCard::BUFF;
short pendulumScale = 3;

TEST_CASE("PENDULUM_CARD_CONSTRUCTORS_WITH_PARAMETERS",
          "[CONSTRUCTORS][GETTERS]") {
  PendulumCard pendulumCard(cardName, cardEffect, rarity, attackPoints,
                            defensePoints, type, pendulumScale);

  REQUIRE(pendulumCard.getName() == cardName);
  REQUIRE(pendulumCard.getEffect() == cardEffect);
  REQUIRE(pendulumCard.getRarity() == rarity);
  REQUIRE(pendulumCard.getAttackPoints() == attackPoints);
  REQUIRE(pendulumCard.getDefensePoints() == defensePoints);
  REQUIRE(pendulumCard.getType() == type);
  REQUIRE(pendulumCard.getPendulumScale() == pendulumScale);
}

TEST_CASE("PENDULUM_CARD_NEGATIVE_RARITY_ATTACKPOINTS_DEFENSEPOINTS",
          "[CONSTRUCTORS][GETTERS]") {
  PendulumCard pendulumCard("generic", "generic", -1, -2, -3,
                            MagicCard::NO_TYPE);

  REQUIRE(pendulumCard.getRarity() >= 0);
  REQUIRE(pendulumCard.getAttackPoints() >= 0);
  REQUIRE(pendulumCard.getDefensePoints() >= 0);
  REQUIRE(pendulumCard.getType() == MagicCard::NO_TYPE);
}

TEST_CASE("PENDULUM_CARD_INVALID_PENDULUM_SCALE", "[CONSTRUCTORS]") {
  PendulumCard pendulumCard1("generic", "generic", 1, 2, 3, MagicCard::NO_TYPE,
                             1);

  REQUIRE(pendulumCard1.getPendulumScale() == 1);

  REQUIRE_THROWS(
      PendulumCard("generic", "generic", 1, 2, 3, MagicCard::NO_TYPE, 0),
      "A pendulum scale must be in the range [1, 13]");

  REQUIRE_THROWS(
      PendulumCard("generic", "generic", 1, 2, 3, MagicCard::NO_TYPE, 14),
      "A pendulum scale must be in the range [1, 13]");

  REQUIRE_THROWS(
      PendulumCard("generic", "generic", 1, 2, 3, MagicCard::NO_TYPE, -1),
      "A pendulum scale must be in the range [1, 13]");
}

TEST_CASE("PENDULUM_TOSTRING", "[STRING]") {
  // Arrange
  PendulumCard pendulumCard(cardName, cardEffect, rarity, attackPoints,
                            defensePoints, type, pendulumScale);
  std::string excpect =
      "PendulumName|"
      "PendulumEffect|"
      "20|100|200|3|BUFF";

  // Act
  std::string pendulumToString = pendulumCard.toString();

  // Assert
  REQUIRE(pendulumToString == excpect);
}
