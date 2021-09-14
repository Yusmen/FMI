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
#include "Card.hpp"

Card::Card() :name(""), effect(""), rarity(0) {}


Card::Card(const std::string& name, const std::string& effect, const unsigned int& rarity)
	: name(name), effect(effect), rarity(rarity) {}




void Card::print()
{
	std::cout << this->name << " " << this->effect << " " << this->rarity;
}

bool operator<(const Card& lhs, const Card& rhs)
{
	return lhs.rarity < rhs.rarity;
}

bool operator>(const Card& lhs, const Card& rhs)
{
	return lhs.rarity > rhs.rarity;
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	out << card.name << "|";
	out << card.effect << "|";
	out << card.rarity << "|";
	return out;
}

std::istream& operator>>(std::istream& in, Card& card)
{
	std::string name;
	getline(in, name, '|');
	card.name = name;

	std::string effect;
	getline(in, effect, '|');
	card.effect = effect;

	std::string rarity;
	getline(in, rarity, '|');
	std::stringstream parser1(rarity);
	int rarityToInt = 0;
	parser1 >> rarityToInt;
	card.rarity = rarityToInt;

	return in;
}
