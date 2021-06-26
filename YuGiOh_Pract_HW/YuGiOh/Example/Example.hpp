#ifndef YUGIOH_EXAMPLE_HPP_
#define YUGIOH_EXAMPLE_HPP_

#include "../Duelist.hpp"

void Example() {
  MonsterCard dragon("Blue-Eyes White Dragon",
                     "This legendary dragon is a powerful engine of destruction.",
                     43,
                     3000, 2500);

  MonsterCard magician("Dark Magician",
                       "The ultimate wizard.",
                       23,
                       2500, 2100);

  MagicCard swords("Swords of Revealing Light",
                   "Your opponent's monsters cannot declare an attack.",
                   123,
                   MagicCard::SPELL);

  MagicCard cylinder("Magic Cylinder",
                     "Inflict damage to your opponent equal to its ATK.",
                     9,
                     MagicCard::TRAP);

  PendulumCard timegazer("Timegazer Magician",
                         "Your opponent cannot activate Trap Magic Cards",
                         3,
                         1200, 600,
                         MagicCard::SPELL,
                         8);

  Duelist firstDuelist("Harry Hacker");

  firstDuelist.getDeck().setName("Magician Deck");

  firstDuelist.getDeck().addCard(&dragon);
  firstDuelist.getDeck().addCard(&swords);
  firstDuelist.getDeck().addCard(&magician);
  firstDuelist.getDeck().addCard(&cylinder);
  firstDuelist.getDeck().addCard(&timegazer);

  firstDuelist.getDeck().shuffle();

  firstDuelist.saveDeck("magician_deck.txt");

  MagicCard box("Mystic Box", "Destroy one monster.", 0, MagicCard::SPELL);
  firstDuelist.getDeck().replaceCard(1, &box);

  Duelist secondDuelist("Tim Tester");
  secondDuelist.getDeck().addCard(&dragon);
  secondDuelist.getDeck().addCard(&swords);
  secondDuelist.getDeck().addCard(&magician);
  secondDuelist.getDeck().addCard(&cylinder);
  secondDuelist.getDeck().addCard(&timegazer);
}

#endif //YUGIOH_EXAMPLE_HPP_
