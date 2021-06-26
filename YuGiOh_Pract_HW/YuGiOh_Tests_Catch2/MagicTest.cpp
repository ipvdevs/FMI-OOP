#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../YuGiOh/MagicCard.hpp"

// DEFAULT TEST MAGIC CARD
std::string cardName = "MagicName";
std::string cardEffect = "MagicEffect";
unsigned int rarity = 15;
MagicCard::Type type = MagicCard::SPELL;

TEST_CASE("MAGIC_CARD_CONSTRUCTORS_WITH_PARAMETERS", "[MAGICCARD]") {
  MagicCard magicCard(cardName, cardEffect, rarity, type);

  REQUIRE(magicCard.getName() == cardName);
  REQUIRE(magicCard.getEffect() == cardEffect);
  REQUIRE(magicCard.getType() == type);
}

TEST_CASE("MAGIC_CARD_NEGATIVE_RARITY", "[MAGICCARD]") {
  MagicCard::Type trapType = MagicCard::TRAP;
  MagicCard magicCard("generic", "generic", -123, trapType);

  REQUIRE(magicCard.getRarity() >= 0);  // Rarity should not be negative
  REQUIRE(magicCard.getType() == trapType);
}

TEST_CASE("MAGIC_CARD_TYPE_TO_STRING", "[MAGICCARD]") {
  MagicCard buff("", "", 0, MagicCard::BUFF);
  MagicCard spell("", "", 0, MagicCard::SPELL);
  MagicCard trap("", "", 0, MagicCard::TRAP);
  MagicCard no_type("", "", 0, MagicCard::NO_TYPE);

  REQUIRE(buff.getTypeToString() == "BUFF");
  REQUIRE(spell.getTypeToString() == "SPELL");
  REQUIRE(trap.getTypeToString() == "TRAP");
  REQUIRE(no_type.getTypeToString() == "NO_TYPE");
}

TEST_CASE("COMPARE_MAGIC_BY_RARITY_OPERATORS", "[COMPARE]") {
  int lhsRarity = 6;
  int rhsRarity = 7;
  MagicCard lhs("generic", "generic", lhsRarity, type);
  MagicCard rhs("generic", "generic", rhsRarity, type);

  REQUIRE(lhs < rhs);        // operator<
  REQUIRE_FALSE(rhs < lhs);  // operator<
  REQUIRE(rhs > lhs);        // operator>
  REQUIRE_FALSE(lhs > rhs);  // operator>
}

TEST_CASE("MAGIC_TOSTRING", "[STRING]") {
  // Arrange
  MagicCard magicCard(cardName, cardEffect, rarity, type);

  std::string excpect =
      "MagicName|"
      "MagicEffect|"
      "15|SPELL";

  // Act
  std::string magicString = magicCard.toString();

  // Assert
  REQUIRE(magicString == excpect);
}
