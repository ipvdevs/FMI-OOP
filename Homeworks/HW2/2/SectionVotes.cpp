#include "SectionVotes.hpp"

SectionVotes::SectionVotes() {
  for (int& partiesVote : partiesVotes) {
    partiesVote = 0;
  }
}

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes) {
  partiesVotes[PARTY1] = party1Votes;
  partiesVotes[PARTY2] = party2Votes;
  partiesVotes[PARTY3] = party3Votes;
}

int SectionVotes::votesForParty(Party party) const {
  return partiesVotes[party];
}

std::istream& operator>>(std::istream& input, SectionVotes& section) {
  int votesForParty1 = 0, votesForParty2 = 0, votesForParty3 = 0;
  input >> votesForParty1 >> votesForParty2 >> votesForParty3;

  section = SectionVotes(votesForParty1, votesForParty2, votesForParty3);

  return input;
}

std::ostream& operator<<(std::ostream& output, const SectionVotes& section) {
  for (int partyID = 0; partyID < PARTIES_COUNT - 1; ++partyID) {
    output << section.partiesVotes[partyID] << ' ';
  }
  output << section.partiesVotes[PARTIES_COUNT - 1];

  return output;
}


