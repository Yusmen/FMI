/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 3
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int* Factorization(int numerator, int denumerator);
int* Calculate(int firstNumerator, int firstDenumerator, int secondNumerator, int secondDenumerator, char operation);
int main()
{
	char operation;
	int firstNumerator;
	int firstDenumerator;
	int secondDenumerator;
	int secondNumerator;
	cout << "Numerator: ";  cin >> firstNumerator;
	cout << "Denumerator: "; cin >> firstDenumerator;
	cout << "Operation: "; cin >> operation;
	cout << "Numerator: "; cin >> secondNumerator;
	cout << "Denumerator: "; cin >> secondDenumerator;
	int* arr = new int[2];
	arr = Calculate(firstNumerator, firstDenumerator, secondNumerator, secondDenumerator, operation);
	cout << *arr << " " << *(arr + 1);

}
int* Calculate(int firstNumerator, int firstDenumerator, int secondNumerator, int secondDenumerator, char operation)
{
	
	int resultNumerator = 0;
	int resultDenumerator = firstDenumerator * secondDenumerator;
	if (operation == '+')
	{
		resultNumerator = firstNumerator * secondDenumerator + secondNumerator * firstDenumerator;

	}
	else if (operation == '-')
	{
		resultNumerator = firstNumerator * secondDenumerator - secondNumerator * firstDenumerator;
	}
	else if (operation == '*')
	{
		resultNumerator = firstNumerator * secondNumerator;
	}
	else if (operation == '/')
	{
		resultNumerator = firstNumerator * secondDenumerator;
		resultDenumerator = secondNumerator * firstDenumerator;
	}

	return Factorization(resultNumerator, resultDenumerator);
}
int* Factorization(int numerator, int denumerator)
{
	int* arr = new int[2];
	while (numerator % 2 == 0 && denumerator % 2 == 0)
	{
		numerator = numerator / 2;
		denumerator = denumerator / 2;
	}
	int end = numerator;
	if (numerator == 0)
	{
		end = denumerator;
	}


	for (int i = 3; i <= end; i += 2)
	{
		while (numerator % i == 0 && denumerator % i == 0)
		{
			numerator = numerator / i;
			denumerator = denumerator / i;
		}
	}
	*arr = numerator;
	*(arr + 1) = denumerator;
	return arr;


}


