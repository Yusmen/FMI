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
#include "MagicCard.hpp"

MagicCard::MagicCard(std::string name, std::string effect, CardType type)
{
	this->name = name;
	this->effect = effect;
	this->type = type;

}

MagicCard::MagicCard() :type(CardType::Default) {}

MagicCard& MagicCard::operator=(const MagicCard& rhs)
{
	this->name = rhs.name;
	this->effect = rhs.effect;
	this->type = rhs.type;
	return *this;
}


void MagicCard::print()
{
	Card::print();
	std::cout << this->type<<"\n";
}

std::ostream& operator<<(std::ostream& out, const MagicCard& magicCard)
{
	out << magicCard.name << "|";
	out << magicCard.effect << "|";
	out << magicCard.type << "\n";

	return out;
}

std::istream& operator>>(std::istream& in, MagicCard& magicCard)
{
	std::string name;
	getline(in, name, '|');
	magicCard.name = name;

	std::string effect;
	getline(in, effect, '|');
	magicCard.effect = effect;

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
