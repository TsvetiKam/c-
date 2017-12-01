#include "stdafx.h"
#include <iostream>

using namespace std;

bool lim(int a) {
	bool flag;
	if (a < 1 || a > 8) {
		flag = true
	}
	else {
		flag = false;
	}
	return flag;
}

void input(int* x, int* y, int* x1, int* y1) {
	cout << "x = ";
	cin >> *x;

	cout << "y = ";
	cin >> *y;

	cout << "x1 = ";
	cin >> *x1;

	cout << "y1 = ";
	cin >> *y1;
}
int main()
{
	int x, y, x1, y1;
	
	input(&x, &y, &x1, &y1);
	
	while (lim(x) || lim(y) || lim(x1) || lim(y1)) {
		cout << "Try again:" << endl;
		input(&x, &y, &x1, &y1);
	}


	// pawn
	if ((x == x1 && y + 1 == y1) || (x - 1 == x1 && y + 1 == y1) || (x + 1 == x1 && y + 1 == y1)) {
		cout << "pawn" << endl;
		cout << "Valid move" << endl;
	}
	else cout << "Invalid move" << endl;

	//rook

	if (x == x1 || y == y1) {
		cout << "Valid move" << endl;
	}
	else cout << "Invalid move" << endl;

	//bishop

	if (abs(x - x1) == abs(y - y1))
	{
		cout << "Valid move" << endl;
	}
	else cout << "Invalid move" << endl;

	
    return 0;
}

