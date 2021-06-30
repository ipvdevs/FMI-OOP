#include "ElectionResultsDatabase.hpp"

std::istream& operator>>(std::istream& input, ElectionResultsDatabase& database) {
  SectionVotes section;
  while (input >> section) {
    database.votesBySections.push_back(section);
  }

  return input;
}

std::ostream& operator<<(std::ostream& output, const ElectionResultsDatabase& database) {
  for (auto votesBySection : database.votesBySections) {
    output << votesBySection.votesForParty(PARTY1) << ' '
           << votesBySection.votesForParty(PARTY2) << ' '
           << votesBySection.votesForParty(PARTY3) << '\n';
  }

  return output;
}

void ElectionResultsDatabase::addResultsFromFile(const char* filename) {
  std::ifstream votesInput;
  votesInput.open(filename);

  if (!votesInput.is_open()) {
    // Error
    return;
  }

  votesInput >> *this;

  votesInput.close();
}

int ElectionResultsDatabase::numberOfSections() const {
  return votesBySections.size();
}

int ElectionResultsDatabase::votesForParty(Party party_id) const {
  int totalVotes = 0;
  for (auto votesBySection : votesBySections) {
    totalVotes += votesBySection.votesForParty(party_id);
  }
  return totalVotes;
}

Party ElectionResultsDatabase::winningParty() const {
  Party winningParty = PARTY1;

  int party1Votes = votesForParty(PARTY1);
  int party2Votes = votesForParty(PARTY2);
  int party3Votes = votesForParty(PARTY3);

  int winningVotes = std::max(party1Votes, std::max(party2Votes, party3Votes));

  if (winningVotes == party1Votes) {
    winningParty = PARTY1;
  } else if (winningVotes == party2Votes) {
    winningParty = PARTY2;
  } else if (winningVotes == party3Votes) {
    winningParty = PARTY3;
  }

  return winningParty;
}

