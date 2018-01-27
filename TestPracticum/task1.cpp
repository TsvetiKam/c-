#include "stdafx.h"
#include <iostream>
#include <cstring>

// Maic Square

using namespace std;

int const N = 10;

int getSum(int arr[][N], int n) {
	int Sum = 0;
	for (int i = 0; i < n; i++) {
		Sum += arr[0][i];
	}
	return Sum;
}

void getArr(int arr[][N], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

bool isMagicSquare(int arr[][N], int n) {
	bool isSq = true;
	int Sum = getSum(arr, n);

	int sumCol, sumRow, sumD1 = 0, sumD2 = 0;
	for (int i = 0; i < n; i++) {
		sumCol = 0;
		sumRow = 0;
		for (int j = 0; j < n; j++) {
			sumCol += arr[j][i];
			sumRow += arr[i][j];
		}
		if (Sum != sumCol || Sum != sumRow) {
			isSq = false;
		}
		sumD1 += arr[i][i];
		sumD2 += arr[i][n - i - 1];
	}
	if (Sum != sumD1 || Sum != sumD2) {
		isSq = false;
	}
	return isSq;

}
int main()
{
	int arr[N][N];
	int n;
	cin >> n; 
	getArr(arr, n);
	
	if (isMagicSquare(arr, n))
		cout << "Yes" << endl;
	else cout << "No" << endl;


    return 0;
}

