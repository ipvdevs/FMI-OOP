#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include "SectionVotes.hpp"

class ElectionResultsDatabase {

 public:
  void addResultsFromFile(const char* filename);
  int numberOfSections() const;
  int votesForParty(Party) const;
  Party winningParty() const;

  friend std::istream& operator>>(std::istream&, ElectionResultsDatabase&);
  friend std::ostream& operator<<(std::ostream&, const ElectionResultsDatabase&);
 private:
  std::vector<SectionVotes> votesBySections;
};
