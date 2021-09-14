#pragma once
#include "SectionVotes.hpp"
#include <vector>
#include<iostream>
#include<fstream>
#include <algorithm>

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

class ElectionResultsDatabase
{

public:

    void addResultsFromFile(const char* filename);

    friend std::istream& operator>>(std::istream&, ElectionResultsDatabase&);
    friend std::ostream& operator<<(std::ostream&, const ElectionResultsDatabase&);

    int numberOfSections() const;

    int votesForParty(Party) const;

    Party winningParty() const;

private:
    std::vector<SectionVotes> sections;

};