#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
	std::ifstream inFile(filename);

	if (inFile.is_open())
	{
		inFile >> *this;
	}
	else
	{
		std::cout << "File could not open!";
		return;
	}

}

int ElectionResultsDatabase::numberOfSections() const
{
	return this->sections.size();
}

int ElectionResultsDatabase::votesForParty(Party party) const
{
	int result = 0;
	for (int i = 0; i < this->sections.size(); i++)
	{
		result += this->sections[i].votesForParty(party);
	}
	return result;
}

Party ElectionResultsDatabase::winningParty() const
{
	int totalVotesForParty1 = votesForParty(PARTY1);
	int totalVotesForParty2 = votesForParty(PARTY2);
	int totalVotesForParty3 = votesForParty(PARTY3);



	if (totalVotesForParty1 == totalVotesForParty2
		&& totalVotesForParty1 > totalVotesForParty3)
	{
		return PARTY1;
	}
	else if (totalVotesForParty1 == totalVotesForParty3
		&& totalVotesForParty1 < totalVotesForParty2)
	{
		return PARTY1;
	}
	else if (totalVotesForParty2 == totalVotesForParty3
		&& totalVotesForParty1 < totalVotesForParty1)
	{
		return PARTY2;
	}
	int tempVotes = std::max({ totalVotesForParty1,totalVotesForParty2,totalVotesForParty3 });

	if (tempVotes == totalVotesForParty1)
	{

		return PARTY1;

	}
	else if (tempVotes == totalVotesForParty2)
	{

		return PARTY2;

	}
	else if (tempVotes == totalVotesForParty3)
	{

		return PARTY3;

	}

}

std::istream& operator>>(std::istream& in, ElectionResultsDatabase& database)
{

	SectionVotes s;

	while (in >> s)
	{
		database.sections.push_back(s);
	}
	return in;

}

std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& database)
{
	for (int i = 0; i < database.sections.size(); i++)
	{
		out << database.sections[i];
	}
	return out;
}
