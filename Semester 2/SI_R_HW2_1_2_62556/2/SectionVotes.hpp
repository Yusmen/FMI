#pragma once
#include <istream>

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{

public:

    SectionVotes(int party1Votes, int party2Votes, int party3Votes);
    SectionVotes();

    int votesForParty(Party) const;

    friend std::istream& operator>>(std::istream&, SectionVotes&);
    friend std::ostream& operator<<(std::ostream&, const SectionVotes&);

private:

    int party1Votes;
    int party2Votes;
    int party3Votes;

};