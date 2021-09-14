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
#include "PendulumCard.hpp"
#include "PendulumCard.hpp"


PendulumCard::PendulumCard() :scale(0) {}

PendulumCard::PendulumCard(std::string name, std::string effect, int attackPoints, int defencePoints, int scale, CardType type)
{
	this->name = name;
	this->effect = effect;
	this->attackPoints = attackPoints;
	this->defencePoints = defencePoints;
	this->type = type;
	this->scale = scale;
}

PendulumCard& PendulumCard::operator=(const PendulumCard& rhs)
{
	this->name = rhs.name;
	this->effect = rhs.effect;
	this->attackPoints = rhs.attackPoints;
	this->defencePoints = rhs.defencePoints;
	this->type = rhs.type;
	this->scale = rhs.scale;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const PendulumCard& pendulumCard)
{
	
	//out << static_cast<MonsterCard&>(pendulumCard);
	//out << static_cast<MagicCard&>(pendulumCard);
	out << pendulumCard.name << "|";
	out << pendulumCard.effect << "|";
	out << pendulumCard.attackPoints << "|";
	out << pendulumCard.defencePoints << "|";
	out << pendulumCard.scale << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, PendulumCard& pemdulumCard)
{
	

	std::string name;
	getline(in, name, '|');
	pemdulumCard.name = name;

	std::string effect;
	getline(in, effect, '|');
	pemdulumCard.effect = effect;

	
	std::string attackPoints;
	getline(in, attackPoints, '|');	
	std::stringstream parser(attackPoints);
	int attackPointsToInt = 0;
	parser >> attackPointsToInt;
	pemdulumCard.attackPoints = attackPointsToInt;

	std::string defencePoints;
	getline(in, defencePoints, '|');
	std::stringstream parser1(defencePoints);
	int defencePointsToInt = 0;
	parser1 >> defencePointsToInt;
	pemdulumCard.defencePoints =defencePointsToInt;

	std::string type;
	getline(in, type, '|');
	if (type == "SPELL")
	{
		pemdulumCard.type = CardType::SPELL;
	}
	else if (type == "BUFF")
	{
		pemdulumCard.type = CardType::BUFF;
	}
	else if (type == "TRAP")
	{
		pemdulumCard.type = CardType::TRAP;
	}
	std::string scale;
	getline(in, scale, '|');
	std::stringstream parser3(scale);
	int scaleToInt = 0;
	parser3 >> scaleToInt;
	pemdulumCard.scale = scaleToInt;

	return in;
}
