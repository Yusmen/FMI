/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 2
* @compiler GCC
*
*/
#include <iostream>

using namespace std;

int main()
{
	int N;
	do
	{
		cin >> N;

	} while (N < 3 || N > 365);

	double arr[100];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	double profit = 0;


	for (int i = 0; i < N; i++)
	{
		if (arr[i + 1] > arr[i])
		{
			profit += arr[i + 1] - arr[i];

		}
		
	}

	cout << profit;

}






