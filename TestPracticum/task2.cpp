#include "stdafx.h"
#include <iostream>

using namespace std;
// Euclidean algorithm

int GCD(int a, int b) {
	if (a == b) {
		return a;
	}
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	if (a == 1 || b == 1) {
		return 1;
	}
	if (a > b) {
		a = a - b;
	}
	else {
		b = b - a;
	}
	GCD(a, b);
}

int main()
{
	int a, b;
	cin >> a >> b;

	a = abs(a);
	b = abs(b);
	
	int c = GCD(a, b);
	cout << c << endl;
    return 0;
}

