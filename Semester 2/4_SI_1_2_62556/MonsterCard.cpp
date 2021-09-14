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
#include "MonsterCard.hpp"

MonsterCard::MonsterCard(const std::string& name, const std::string& effect, const unsigned int& rarity, const unsigned int& attackPoints, const unsigned int& defensePoints)
	:Card(name, effect, rarity), attackPoints(attackPoints), defencePoints(defensePoints) {}


MonsterCard::MonsterCard() : attackPoints(0), defencePoints(0) {}

MonsterCard& MonsterCard::operator=(const MonsterCard& rhs)
{
	this->name = rhs.name;
	this->effect = rhs.effect;
	this->attackPoints = rhs.attackPoints;
	this->defencePoints = rhs.defencePoints;

	return *this;
}

Card* MonsterCard::clone() const
{
	return new MonsterCard(*this);
}

void MonsterCard::print()
{
	Card::print();

	std::cout << this->attackPoints << " " << this->defencePoints;
}

std::ostream& operator<<(std::ostream& out, const MonsterCard& monsterCard)
{
	out << static_cast<const Card&>(monsterCard);
	out << monsterCard.attackPoints << "|";
	out << monsterCard.defencePoints << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, MonsterCard& monsterCard)
{

	in >> static_cast<Card&>(monsterCard);

	std::string attackPoints;
	getline(in, attackPoints, '|');
	std::stringstream parser(attackPoints);
	int attackPointsToInt = 0;
	parser >> attackPointsToInt;
	monsterCard.attackPoints = attackPointsToInt;

	std::string defencePoints;
	getline(in, defencePoints, '|');
	std::stringstream parser1(defencePoints);
	int defencePointsToInt = 0;
	parser1 >> defencePointsToInt;
	monsterCard.defencePoints = defencePointsToInt;

	return in;
}