/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 4
* @compiler GCC
*
*/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	
	int N;
	do
	{
		cin >> N;
	} while (N < 3 || N > 100);
	vector<int> numbers;

	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		numbers.push_back(number);
	}
	
	set<int> arr;

	for (size_t i = 0; i < numbers.size(); i++)
	{

		arr.insert(numbers[i]);

	}
	numbers.clear();
	copy(arr.begin(), arr.end(), back_inserter(numbers));

	int count = 0;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			for (int k = j + 1; k < numbers.size(); k++)
			{
				a = numbers[i];
				b = numbers[j];
				c = numbers[k];
				if (a + b + c == 0)
				{
					count++;

				}

			}
		}

	}
	cout << count;

}



