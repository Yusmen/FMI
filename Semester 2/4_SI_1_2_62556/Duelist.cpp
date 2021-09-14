/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler VC
*/
#include "Duelist.hpp"


Duelist::Duelist(std::string)
{
	this->name = name;
}

void Duelist::display()
{
	std::cout << this->deck;
}

bool Duelist::saveDeck(std::string filename) const
{
	std::ofstream outFile(filename);

	if (outFile.is_open())
	{
		outFile << this->deck;
		return true;
	}
	return false;
}

bool Duelist::loadDeck(std::string filename)
{
	std::ifstream outFile(filename);

	if (outFile.is_open())
	{
		outFile >> (this->deck);
		return true;
	}
	return false;
}

Deck& Duelist::getDeck()
{
	return this->deck;
}

void Duelist::duel(Duelist& firstDuelist, Duelist& secondDuelist)
{
	int firstDuelistPoints = 0;
	int secondDuelistPoints = 0;
	if (firstDuelist.deck.totalCardsCount() == secondDuelist.deck.totalCardsCount())
	{
		firstDuelist.deck.shuffle();
		secondDuelist.deck.shuffle();
		for (int i = 0; i < firstDuelist.deck.totalCardsCount(); i++)
		{
			if (firstDuelist.deck.getCards()[i] > secondDuelist.deck.getCards()[i])
			{
				firstDuelistPoints++;
			}
			else if (firstDuelist.deck.getCards()[i] < secondDuelist.deck.getCards()[i])
			{
				secondDuelistPoints++;
			}
		}

	}
	else
	{
		std::cout << "Duelists must have equal number of cards!";
	}
	if (firstDuelistPoints > secondDuelistPoints)
	{
		std::cout << "Duelist" << firstDuelist.name << "wins." << "\n";
	}
	else if (secondDuelistPoints > firstDuelistPoints)
	{
		std::cout << "Duelist" << secondDuelist.name << "wins." << "\n";
	}

}
