#include "stdafx.h"
#include <iostream>

using namespace std;
int const N = 50;
bool magicSquare(int arr[][N], int n) {

	int sum = 0;
	bool magicSquare = false;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i][0];
	}

	int sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum2 += arr[i][j];
			sum3 += arr[j][i];
			if (i == j) {
				sum4 += arr[i][j];
			}
			if (i + j == n - 1) {
				sum5 += arr[i][j];
			}
		}
		if (sum == sum2 && sum == sum3 && sum == sum4 && sum == sum5) {
			magicSquare = true;
		}
			sum2 = 0;
			sum3 = 0;
	}
	return magicSquare;
}


int main()
{
	int n;
	int arr[N][N];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << magicSquare(arr, n) << endl;
    return 0;
}

