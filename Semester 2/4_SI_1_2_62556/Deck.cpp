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
#include "Deck.hpp"

Deck::Deck(std::string name)
{
	this->name = name;
}

Deck::Deck() :name("") {}


//Deck::~Deck()
//{
//	for (auto card : cards)
//	{
//		delete card;
//	}
//}

Deck::Deck(const Deck& rhs)
{
	for (auto card : rhs.cards)
	{
		this->cards.push_back(card->clone());
	}
}

Deck& Deck::operator=(const Deck& rhs)
{
	if (this != &rhs)
	{
		for (auto card : cards)
		{
			delete card;
		}
		this->cards.clear();

		for (auto card : rhs.cards)
		{
			this->cards.push_back(card->clone());
		}
	}

	return *this;
}



int Deck::magicCardsCount() const
{
	int count = 0;
	for (int i = 0; i < (int)this->cards.size(); i++)
	{
		auto magicCardptr = dynamic_cast<MagicCard*>(this->cards[i]);
		auto pendulumCardptr = dynamic_cast<PendulumCard*>(this->cards[i]);
		if (magicCardptr && !pendulumCardptr)
		{
			count++;
		}
	}
	return count;
}

int Deck::monsterCardsCount() const
{
	int count = 0;
	for (int i = 0; i < (int)this->cards.size(); i++)
	{
		MonsterCard* monsterCardptr = dynamic_cast<MonsterCard*>(this->cards[i]);
		auto pendulumCardptr = dynamic_cast<PendulumCard*>(this->cards[i]);
		if (monsterCardptr && !pendulumCardptr)
		{
			count++;
		}
	}
	return count;
}

int Deck::pendulumCardsCount() const
{
	int count = 0;
	for (int i = 0; i < (int)this->cards.size(); i++)
	{
		PendulumCard* pendulumCardptr = dynamic_cast<PendulumCard*>(this->cards[i]);
		if (pendulumCardptr)
		{
			count++;
		}
	}
	return count;
}

int Deck::totalCardsCount() const
{
	return this->cards.size();
}

void Deck::addCard(Card* card)
{
	this->cards.push_back(card);
}

void Deck::setCard(int index, Card* card)
{
	PendulumCard* pendulumCardptr = dynamic_cast<PendulumCard*>(this->cards[index]);
	PendulumCard* pendulumCardptr1 = dynamic_cast<PendulumCard*>(card);
	if (pendulumCardptr && pendulumCardptr1)
	{
		this->cards[index] = card;
	}
	MagicCard* magicCardptr = dynamic_cast<MagicCard*>(this->cards[index]);
	MagicCard* magicCardptr1 = dynamic_cast<MagicCard*>(card);
	if (magicCardptr && magicCardptr1)
	{
		this->cards[index] = card;

	}
	MonsterCard* monsterCardptr = dynamic_cast<MonsterCard*>(this->cards[index]);
	MonsterCard* monsterCardptr1 = dynamic_cast<MonsterCard*>(card);
	if (monsterCardptr && monsterCardptr1)
	{
		this->cards[index] = card;

	}

}


void Deck::shuffle()
{


	std::random_shuffle(this->cards.begin(), this->cards.end());
}

void Deck::clearDeck()
{
	this->cards.clear();
}

void Deck::setDeckname(std::string name)
{
	this->name = name;
}

std::string Deck::getDeckname() const
{

	return this->name;
}

std::vector<Card*>& Deck::getCards()
{
	return this->cards;
}

int Deck::randomfunc(int j)
{
	return rand() % j;
}


std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
	out << deck.name << "|" << deck.totalCardsCount() << "|" << deck.monsterCardsCount() << "|" << deck.magicCardsCount()
		<< "|" << deck.pendulumCardsCount() << "\n";

	for (int i = 0; i < (int)deck.cards.size(); i++)
	{
		MagicCard* magicCardptr = dynamic_cast<MagicCard*>(deck.cards[i]);
		MonsterCard* monsterCardptr = dynamic_cast<MonsterCard*>(deck.cards[i]);
		PendulumCard* pendulumCardptr = dynamic_cast<PendulumCard*>(deck.cards[i]);
		if (magicCardptr && !pendulumCardptr)
		{
			out << *magicCardptr;
		}
		else if (monsterCardptr && !pendulumCardptr)
		{
			out << *monsterCardptr;
		}
		else if (pendulumCardptr)
		{
			out << *pendulumCardptr;
		}

	}
	return out;
}

std::istream& operator>>(std::istream& in, Deck& deck)
{
	std::string deckname;
	getline(in, deckname, '|');
	deck.name = deckname;

	std::string cards;
	getline(in, cards, '|');
	int totalCardsCount = stoi(cards);

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
		in >> monsterCard;
		deck.cards.push_back(new MonsterCard(monsterCard));
	}
	for (int i = 0; i < magicCardsCount; i++)
	{
		MagicCard magicCard;
		in >> magicCard;
		deck.cards.push_back(new MagicCard(magicCard));
	}
	for (int i = 0; i < pendulumCardsCount; i++)
	{
		PendulumCard pendulumCard;
		in >> pendulumCard;
		deck.cards.push_back(new PendulumCard(pendulumCard));
	}
	return in;

}
