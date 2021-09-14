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
#pragma once
class Date
{
public:
	Date();
	Date(const int, const int, const int);
	void print();
	void addDays(int);
	void removeDays(int);
	bool isLeapYear();
	int DaysToXmas();
	int DaysToEndOfYear();
	int DaysToEvent(Date);
	bool isLaterThen(Date);


private:

	int day;
	int month;
	int year;
	bool is31DayMonth(int);

};
