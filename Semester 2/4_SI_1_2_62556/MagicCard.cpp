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
#include "MagicCard.hpp"

MagicCard::MagicCard(const std::string& name, const std::string& effect, const unsigned int& rarity, CardType type)
	:Card(name, effect, rarity), type(type) {}

MagicCard::MagicCard() : type(CardType::Default) {}

MagicCard& MagicCard::operator=(const MagicCard& rhs)
{
	this->name = rhs.name;
	this->effect = rhs.effect;
	this->rarity = rhs.rarity;
	this->type = rhs.type;	
	return *this;
}


Card* MagicCard::clone() const
{
	return new MagicCard(*this);
}

void MagicCard::print()
{
	Card::print();
	std::cout << this->type << "\n";
}

std::ostream& operator<<(std::ostream& out, const MagicCard& magicCard)
{

	out << static_cast<const Card&>(magicCard);
	out << magicCard.type << "\n";

	return out;
}

std::istream& operator>>(std::istream& in, MagicCard& magicCard)
{
	in >> static_cast<Card&>(magicCard);

	std::string type;
	getline(in, type, '|');
	if (type == "SPELL")
	{
		magicCard.type = CardType::SPELL;
	}
	else if (type == "BUFF")
	{
		magicCard.type = CardType::BUFF;
	}
	else if (type == "TRAP")
	{
		magicCard.type = CardType::TRAP;
	}
	return in;





}
