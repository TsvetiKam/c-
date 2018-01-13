#include "stdafx.h"
#include <iostream>

using namespace std;

void sequence(int n) {

	if (n == 1) {
		cout << 1;
		return;
	}
	sequence(n - 1);
	cout << n;
	sequence(n - 1);

	return;
}

int main()
{
	int n;
	cin >> n;

	sequence(n);
    return 0;
}

