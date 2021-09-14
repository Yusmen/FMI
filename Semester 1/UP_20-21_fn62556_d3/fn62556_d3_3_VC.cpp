
/**
*
* Solution to homework assignment 3
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
#include <vector>

using namespace std;
bool isMagicalSquare(double arr[10][10], int& n);
int main()
{
	int n;
	cin >> n;
	double arr[10][10];
	cout << isMagicalSquare(arr, n);

}

bool isMagicalSquare(double arr[10][10], int& n)
{
	vector<double> result;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			cin >> arr[i][j];
			if (arr[i][j] < 0 || arr[i][j]>100)
			{
				cout << -1;
				return 0;
			}
		}
	}
	double sumRow = 0;
	double sumCol = 0;
	double sumDiagonal = 0;
	int sumSecondDiagonal = 0;
	for (int i = 0; i < n; i++)
	{
		sumDiagonal += arr[i][i];
		sumSecondDiagonal += arr[i][n - 1 - i];
		for (int j = 0; j < n; j++)
		{
			sumRow += arr[i][j];
			sumCol += arr[j][i];
		}
		result.push_back(sumRow);
		result.push_back(sumCol);
		sumRow = 0;
		sumCol = 0;
	}
	result.push_back(sumDiagonal);
	result.push_back(sumSecondDiagonal);


	double element = result[0];
	for (int i = 1; i < result.size(); i++)
	{
		if (result[i] != element)
		{
			return false;
		}
	}
	return true;


}






