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
#include <iostream>
#include "Date.hpp"
using  namespace std;

int main()
{
	
	Date d1(31, 3, 2014);
	Date d;


	d.print();
	d1.print();
	
	//d1.print();
	//d1.addDays(1);
	//d1.addDays(1);
	//d1.removeDays(42);
	//d1.print();
	cout << d.isLaterThen(d1);
	//cout << d1.DaysToXmas();
}

