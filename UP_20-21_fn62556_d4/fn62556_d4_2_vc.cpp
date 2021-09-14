/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 2
* @compiler VC
*
*/

#include <iostream>

using namespace std;
void output(int arr[4][4]);
int findPossibleMoves(int mat[4][4], int p, int q)
{

    int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    int count = 0;

    for (int i = 0; i < 8; i++) 
    {

        int x = p + X[i];
        int y = q + Y[i];
        if (x >= 0 && y >= 0 && x < 4 && y < 4 && mat[x][y] == 0)
            count++;
    }

    
    return count;
}
int main()
{
    int mat[4][4];

    int p = 2, q = 2;

    cout << findPossibleMoves(mat, p, q);
}
void output(int arr[4][4])
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
}
