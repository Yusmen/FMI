/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler VC
*/
#pragma once
#include "Weapon.hpp"
#include "Armor.hpp"



template<typename T>
class Equipment;

template<>
class Equipment<Weapon>
{
public:
	Equipment();
	int getSlots() const;
	bool isFull() const;
	bool isEmpty() const;
	void Clear();
	void Add(Weapon);
	void Remove(string);
	Weapon bestEquipment() const;
	double getWeaponsScores() const;
	bool operator==(const Equipment<Weapon>) const;
	bool operator!=(const Equipment<Weapon>) const;
	void print();

private:

	vector<Weapon> weapons;
	int slots;
	const int max_slots = 24;
};

Equipment<Weapon>::Equipment() :slots(0) {}


int Equipment<Weapon>::getSlots() const
{
	return this->slots;
}

bool Equipment<Weapon>::isFull() const
{
	if (this->weapons.empty())
	{
		return false;
	}
	return true;
}

bool Equipment<Weapon>::isEmpty() const
{
	if (this->weapons.empty())
	{
		return true;
	}
	return false;
}

void Equipment<Weapon>::Clear()
{
	this->weapons.clear();
	this->slots = 0;
}

void Equipment<Weapon>::Add(Weapon weapon)
{

	if (weapon.getType() == WeaponType::oneHanded)
	{
		if (this->slots + 1 > max_slots)
		{
			cout << "You cannot add this weapon.There are not enough slots for it!";
			return;
		}
		this->slots++;


	}
	else
	{
		if (this->slots + 2 > max_slots)
		{
			cout << "You cannot add this weapon.There are not enough slots for it!";
			return;
		}
		this->slots += 2;

	}


	this->weapons.push_back(weapon);

}

void Equipment<Weapon>::Remove(string kind)
{
	for (int i = 0; i < this->weapons.size(); i++)
	{
		if (this->weapons[i].getKind() == kind)
		{
			this->weapons.erase(weapons.begin() + i);
			i = 0;
		}
	}
}

Weapon Equipment<Weapon>::bestEquipment() const
{
	double maxScore = 0;
	int index = 0;
	for (int i = 0; i < this->weapons.size(); i++)
	{
		if (this->weapons[i].WeaponScore() > maxScore)
		{
			maxScore = this->weapons[i].WeaponScore();
			index = i;
		}
	}
	return this->weapons[index];
}

double Equipment<Weapon>::getWeaponsScores() const
{
	double result = 0;
	for (int i = 0; i < this->weapons.size(); i++)
	{
		result += this->weapons[i].WeaponScore();
	}
	return result;
}

bool Equipment<Weapon>::operator==(const Equipment<Weapon> weapon) const
{
	return (this->getWeaponsScores() == weapon.getWeaponsScores());
}

bool Equipment<Weapon>::operator!=(const Equipment<Weapon> weapon) const
{
	return (this->getWeaponsScores() != weapon.getWeaponsScores());
}

void Equipment<Weapon>::print()
{
	cout << "Slots: " << endl;
	cout << "Weapons: " << endl;
	for (int i = 0; i < this->weapons.size(); i++)
	{
		this->weapons[i].print();
	}

}





template<>
class Equipment<Armor>
{
public:
	Equipment();
	int getSlots() const;
	bool isFull() const;
	bool isEmpty() const;
	void Clear();
	void Add(Armor);
	void Remove(ArmorType);
	Armor bestEquipment() const;
	double getArmorsScores() const;
	bool operator==(const Equipment<Armor>) const;
	bool operator!=(const Equipment<Armor>) const;
	void print();

private:

	vector<Armor> armors;
	int slots;
	const int max_slots = 24;
};

Equipment<Armor>::Equipment() :slots(0) {}


int Equipment<Armor>::getSlots() const
{
	return this->slots;
}

bool Equipment<Armor>::isFull() const
{
	if (this->armors.empty())
	{
		return false;
	}
	return true;
}

bool Equipment<Armor>::isEmpty() const
{
	if (this->armors.empty())
	{
		return true;
	}
	return false;
}

void Equipment<Armor>::Clear()
{
	this->armors.clear();
	this->slots = 0;
}

void Equipment<Armor>::Add(Armor armor)
{


	if (this->slots + 1 > max_slots)
	{
		cout << "Not enough slots"<<endl;
		return;
	}
	this->slots++;
	this->armors.push_back(armor);

}

void Equipment<Armor>::Remove(ArmorType type)
{
	for (int i = 0; i < this->armors.size(); i++)
	{
		if (this->armors[i].getType() == type)
		{
			this->armors.erase(armors.begin() + i);
			i = 0;
		}
	}
}

Armor Equipment<Armor>::bestEquipment() const
{
	double maxScore = 0;
	int index = 0;
	for (int i = 0; i < this->armors.size(); i++)
	{
		if (this->armors[i].GearScore() > maxScore)
		{
			maxScore = this->armors[i].GearScore();
			index = i;
		}
	}
	return this->armors[index];
}

double Equipment<Armor>::getArmorsScores() const
{
	double result = 0;
	for (int i = 0; i < armors.size(); i++)
	{
		result += this->armors[i].GearScore();
	}
	return result;
}

bool Equipment<Armor>::operator==(const Equipment<Armor> armor) const
{
	return (this->getArmorsScores() == armor.getArmorsScores());
}

bool Equipment<Armor>::operator!=(const Equipment<Armor> armor) const
{
	return (this->getArmorsScores() != armor.getArmorsScores());
}

void Equipment<Armor>::print()
{
	cout << "Slots: " << endl;
	cout << "Weapons: " << endl;
	for (int i = 0; i < this->armors.size(); i++)
	{
		this->armors[i].print();
	}

}