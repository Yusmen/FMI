/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler GCC
*
*/


#include <iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	int n;
	do
	{
		cin >> n;
	} while (n < 3 || n>100);


	int arr[100];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n / 2; i++)
	{
		if (abs(arr[i] - arr[i + 1]) != abs(arr[n - 1 - i] - arr[n - 2 - i]))
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;


}


