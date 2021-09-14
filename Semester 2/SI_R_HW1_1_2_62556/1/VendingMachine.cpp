#include "VendingMachine.hpp"


VendingMachine::VendingMachine() :income(0) {}



VendingMachine::VendingMachine(const VendingMachine& from)
{
	for (int i = 0; i < drinks_size; i++)
	{
		this->drinks[i] = from.drinks[i];
	}
	this->income = from.income;
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
	if (this != &from)
	{
		for (int i = 0; i < drinks_size; i++)
		{
			this->drinks[i] = from.drinks[i];
		}
		this->income = from.income;
	}


	return *this;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
	for (int i = 0; i < drinks_size; i++)
	{

		if (strcmp(this->drinks[i].get_name(), to_add.get_name()) == 0 &&
			this->drinks[i].get_calories() == to_add.get_calories()
			&& this->drinks[i].get_price() == to_add.get_price()
			&& this->drinks[i].get_quantity() == to_add.get_quantity())
		{

			return false;
		}
	}
	for (int i = 0; i < drinks_size; i++)
	{
		if (this->drinks[i].get_name()[0] == '\0'
			&& this->drinks[i].get_calories() == 0
			&& this->drinks[i].get_price() == 0
			&& this->drinks[i].get_quantity() == 0)
		{
			this->drinks[i] = to_add;
			break;

		}
	}
	return true;
}



int VendingMachine::buy_drink(const char* drink_name, const double money)
{
	for (int i = 0; i < drinks_size; i++)
	{
		if (strcmp(this->drinks[i].get_name(), drink_name) == 0 && money >= this->drinks[i].get_price())
		{
		
			Drink d;
			this->drinks[i] = d;
			this->income += money;
			return 0;
		}
		else if (strcmp(this->drinks[i].get_name(), drink_name) == 0 && money < this->drinks[i].get_price())
		{
			this->income += money;
			return 1;
		}

	}
	return 2;

}

double VendingMachine::get_income() const
{
	return this->income;
}

