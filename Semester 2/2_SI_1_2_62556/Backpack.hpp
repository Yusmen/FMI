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

#include "Materials.hpp"
#include<vector>
#include "Money.hpp"
template<typename T>
class Backpack;

template<>
class Backpack<Materials>
{
public:
	Backpack();
	bool isFull() const;
	bool isEmpty() const;
	void Clear();
	void Add(string, int);
	void Remove(string, int);
	int getSlots() const;
	void print();


private:
	Materials materials;
	int slots;
	const int max_slots = 16;


};

Backpack<Materials>::Backpack() :slots(0) {}

bool Backpack<Materials>::isFull() const
{
	if (this->materials.getClothQuantitty() != 0
		|| this->materials.getEssenceQuantitty() != 0
		|| this->materials.getHerbsQuantitty() != 0
		|| this->materials.getOresQuantitty() != 0)
	{
		return true;
	}
	return false;

}

bool Backpack<Materials>::isEmpty() const
{
	if (this->materials.getClothQuantitty() == 0
		|| this->materials.getEssenceQuantitty() == 0
		|| this->materials.getHerbsQuantitty() == 0
		|| this->materials.getOresQuantitty() == 0)
	{
		return true;
	}
	return false;
}

void Backpack<Materials>::Clear()
{
	this->materials.setClothQuantitty(0);
	this->materials.setHerbsQuantitty(0);
	this->materials.setOresQuantitty(0);
	this->materials.setEssenceQuantitty(0);
}

void Backpack<Materials>::Add(string type, int quantity)
{
	int tempSlots = 0;
	if (type == "essence")
	{
		if (quantity / 10 > quantity / 10.0)
		{
			tempSlots += quantity / 10 + 1;
		}
		else
		{
			tempSlots += quantity / 10;
		}
	}
	else if (type == "herbs" || type == "ores" || type == "cloth")
	{
		if (quantity / 20 > quantity / 20.0)
		{
			tempSlots += quantity / 20 + 1;
		}
		else
		{
			tempSlots += quantity / 20;
		}
	}
	if (tempSlots + this->slots > max_slots)
	{
		return;
	}
	this->slots += tempSlots;
}

void Backpack<Materials>::Remove(string type, int quantity)
{
	if (type == "essence")
	{
		if (quantity / 10 > quantity / 10.0)
		{
			this->slots -= quantity / 10 + 1;
		}
		else
		{
			this->slots -= quantity / 10;
		}
	}
	else if (type == "herbs" || type == "ores" || type == "cloth")
	{
		if (quantity / 20 > quantity / 20.0)
		{
			this->slots -= quantity / 20 + 1;
		}
		else
		{
			this->slots -= quantity / 20;
		}
	}
	if (this->slots < 0)
	{
		this->slots = 0;
	}
}

int Backpack<Materials>::getSlots() const
{
	return this->slots;
}

void Backpack<Materials>::print()
{
	cout << "Slots: " << endl;
	cout << "Materials: " << endl;
	this->materials.print();
}



template<>
class Backpack<Money>
{
public:
	Backpack();
	//void UpdateSlots();
	bool isFull() const;
	bool isEmpty() const;
	void Clear();
	void Add(int, int);
	void Remove(int, int);
	int getSlots() const;
	void print();


private:
	Money money;
	int slots;
	const int max_slots = 16;


};

Backpack<Money>::Backpack() :slots(0) {}

void Backpack<Money>::print()
{
	cout << "Slots: " << endl;
	cout << "Money: " << endl;
	this->money.print();
}


bool Backpack<Money>::isFull() const
{
	if (this->money.getMoney().first != 0 || this->money.getMoney().second != 0)
	{
		return true;
	}
	return false;

}

bool Backpack<Money>::isEmpty() const
{
	if (this->money.getMoney().first == 0 || this->money.getMoney().second == 0)
	{
		return true;
	}
	return false;
}

void Backpack<Money>::Clear()
{
	this->money.setMoney(0, 0);
}

void Backpack<Money>::Add(int gold, int silver)
{

	this->money.setMoney(gold, silver);
	this->money.UpdateMoney();
}

void Backpack<Money>::Remove(int gold, int silver)
{
	this->money.remove(gold, silver);
}

int Backpack<Money>::getSlots() const
{
	return this->slots;
}


