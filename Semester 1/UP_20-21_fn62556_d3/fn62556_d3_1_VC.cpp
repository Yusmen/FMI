
/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler VC
*
*/


#include <iostream>
using namespace std;
int strlen(char arr[150]);
void sort(char arr[150]);
int IsProperArray(char arr[150]);
int main()
{

	char arr[150];
	cin.getline(arr, 150);
	cout << IsProperArray(arr);

	

}
int IsProperArray(char arr[150])
{
	int n = strlen(arr);
	int count = 0;
	int currentCount = 0;
	int i = 0;

	sort(arr);
	while (true)
	{
		if (arr[i] == arr[i + 1])
		{
			count++;
		}
		else
		{
			if (count != 0)
			{
				break;

			}
		}

		i++;
	}

	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			currentCount++;

		}
		else
		{
			if (currentCount != count && flag == 1)
			{
				return 0;
			}

			if (currentCount != count)
			{
				flag = 1;
			}
			currentCount = 0;
		}


	}
	return 1;

}

void sort(char arr[150])
{
	for (int i = 0; i < strlen(arr); i++)
	{
		for (int j = i + 1; j < strlen(arr); j++)
		{
			if (arr[i] > arr[j])
			{
				char temp;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

	}
}
int strlen(char arr[150])
{
	int i = 0;
	int br = 0;
	while (arr[i] != '\0')
	{
		br++;
		i++;

	}
	return br;
}

