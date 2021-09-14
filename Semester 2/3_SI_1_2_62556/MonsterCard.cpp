#include "MonsterCard.hpp"

MonsterCard::MonsterCard(std::string name, std::string effect, int attackPoints, int defensePoints)
{
	this->name = name;
	this->effect = effect;
	this->attackPoints = attackPoints;
	this->defencePoints = defensePoints;

}

MonsterCard::MonsterCard() :attackPoints(0), defencePoints(0) {}

MonsterCard& MonsterCard::operator=(const MonsterCard& rhs)
{
	this->name = rhs.name;
	this->effect = rhs.effect;
	this->attackPoints = rhs.attackPoints;
	this->defencePoints = rhs.defencePoints;

	return *this;
}

void MonsterCard::print()
{
	Card::print();

	std::cout << this->attackPoints << " " << this->defencePoints;
}

std::ostream& operator<<(std::ostream& out, const MonsterCard& monsterCard)
{
	out << monsterCard.name << "|";
	out << monsterCard.effect << "|";
	out << monsterCard.attackPoints << "|";
	out << monsterCard.defencePoints << "\n";
	return out;
}

std::istream& operator>>(std::istream& in, MonsterCard& monsterCard)
{

	std::string name;
	getline(in, name, '|');
	monsterCard.name = name;

	std::string effect;
	getline(in, effect, '|');
	monsterCard.effect = effect;

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