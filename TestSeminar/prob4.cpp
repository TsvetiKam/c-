#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;
// 123
int removeNthDigit(int number, int n) {
	int divider = (int)pow(10, n);
	int remainder = number % (divider / 10);
	int leftSide = number / divider;

	return leftSide  * (divider / 10) + remainder;

}
int getLength(int n) {
	if (n < 10) {
		return 1;
	}

	return 1 + getLength(n / 10);
}
int main() {
	int first, second, length;
	cin >> first >> second;
	bool youCan = false;

	length = getLength(second);

	for (int i = 1; i < length; i++) {
		if (first == removeNthDigit(second, i)) {
			youCan = true;
		}
	}
	if (youCan) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
    return 0;
}

