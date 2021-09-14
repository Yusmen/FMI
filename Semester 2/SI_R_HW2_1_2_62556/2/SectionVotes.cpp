#include "SectionVotes.hpp"

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
{
	this->party1Votes = party1Votes;
	this->party2Votes = party2Votes;
	this->party3Votes = party3Votes;

}

SectionVotes::SectionVotes() :party1Votes(0), party2Votes(0), party3Votes(0) {}

int SectionVotes::votesForParty(Party partyType) const
{
	if (partyType == PARTY1)
	{
		return this->party1Votes;

	}
	else if (partyType == PARTY2)
	{
		return this->party2Votes;

	}
	else if (partyType == PARTY3)
	{
		return this->party3Votes;

	}

}

std::istream& operator>>(std::istream& in, SectionVotes& section)
{

	int votesForParty1;
	in >> votesForParty1;
	section.party1Votes = votesForParty1;
	int votesForParty2;
	in >> votesForParty2;
	section.party2Votes = votesForParty2;
	int votesForParty3;
	in >> votesForParty3;
	section.party3Votes = votesForParty3;

	return in;
}

std::ostream& operator<<(std::ostream& out, const SectionVotes& section)
{
	out << section.party1Votes << " ";
	out << section.party2Votes << " ";
	out << section.party3Votes << "\n";

	return out;

}
