#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../YuGiOh/MagicCard.hpp"
#include "../YuGiOh/MonsterCard.hpp"
#include "../YuGiOh/PendulumCard.hpp"

TEST_CASE("RARITY_COMPARISON", "[CARD][MONSTERCARD][MAGICCARD][PENDULUMCARD]") {
  int pendulumRarity = 20;
  int magicRarity = 10;
  int monsterRarity = 25;
  PendulumCard pendulumCard("PendulumName", "PendulumEffect", pendulumRarity,
                            20, 30, MagicCard::TRAP, 8);
  MagicCard magicCard("MagicName", "MagicEffect", magicRarity, MagicCard::BUFF);
  MonsterCard monsterCard("MonsterName", "MonsterEffect", monsterRarity, 20,
                          30);

  REQUIRE(pendulumCard > magicCard);
  REQUIRE(pendulumCard < monsterCard);
  REQUIRE(magicCard < monsterCard);
  REQUIRE_FALSE(magicCard > monsterCard);
  REQUIRE_FALSE(pendulumCard > pendulumCard);
}
