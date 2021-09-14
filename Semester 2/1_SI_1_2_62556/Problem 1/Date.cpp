/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler VC
*/
#include "Date.hpp"
#include<iostream>
using namespace std;

Date::Date() :day(1), month(1), year(2000) {}
Date::Date(const int day, const int month, const int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
bool Date::is31DayMonth(int month)
{
	if (month == 1 || month == 3 || month == 4 || month == 6
		|| month == 7 || month == 8 || month == 10 || month == 12)
	{
		return true;
	}
	return false;
}
void Date::print()
{

	cout << ((day < 10) ? day : day) << "." << ((month < 10) ? month : month) << "." << year << endl;;
}

void Date::addDays(int n)
{
	while (n <= 0)
	{
		cout << "Days cannot be zero or negative!";
		cin >> n;
	}

	if (is31DayMonth(month))
	{

		if (day + n > 31 && month == 12)
		{
			month += 1;
			day = (day + n) - 31;
			year += 1;
		}
		else if (day + n > 31)
		{
			month += 1;
			day = (day + n) - 31;
		}
		else
		{
			day += n;
		}

	}
	else if (month == 2)
	{
		if (this->isLeapYear())
		{
			if (day + n > 29)
			{
				month += 1;
				day = (day + n) - 29;
			}
			else
			{
				day += n;
			}
		}
		else
		{
			if (day + n > 28)
			{
				month += 1;
				day = (day + n) - 28;
			}
			else
			{
				day += n;
			}

		}

	}
	else
	{
		if (day + n > 30)
		{
			month += 1;
			day = (day + n) - 28;
		}
		else
		{
			day += n;
		}
	}

}

void Date::removeDays(int n)
{
	while (n <= 0)
	{
		cout << "Days cannot be zero or negative!";
		cin >> n;
	}
	if (this->day - n > 0)
	{
		day -= n;
	}
	else
	{
		this->month -= 1;
		if (is31DayMonth(month))
		{
			if (month == 12)
			{
				year--;

			}
			day = (day - n) + 31;
		}
		else if (month == 2)
		{
			if (this->isLeapYear())
			{
				day = (day - n) + 29;
			}
			else
			{
				day = (day - n) + 28;

			}

		}
		else
		{
			day = (day - n) + 30;
		}
	}




}

bool Date::isLeapYear()
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}

}

int Date::DaysToXmas()
{
	int resultDays = 0;
	int currentMonth = 1;
	while (true)
	{
		if (currentMonth == this->month)
		{
			resultDays += this->day;
			break;
		}
		if (is31DayMonth(currentMonth))
		{
			resultDays += 31;
		}
		else if (currentMonth == 2)
		{
			if (this->isLeapYear())
			{
				resultDays += 29;
			}
			else
			{
				resultDays += 28;
			}
		}
		else
		{
			resultDays += 30;
		}

		currentMonth++;
	}
	if (this->isLeapYear())
	{
		resultDays = 360 - resultDays;
	}
	else
	{
		resultDays = 359 - resultDays;
	}
	return resultDays;


}
int Date::DaysToEndOfYear()
{
	int resultDays = 0;
	int currentMonth = 1;
	while (true)
	{
		if (currentMonth == this->month)
		{
			resultDays += this->day;
			break;
		}
		if (is31DayMonth(currentMonth))
		{
			resultDays += 31;
		}
		else if (currentMonth == 2)
		{
			if (this->isLeapYear())
			{
				resultDays += 29;
			}
			else
			{
				resultDays += 28;
			}
		}
		else
		{
			resultDays += 30;
		}

		currentMonth++;
	}
	if (this->isLeapYear())
	{
		resultDays = 366 - resultDays;
	}
	else
	{
		resultDays = 365 - resultDays;
	}
	return resultDays;
}

int Date::DaysToEvent(Date d)
{
	int eventDay = d.day;
	int eventMonth = d.month;
	int eventYear = d.year;
	int resultDays = day;
	int currentMonth = month;
	while (true)
	{
		if (currentMonth == eventMonth)
		{
			resultDays += eventDay;
			break;
		}
		if (is31DayMonth(currentMonth))
		{
			resultDays += 31;
		}
		else if (currentMonth == 2)
		{
			if (this->isLeapYear())
			{
				resultDays += 29;
			}
			else
			{
				resultDays += 28;
			}
		}
		else
		{
			resultDays += 30;
		}

		currentMonth++;
	}

	return resultDays;
}

bool Date::isLaterThen(Date d)
{
	if (d.year > year)
	{
		return true;

	}
	else if (d.year == this->year)
	{
		if (d.month > this->month)
		{
			return true;
		}
		else if (d.day > this->day)
		{
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}

}
