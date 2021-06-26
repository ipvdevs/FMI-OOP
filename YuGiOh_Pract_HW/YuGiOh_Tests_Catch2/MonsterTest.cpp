#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../YuGiOh/MonsterCard.hpp"

// DEFAULT TEST MONSTER
std::string cardName = "MonsterName";
std::string cardEffect = "MonsterEffect";
unsigned int rarity = 10;
unsigned int attackPoints = 20;
unsigned int defensePoints = 30;

TEST_CASE("MONSTER_CARD_CONSTRUCTORS_WITH_PARAMETERS", "[CONSTRUCTORS]") {
  MonsterCard monsterCard(cardName, cardEffect, rarity, attackPoints,
                          defensePoints);

  REQUIRE(monsterCard.getCardType() == Card::MONSTER);
  REQUIRE(monsterCard.getName() == cardName);
  REQUIRE(monsterCard.getEffect() == cardEffect);
  REQUIRE(monsterCard.getRarity() == rarity);
  REQUIRE(monsterCard.getAttackPoints() == attackPoints);
  REQUIRE(monsterCard.getDefensePoints() == defensePoints);
}

TEST_CASE("MONSTER_CARD_NEGATIVE_RARITY_ATTACKPOINTS_DEFENSEPOINTS_UNSIGNED",
          "[CONSTRUCTORS]") {
  MonsterCard monsterCard("generic", "generic", -1, -2, -3);

  REQUIRE(monsterCard.getRarity() >= 0);
  REQUIRE(monsterCard.getAttackPoints() >= 0);
  REQUIRE(monsterCard.getDefensePoints() >= 0);
}

TEST_CASE("COMPARE_MONSTERS_BY_RARITY_OPERATORS", "[COMPARE]") {
  int lhsRarity = 10;
  int rhsRarity = 20;
  MonsterCard lhs("generic", "generic", lhsRarity, 20, 30);
  MonsterCard rhs("generic", "generic", rhsRarity, 20, 30);

  REQUIRE(lhs < rhs);
  REQUIRE_FALSE(rhs < lhs);
  REQUIRE(rhs > lhs);
  REQUIRE_FALSE(lhs > rhs);
}

TEST_CASE("MONSTER_TOSTRING", "[STRING]") {
  // Arrange
  MonsterCard monsterCard(cardName, cardEffect, rarity, attackPoints,
                          defensePoints);
  std::string excpect =
      "MonsterName|"
      "MonsterEffect|"
      "10|20|30";

  // Act
  std::string monsterString = monsterCard.toString();

  // Assert
  REQUIRE(monsterString == excpect);
}


