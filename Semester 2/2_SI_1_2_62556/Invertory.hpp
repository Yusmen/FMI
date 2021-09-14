
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
#include "Backpack.hpp"
#include "Equipment.hpp"
template<typename T>
class Invertory;

template<>
class Invertory<Backpack<Materials>>
{
public:
	Invertory();
	bool operator==(const Invertory<Backpack<Materials>>) const;
	bool operator!=(const Invertory<Backpack<Materials>>) const;
	void operator<<(const Invertory<Backpack<Materials>>);
	int getTotalNumberOfSlots() const;
	void Add(Backpack<Materials>);
	void Remove(int);



private:
	vector<Backpack<Materials>> backpacks;


};

Invertory<Backpack<Materials>>::Invertory() {}



bool Invertory<Backpack<Materials>>::operator==(const Invertory<Backpack<Materials>> invertory) const
{
	return (this->getTotalNumberOfSlots() == invertory.getTotalNumberOfSlots());
}

bool Invertory<Backpack<Materials>>::operator!=(const Invertory<Backpack<Materials>> invertory) const
{
	return (this->getTotalNumberOfSlots() != invertory.getTotalNumberOfSlots());
}

void Invertory<Backpack<Materials>>::operator<<(const Invertory<Backpack<Materials>> backapack)
{
	for (int i = 0; i < this->backpacks.size(); i++)
	{
		this->backpacks[i].print();
	}

}

int Invertory<Backpack<Materials>>::getTotalNumberOfSlots() const
{
	int sum = 0;
	for (int i = 0; i < this->backpacks.size(); i++)
	{
		sum += this->backpacks[i].getSlots();
	}
	return sum;

}

void Invertory<Backpack<Materials>>::Add(Backpack<Materials> backpack)
{
	this->backpacks.push_back(backpack);
}

void Invertory<Backpack<Materials>>::Remove(int index)
{

	this->backpacks.erase(this->backpacks.begin() + index);
}


template<>
class Invertory<Backpack<Money>>
{
public:
	Invertory();
	bool operator==(const Invertory<Backpack<Money>>) const;
	bool operator!=(const Invertory<Backpack<Money>>) const;
	void operator<<(const Invertory<Backpack<Money>>);
	int getTotalNumberOfSlots() const;
	void Add(Backpack<Money>);
	void Remove(int);



private:
	vector<Backpack<Money>> money;


};

Invertory<Backpack<Money>>::Invertory() {}



bool Invertory<Backpack<Money>>::operator==(const Invertory<Backpack<Money>> invertory) const
{
	return (this->getTotalNumberOfSlots() == invertory.getTotalNumberOfSlots());
}

bool Invertory<Backpack<Money>>::operator!=(const Invertory<Backpack<Money>> invertory) const
{
	return (this->getTotalNumberOfSlots() != invertory.getTotalNumberOfSlots());
}

void Invertory<Backpack<Money>>::operator<<(const Invertory<Backpack<Money>> backapack)
{
	for (int i = 0; i < this->money.size(); i++)
	{
		this->money[i].print();
	}

}

int Invertory<Backpack<Money>>::getTotalNumberOfSlots() const
{
	int sum = 0;
	for (int i = 0; i < this->money.size(); i++)
	{
		sum += this->money[i].getSlots();
	}
	return sum;

}

void Invertory<Backpack<Money>>::Add(Backpack<Money> money)
{
	this->money.push_back(money);
}

void Invertory<Backpack<Money>>::Remove(int index)
{

	this->money.erase(this->money.begin() + index);
}




template<>
class Invertory<Equipment<Weapon>>
{
public:
	Invertory();
	bool operator==(const Invertory<Equipment<Weapon>>) const;
	bool operator!=(const Invertory<Equipment<Weapon>>) const;
	void operator<<(const Invertory<Equipment<Weapon>>);
	int getTotalNumberOfSlots() const;
	void Add(Equipment<Weapon>);
	void Remove(int);



private:
	vector<Equipment<Weapon>> equipments;


};

Invertory<Equipment<Weapon>>::Invertory() {}



bool Invertory<Equipment<Weapon>>::operator==(const Invertory<Equipment<Weapon>> invertory) const
{
	return (this->getTotalNumberOfSlots() == invertory.getTotalNumberOfSlots());
}

bool Invertory<Equipment<Weapon>>::operator!=(const Invertory<Equipment<Weapon>> invertory) const
{
	return (this->getTotalNumberOfSlots() != invertory.getTotalNumberOfSlots());
}

void Invertory<Equipment<Weapon>>::operator<<(const Invertory<Equipment<Weapon>> equipment)
{
	for (int i = 0; i < this->equipments.size(); i++)
	{
		this->equipments[i].print();
	}

}

int Invertory<Equipment<Weapon>>::getTotalNumberOfSlots() const
{
	int sum = 0;
	for (int i = 0; i < this->equipments.size(); i++)
	{
		sum += this->equipments[i].getSlots();
	}
	return sum;

}

void Invertory<Equipment<Weapon>>::Add(Equipment<Weapon> weapon)
{
	this->equipments.push_back(weapon);
}

void Invertory<Equipment<Weapon>>::Remove(int index)
{

	this->equipments.erase(this->equipments.begin() + index);
}


template<>
class Invertory<Equipment<Armor>>
{
public:
	Invertory();
	bool operator==(const Invertory<Equipment<Armor>>) const;
	bool operator!=(const Invertory<Equipment<Armor>>) const;
	void operator<<(const Invertory<Equipment<Armor>>);
	int getTotalNumberOfSlots() const;
	void Add(Equipment<Armor>);
	void Remove(int);



private:
	vector<Equipment<Armor>> equipments;


};

Invertory<Equipment<Armor>>::Invertory() {}



bool Invertory<Equipment<Armor>>::operator==(const Invertory<Equipment<Armor>> invertory) const
{
	return (this->getTotalNumberOfSlots() == invertory.getTotalNumberOfSlots());
}

bool Invertory<Equipment<Armor>>::operator!=(const Invertory<Equipment<Armor>> invertory) const
{
	return (this->getTotalNumberOfSlots() != invertory.getTotalNumberOfSlots());
}

void Invertory<Equipment<Armor>>::operator<<(const Invertory<Equipment<Armor>> equipment)
{
	for (int i = 0; i < this->equipments.size(); i++)
	{
		this->equipments[i].print();
	}

}

int Invertory<Equipment<Armor>>::getTotalNumberOfSlots() const
{
	int sum = 0;
	for (int i = 0; i < this->equipments.size(); i++)
	{
		sum += this->equipments[i].getSlots();
	}
	return sum;

}

void Invertory<Equipment<Armor>>::Add(Equipment<Armor> armor)
{
	this->equipments.push_back(armor);
}

void Invertory<Equipment<Armor>>::Remove(int index)
{

	this->equipments.erase(this->equipments.begin() + index);
}

