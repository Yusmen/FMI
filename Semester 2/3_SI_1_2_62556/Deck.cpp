/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler VC
*/
#include "Deck.hpp"

Deck::Deck(std::string name)
{
	this->name = name;
}

Deck::Deck() :name("") {}

int Deck::magicCardsCount() const
{
	return this->magicCards.size();
}

int Deck::monsterCardsCount() const
{
	return this->monsterCards.size();
}

int Deck::pendulumCardsCount() const
{
	return this->pendulumCards.size();
}

void Deck::addMagicCard(MagicCard magicCard)
{
	this->magicCards.push_back(magicCard);
}

void Deck::addMonsterCard(MonsterCard monsterCard)
{
	this->monsterCards.push_back(monsterCard);
}

void Deck::addPendulumCard(PendulumCard pendulumCard)
{
	this->pendulumCards.push_back(pendulumCard);
}

void Deck::setMagicCard(int index, MagicCard magicCard)
{



	this->magicCards.insert(this->magicCards.begin() + index, magicCard);
}

void Deck::setMonsterCard(int index, MonsterCard monsterCard)
{
	this->monsterCards.insert(this->monsterCards.begin() + index, monsterCard);
}

void Deck::setPendulumCard(int index, PendulumCard pendulumCard)
{
	this->pendulumCards.insert(this->pendulumCards.begin() + index, pendulumCard);
}

void Deck::clearDeck()
{
	this->magicCards.clear();
	this->monsterCards.clear();
	this->pendulumCards.clear();
}

void Deck::setDeckname(std::string name)
{
	this->name = name;
}

std::string Deck::getDeckname() const
{
	std::string a = "erer";
	return this->name;
}


std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
	out << deck.name << "|" << deck.monsterCardsCount() << "|" << deck.magicCardsCount()
		<< "|" << deck.pendulumCardsCount() << "\n";

	for (int i = 0; i < (int)deck.monsterCards.size(); i++)
	{
		out << deck.monsterCards[i];
	}
	for (int i = 0; i < (int)deck.magicCards.size(); i++)
	{
		out << deck.magicCards[i];
	}
	for (int i = 0; i < (int)deck.pendulumCards.size(); i++)
	{
		out << deck.pendulumCards[i];
	}
	return out;
}

std::istream& operator>>(std::istream& in, Deck& deck)
{
	std::string deckname;
	getline(in, deckname, '|');
	deck.name = deckname;

	std::string monsterCards;
	getline(in, monsterCards, '|');
	int monsterCardsCount = stoi(monsterCards);

	std::string magicCards;
	getline(in, magicCards, '|');
	int magicCardsCount = stoi(magicCards);

	std::string pendulumCards;
	getline(in, pendulumCards, '|');
	int pendulumCardsCount = stoi(pendulumCards);
	deck.clearDeck();
	for (int i = 0; i < monsterCardsCount; i++)
	{
		MonsterCard monsterCard;
		//in >> deck.monsterCards[i];
		in >> monsterCard;
		deck.monsterCards.push_back(monsterCard);
	}
	for (int i = 0; i < magicCardsCount; i++)
	{
		MagicCard magicCard;
		in >> magicCard;
		deck.magicCards.push_back(magicCard);
	}
	for (int i = 0; i < pendulumCardsCount; i++)
	{
		PendulumCard pendulumCard;
		in >> pendulumCard;
		deck.pendulumCards.push_back(pendulumCard);
	}
	return in;

}
